#pragma once
#include <vector>
#include <chrono>
#include <future>
#include "ui/pages/drawable_page.hpp"
#include "ui/ui_state.hpp"
#include "docker_client.hpp"
#include "models/container_list_model.hpp"
#include "ui/frames/containers/containers_frame.hpp"

namespace ui
{
    class ContainersPage : public DrawablePage
    {
    public:
        explicit ContainersPage(UIState *uiState, docker::DockerClient *docker_client);

        void draw() override;

    private:
        // components
        UIState *uiState;

        ContainersFrame *frame;
    };
}