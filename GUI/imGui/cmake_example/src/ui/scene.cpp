#include "./scene.hpp"
#include "imgui.h"
#include "ui/core/graph_item.hpp"
#include "ui/units/dsensor/dsensor_view.hpp"
#include "ui/units/dsensor/dsensor_vm.hpp"

using namespace UI;

Scene::Scene() {

    auto dsensor_vm = new DSensorVM();
    dsensor_vm->state = false;
    auto dsensor_view = new DSensorView(dsensor_vm);

    this->addItem(dsensor_view);
}

void Scene::draw() {
    const ImGuiViewport *viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->Pos);
    ImGui::SetNextWindowSize(viewport->Size);
    ImGuiWindowFlags windowFlags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoTitleBar |
                                   ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
                                   ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBringToFrontOnFocus |
                                   ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse;

    // Render main dock space
    if (ImGui::Begin("ImHexDockSpace", nullptr, windowFlags)) {
        // ImGui::PopStyleVar();
        ImDrawList *draw_list_g = ImGui::GetWindowDrawList();

        for (GraphItem *item : graph_items) {
            item->draw(draw_list_g);
        }

        const ImVec2 p = ImGui::GetCursorScreenPos();
        ImGui::End();
    }
}

void Scene::addItem(GraphItem *item) { this->graph_items.push_back(item); }
