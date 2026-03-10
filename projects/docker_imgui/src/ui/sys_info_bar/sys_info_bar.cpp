#include "imgui.h"
#include "sys_info_bar.hpp"
#include <chrono>

using namespace ui;

SysInfoBar::SysInfoBar(docker::DockerClient *docker_client) : docker_client(docker_client)
{

    fetcher = new AsyncFetcher<docker::SystemInfo>([=]()
                                                   {
                                                       //
                                                       return this->docker_client->system->info();
                                                       //
                                                   },
                                                   std::chrono::milliseconds(10000));

    // start
    fetcher->start();
}

void SysInfoBar::draw()
{

    auto payload = fetcher->tick();

    ImGuiViewport *viewport = ImGui::GetMainViewport();

    auto size = ImVec2(viewport->WorkSize.x, viewport->WorkSize.y * 0.1f);
    auto pos = ImVec2(viewport->WorkPos.x, viewport->WorkPos.y + viewport->WorkSize.y * 0.9f);

    // 1. Устанавливаем позицию и размер на весь экран
    // ImGui::SetNextWindowPos(viewport->WorkPos);
    // ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowPos(pos);
    ImGui::SetNextWindowSize(size);

    // 3. Флаги: убираем оформление и запрещаем перемещение на передний план
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDecoration |
                                    ImGuiWindowFlags_NoMove |
                                    ImGuiWindowFlags_NoResize |
                                    ImGuiWindowFlags_NoSavedSettings |
                                    ImGuiWindowFlags_NoBringToFrontOnFocus;

    auto io = &ImGui::GetIO();
    ImGui::Begin("Sys", nullptr, window_flags);

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io->Framerate, io->Framerate);
    ImGui::Text("Version %s", payload.ServerVersion.c_str());

    ImGui::End();
}