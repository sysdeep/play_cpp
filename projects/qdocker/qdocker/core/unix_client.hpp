#pragma once

#include <QObject>
#include <QLocalSocket>
#include <QThread>
#include <QTimer>

class UnixClient : public QObject
{
    Q_OBJECT
public:
    explicit UnixClient(const QString &socketPath,
                        QObject *parent = nullptr);
    ~UnixClient() override;

    /** Запуск работы клиента (вызывается из GUI‑потока). */
    void start();

    /** Делает запрос к серверу. */
    Q_INVOKABLE void sendMessage(const QByteArray &msg);
    Q_INVOKABLE void requestJson(const QString &resourcePath);

signals:
    /** Информирует GUI, что пришло новое сообщение. */
    void messageReceived(const QString &msg);

    /** Информирует GUI о статусе соединения. */
    void connected();
    void disconnected();
    void errorOccurred(const QString &errorString);

private slots:
    void onConnected();
    void onDisconnected();
    void onReadyRead();
    void onErrorOccurred(QLocalSocket::LocalSocketError socketError);
    void tryReconnect();            // попытка переподключения

private:
    QString      m_socketPath;
    QLocalSocket *m_socket = nullptr;
    QTimer       *m_reconnectTimer = nullptr;
    bool         m_started = false;

    void sendRaw(const QByteArray &data);

    /* ---------- буфер и парсер HTTP‑ответа ---------- */
        QByteArray   m_rxBuffer;                // всё полученное от сервера
        bool         m_headerParsed = false;    // уже нашли \r\n\r\n ?
        int          m_contentLength = -1;      // из заголовка Content‑Length
        int          m_headerEndPos = -1;       // позиция конца заголовков

};

