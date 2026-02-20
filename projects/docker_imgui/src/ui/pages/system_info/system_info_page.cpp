#include "system_info_page.hpp"
#include "imgui.h"
#include <iostream>
#include <future>

int calculateValue()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Имитация долгой работы
    return 42;
}

SystemInfoPage::SystemInfoPage(UIState *state, DockerClient *docker_client) : state{state}, docker_client{docker_client}
{
    period_ = std::chrono::seconds(1);
    stopFlag_ = false;
    //
    system_info = docker_client->system->info();

    //
    thread_model = std::make_shared<SystemInfoDataModel>();

    last_update = std::chrono::system_clock::now();

    start();

    // update_result = std::async(std::launch::async, calculateValue);
}

void SystemInfoPage::draw()
{
    if (!state->system_info_window)
        return;

    // async update
    auto now = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->last_update);
    if (elapsed.count() > 1000)
    {
        std::cout << "start update async" << std::endl;
        this->last_update = now;
        // update_result = std::async(std::launch::async, calculateValue);
        update_result = std::async(std::launch::async, [this]()
                                   {
                                       std::this_thread::sleep_for(std::chrono::milliseconds(800)); // Имитация долгой работы
                                       return 42;
                                       //
                                   });
    }

    if (update_result.valid())
    {
        auto future_status = update_result.wait_for(std::chrono::seconds(0));
        if (future_status == std::future_status::ready)
        {
            auto aaa = update_result.get();
            std::cout << "update result: " << aaa << std::endl;
        }
    }
    // async update

    auto sys = thread_model->snapshot();

    ImGui::Begin("System info");
    // ImGui::Begin("Another Window",
    //          &show_another_window); // Pass a pointer to our bool variable (the
    //                                 // window will have a closing button that will
    //                                 // clear the bool when clicked)
    ImGui::Text("Docker ImGui example");

    ImGuiTableFlags table_flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;

    if (ImGui::BeginTable("system_info_main_stats", 2, table_flags))
    {
        // Display headers
        {
            ImGui::TableSetupColumn("param");
            ImGui::TableSetupColumn("value");
            ImGui::TableHeadersRow();
        }

        // containers
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("Containers");

        ImGui::TableSetColumnIndex(1);
        // ImGui::Text("%d", system_info.Containers);
        ImGui::Text("%d", sys.payload.Containers);

        // ContainersRunning
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("ContainersRunning");

        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d", sys.payload.ContainersRunning);

        // ContainersPaused
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("ContainersPaused");

        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d", sys.payload.ContainersPaused);

        // ContainersStopped
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("ContainersStopped");

        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d", sys.payload.ContainersStopped);

        // Images
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0);
        ImGui::Text("Images");

        ImGui::TableSetColumnIndex(1);
        ImGui::Text("%d", sys.payload.Images);
    }
    ImGui::EndTable();

    ImGui::End();
}

// if (ImGui::Button("Закрыть"))
//     this->state->about_window = false;

// ImGui::End();
// }

void SystemInfoPage::run()
{
    while (!stopFlag_.load(std::memory_order_relaxed))
    {
        // ---------- 1. Обновляем модель ----------
        // В реальном проекте здесь будет запрос к БД, REST‑API, расчёты и т.д.
        // std::ostringstream ss;
        // ss << "value_" << dist(rng);
        // model_->addOrUpdate("key", ss.str());

        // std::cout << "update" << std::endl;
        auto sys_info = docker_client->system->info();
        thread_model->addOrUpdate(sys_info);

        // ---------- 2. Ожидание следующего цикла ----------
        std::unique_lock<std::mutex> lk(mtx_);
        // cv_.wait_for разбивает ожидание на небольшие интервалы,
        // позволяя быстро отреагировать на stopFlag.
        cv_.wait_for(lk, period_, [this]
                     { return stopFlag_.load(); });
    }
}

void SystemInfoPage::start()
{
    if (worker_.joinable())
        throw std::logic_error("BackgroundUpdater already running");

    stopFlag_ = false;
    worker_ = std::thread(&SystemInfoPage::run, this);
}
void SystemInfoPage::stop()
{
    stopFlag_.store(true, std::memory_order_relaxed);
    cv_.notify_one(); // разбудить, если поток «заснул» долго
    if (worker_.joinable())
        worker_.join();
}

void SystemInfoPage::run_update()
{

    auto sys_info = docker_client->system->info();

    std::lock_guard<std::mutex> lock(update_mtx);
    // update shared data
}