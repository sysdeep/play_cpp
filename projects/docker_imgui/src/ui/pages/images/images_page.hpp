#pragma once
#include "imgui.h"
#include "docker_client.hpp"
#include "models/image_list_model.hpp"
#include "ui/ui_state.hpp"
#include "ui/pages/drawable_page.hpp"
#include "ui/frames/images/images_frame.hpp"
#include <chrono>
#include <future>

class ImagesPage : public DrawablePage
{
public:
    ImagesPage(UIState *state, docker::DockerClient *docker_client);

    void draw() override;

    void process_draw();

private:
    UIState *state;
    ui::ImagesFrame *frame;
};