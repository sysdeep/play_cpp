#include "./scene.hpp"
#include "application/application_ctx.hpp"
#include "imgui.h"
#include "ui/core/graph_item.hpp"
#include "ui/units/dsensor/dsensor_proto.hpp"
#include "ui/units/dsensor/dsensor_view.hpp"

using namespace UI;

Scene::Scene(ApplicationCtx *ctx) : ctx(ctx) {

    auto dsensor_view = new DSensorView();
    this->dsensor_proto = new DSensorProto(dsensor_view);
    this->addItem(dsensor_view);

    auto model = ctx->project->get_node("main_sensor");
    this->dsensor_proto->set_model(model);
    // this->dsensor_model = new LOGIC::DSensor("scene_sensor");
    // this->dsensor_proto->set_model(this->dsensor_model);
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
    if (ImGui::Begin("DockSpace", nullptr, windowFlags)) {
        // ImGui::PopStyleVar();
        ImDrawList *draw_list_g = ImGui::GetWindowDrawList();

        for (GraphItem *item : graph_items) {
            item->draw(draw_list_g);
        }

        const ImVec2 p = ImGui::GetCursorScreenPos();

        {
            ImGui::Begin("dsensor model controller");

            if (ImGui::Button("enable")) {
                auto model = ctx->project->get_node("main_sensor");

                model->set_attr_value(1, 1);
            }
            ImGui::SameLine();
            if (ImGui::Button("disable")) {
                auto model = ctx->project->get_node("main_sensor");

                model->set_attr_value(1, 0);
            }
            ImGui::End();
        }
        ImGui::End();
    }
}

void Scene::addItem(GraphItem *item) { this->graph_items.push_back(item); }
