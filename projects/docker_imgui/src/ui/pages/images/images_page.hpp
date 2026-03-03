#pragma once
#include "imgui.h"
#include "docker_client.hpp"
#include "models/image_list_model.hpp"
#include "ui/ui_state.hpp"
#include "ui/pages/drawable_page.hpp"
#include <chrono>
#include <future>

class ImagesPage : public DrawablePage
{
public:
    ImagesPage(UIState *state, docker::DockerClient *docker_client);

    void draw() override;

    void process_draw();

private:
    ImGuiTableFlags table_flags;
    //     bool is_visible{false};
    ImGuiTableColumnFlags column_name_flags = ImGuiTableColumnFlags_DefaultSort |
                                              ImGuiTableColumnFlags_WidthStretch;

    UIState *state;
    docker::DockerClient *docker_client;

    // main data model
    std::vector<docker::ImageListModel> images;

    // filter
    std::string filterStr;

    // async update
    std::chrono::microseconds update_timeout; // ms
    std::chrono::system_clock::time_point last_update;
    std::vector<std::future<std::vector<docker::ImageListModel>>> futures;
    void start_update_task();
    void process_update();
};