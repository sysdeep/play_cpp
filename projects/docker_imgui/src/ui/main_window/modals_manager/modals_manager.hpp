#pragma once
#include <map>
#include <string>
#include "ui/core/drawable.hpp"
#include "ui/ui_state.hpp"
#include "ui/windows/image_window.hpp"
#include "ui/windows/container_window.hpp"
#include "modals_storage.hpp"
#include "modal_provider.hpp"
#include "docker_client.hpp"

namespace ui
{

    class ModalsManager : public Drawable
    {
    public:
        ModalsManager(UIState *uiState, docker::DockerClient *docker_client);

        void draw() override;

    private:
        UIState *uiState;

        // images
        ImagesModalProvider images_provider;
        ModalsStorage<ImageWindow> images_storage;

        // containers
        ContainersModalProvider container_provider;
        ModalsStorage<ContainerWindow> containers_storage;
    };
}