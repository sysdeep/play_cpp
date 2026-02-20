#pragma once
#include "ui/ui_state.hpp"
#include "ui/pages/drawable_page.hpp"
#include "docker_client.hpp"
#include "models/system_info.hpp"
#include <thread>
#include <atomic>
#include <condition_variable>
#include <chrono>
#include <future>

class SystemInfoDataModel
{
public:
    // Данные, которые мы будем периодически обновлять.
    // В реальном проекте сюда могут попасть любые структуры.
    struct Record
    {
        std::chrono::system_clock::time_point ts; // время создания/обновления
        SystemInfo payload;                       // произвольные данные
    };

    SystemInfoDataModel() = default;
    ~SystemInfoDataModel() = default;

    // Запрет копирования/перемещения – модель управляется единственной
    // инстанцией, которую делят между потоками через shared_ptr.
    SystemInfoDataModel(const SystemInfoDataModel &) = delete;
    SystemInfoDataModel &operator=(const SystemInfoDataModel &) = delete;

    /** Добавить/обновить запись. Потокобезопасно. */
    void addOrUpdate(const SystemInfo &payload)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        auto now = std::chrono::system_clock::now();
        storage_ = Record{now, payload};
    }

    /** Считать копию текущего состояния. */
    Record snapshot() const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return Record{storage_.ts, storage_.payload};
    }

private:
    mutable std::mutex mutex_; // защищает весь контейнер
    Record storage_;
};

class SystemInfoPage : public DrawablePage
{
public:
    SystemInfoPage(UIState *state, DockerClient *docker_client);
    ~SystemInfoPage()
    {
        stop(); // гарантируем корректный захлоп в деструкторе
    }

    void draw() override;

    void start();
    void stop();

private:
    UIState *state;
    DockerClient *docker_client;

    SystemInfo system_info;

    // updater
    void run();
    std::thread worker_;
    std::chrono::milliseconds period_;

    std::atomic<bool> stopFlag_;

    // Применяется лишь для условной переменной – не нужна в модели.
    std::mutex mtx_;
    std::condition_variable cv_;

    std::shared_ptr<SystemInfoDataModel> thread_model;

    // async update
    std::chrono::system_clock::time_point last_update;
    void run_update();
    std::mutex update_mtx;
    std::future<int> update_result;
};
