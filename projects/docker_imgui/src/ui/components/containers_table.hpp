#pragma once
#include <vector>
#include "imgui.h"
#include "models/container_list_model.hpp"

namespace ui
{

    class ContainersTableHandler
    {
    public:
        virtual ~ContainersTableHandler() = default; // make it abstract

        virtual void on_container_toggled(const std::string &id) = 0;
    };

    class ContainersTable
    {
    public:
        explicit ContainersTable(ContainersTableHandler *handler);
        void draw(std::vector<docker::ContainerListModel> &containers);

    private:
        ImGuiTableFlags table_flags = ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg;
        ImGuiTableColumnFlags column_name_flags = ImGuiTableColumnFlags_DefaultSort |
                                                  ImGuiTableColumnFlags_WidthStretch;

        ContainersTableHandler *handler;
    };
}
