#include <stdio.h>
#include <iostream>
#include "imgui.h"
#include "misc/cpp/imgui_stdlib.h"
#include "images_page.hpp"
#include "ui/icons/fa4.hpp"
#include "ui/utils/humanize.hpp"

ImagesPage::ImagesPage(UIState *state, docker::DockerClient *docker_client) : state(state)
{

    frame = new ui::ImagesFrame(state, docker_client);
};

void ImagesPage::draw()
{

    if (!state->images_window)
    {
        return;
    }

    // ImGui::Begin(ICON_FA_ODNOKLASSNIKI " "
    ImGui::Begin(frame->getMeta().title);

    frame->draw();

    ImGui::End();
};
