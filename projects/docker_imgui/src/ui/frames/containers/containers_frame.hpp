#pragma once
#include <vector>
#include <chrono>
#include <future>
#include "ui/pages/drawable_page.hpp"
#include "ui/ui_state.hpp"
#include "docker_client.hpp"
#include "models/container_list_model.hpp"
#include "ui/frames/frame.hpp"
#include "ui/icons/icons.hpp"
#include "ui/components/containers_table.hpp"

namespace ui
{
    class ContainersFrame : public Frame, public ContainersTableHandler
    {
    public:
        explicit ContainersFrame(UIState *uiState, docker::DockerClient *docker_client);
        static constexpr const char *title = ICON_CONTAINER " Containers";

        void draw() override;
        FrameMeta getMeta() override;

        // ContainersTableHandler interface ---------------
        void on_container_toggled(const std::string &id) override;

    private:
        // components
        UIState *uiState;
        docker::DockerClient *docker_client;

        // data
        std::vector<docker::ContainerListModel> containers;
        ImGuiTableFlags table_flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;
        ImGuiTableColumnFlags column_name_flags = ImGuiTableColumnFlags_DefaultSort |
                                                  ImGuiTableColumnFlags_WidthStretch;

        bool show_all = false;

        // methods
        void process_draw();

        // async update
        std::chrono::microseconds update_timeout; // ms
        std::chrono::system_clock::time_point last_update;
        std::vector<std::future<std::vector<docker::ContainerListModel>>> futures;
        void start_update_task();
        void process_update();

        // components
        ContainersTable containers_table;
    };
}