#pragma once
#include <map>
#include <string>
#include "ui/core/drawable.hpp"
#include "ui/ui_state.hpp"
#include "ui/windows/image_window.hpp"
#include "ui/windows/container_window.hpp"
#include "modal_provider.hpp"

namespace ui
{

    template <class WindowT>
    class ModalsStorage final : public Drawable
    {
    public:
        using Ptr = std::unique_ptr<WindowT>;

        ModalsStorage(ModalProvider<WindowT> &provider, docker::DockerClient *docker_client);
        void draw() override;

    private:
        ModalProvider<WindowT> &provider;

        std::map<std::string, Ptr> modals;

        docker::DockerClient *docker_client;
    };

}