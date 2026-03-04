#include <iostream>
#include "containers_page.hpp"
#include "imgui.h"
#include "ui/icons/fa4.hpp"
#include "ui/utils/humanize.hpp"

using namespace ui;

ContainersPage::ContainersPage(UIState *uiState, docker::DockerClient *docker_client) : uiState(uiState)
{

    frame = new ContainersFrame(uiState, docker_client);
}

void ContainersPage::draw()
{
    if (!uiState->containers_window)
        return;

    ImGui::Begin(frame->getMeta().title);
    frame->draw();
    ImGui::End();
}
