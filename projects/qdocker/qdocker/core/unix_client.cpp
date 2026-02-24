#include "unix_client.hpp"
#include <QDebug>

UnixClient::UnixClient(const QString &socketPath, QObject *parent)
    : QObject(parent),
      m_socketPath(socketPath)
{
    // Таймер будет использоваться для автоматического повторного подключения
    m_reconnectTimer = new QTimer(this);
    m_reconnectTimer->setInterval(3000);            // 3 сек.
    m_reconnectTimer->setSingleShot(true);
    connect(m_reconnectTimer, &QTimer::timeout,
            this, &UnixClient::tryReconnect);
}

UnixClient::~UnixClient()
{
    if (m_socket) {
        m_socket->abort();   // разорвать соединение без ожидания
        m_socket->deleteLater();
    }
}

/* ------------------------------------------------------------------ */
/*  public API                                                          */
/* ------------------------------------------------------------------ */

void UnixClient::start()
{
    if (m_started) return;
    m_started = true;

    // Создаём сокет **в этом же потоке**, где будет работать событие
    m_socket = new QLocalSocket(this);

    // Подключаем сигналы сокета к локальным слотам
    connect(m_socket, &QLocalSocket::connected,
            this, &UnixClient::onConnected);
    connect(m_socket, &QLocalSocket::disconnected,
            this, &UnixClient::onDisconnected);
    connect(m_socket, &QLocalSocket::readyRead,
            this, &UnixClient::onReadyRead);
    connect(m_socket, QOverload<QLocalSocket::LocalSocketError>::of(&QLocalSocket::errorOccurred),
            this, &UnixClient::onErrorOccurred);

    // Попытка первого подключения
    tryReconnect();
}

void UnixClient::sendMessage(const QByteArray &msg)
{
    if (!m_socket || m_socket->state() != QLocalSocket::ConnectedState) {
        emit errorOccurred(tr("Socket is not connected"));
        return;
    }
    // Простой протокол – строка с символом '\n' в конце
    QByteArray data = msg;
    if (!data.endsWith('\n'))
        data.append('\n');

    qint64 written = m_socket->write(data);
    if (written == -1)
        emit errorOccurred(tr("Failed to write to socket"));
}

void UnixClient::sendRaw(const QByteArray &data)
{
    qint64 written = m_socket->write(data);
    if (written == -1)
        emit errorOccurred(tr("Failed to write to socket: %1")
                           .arg(m_socket->errorString()));
}

void UnixClient::requestJson(const QString &resourcePath)
{
    if (!m_socket || m_socket->state() != QLocalSocket::ConnectedState) {
        emit errorOccurred(tr("Socket is not connected"));
        return;
    }

    /* Формируем минимальный HTTP‑запрос */
    QByteArray request;
    request.append("GET " + resourcePath.toUtf8() + " HTTP/1.1\r\n");
    request.append("Host: localhost\r\n");
    request.append("Accept: application/json\r\n");
    request.append("Connection: close\r\n");
    request.append("\r\n");

    /* Сбрасываем буфер и флаги, потому что получим новый ответ */
    m_rxBuffer.clear();
    m_headerParsed = false;
    m_contentLength = -1;
    m_headerEndPos   = -1;

    sendRaw(request);
}

/* ------------------------------------------------------------------ */
/*  slots – работа с сокетом                                            */
/* ------------------------------------------------------------------ */

void UnixClient::onConnected()
{
    qDebug() << "[UnixClient] connected to" << m_socketPath;
    emit connected();
}

void UnixClient::onDisconnected()
{
    qDebug() << "[UnixClient] disconnected";
    emit disconnected();

    // Попробуем переподключиться через несколько секунд
    if (!m_reconnectTimer->isActive())
        m_reconnectTimer->start();
}

void UnixClient::onReadyRead()
{
    while (m_socket->canReadLine()) {
        QByteArray line = m_socket->readLine().trimmed(); // без '\n'
        QString txt = QString::fromUtf8(line);
        qDebug() << "[UnixClient] received:" << txt;
        emit messageReceived(txt);
    }
}

void UnixClient::onErrorOccurred(QLocalSocket::LocalSocketError socketError)
{
    Q_UNUSED(socketError);
    QString err = m_socket->errorString();
    qDebug() << "[UnixClient] error:" << err;
    emit errorOccurred(err);
}

/* ------------------------------------------------------------------ */
/*  reconnect logic                                                    */
/* ------------------------------------------------------------------ */

void UnixClient::tryReconnect()
{
    if (!m_socket) return;
    if (m_socket->state() == QLocalSocket::ConnectedState) return;

    qDebug() << "[UnixClient] trying to connect to" << m_socketPath;
    m_socket->connectToServer(m_socketPath);

    // Если соединение не установилось в течение 2 сек – считаем ошибкой
    if (!m_socket->waitForConnected(2000)) {
        qWarning() << "[UnixClient] connect timeout:" << m_socket->errorString();
        // Повторим попытку
        m_reconnectTimer->start();
    }
}
