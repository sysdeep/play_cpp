#include "system_info_page.hpp"
#include "imgui.h"
#include <iostream>

SystemInfoPage::SystemInfoPage(UIState *state, DockerClient *docker_client) : state{state}, docker_client{docker_client}
{
    period_ = std::chrono::seconds(1);
    stopFlag_ = false;
    //
    system_info = docker_client->system->info();

    //
    thread_model = std::make_shared<SystemInfoDataModel>();

    start();
}

void SystemInfoPage::draw()
{
    if (!state->system_info_window)
        return;

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

        std::cout << "update" << std::endl;
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