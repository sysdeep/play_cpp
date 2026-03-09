#pragma once
#include <string>
#include <vector>
#include <memory>
#include "ui/ui_state.hpp"
#include "ui/windows/image_window.hpp"
#include "ui/windows/container_window.hpp"
#include "ui/windows/window_handler.hpp"
#include "docker_client.hpp"

namespace ui
{
    template <class WindowT>
    class ModalProvider
    {

    public:
        using Ptr = std::unique_ptr<WindowT>;
        explicit ModalProvider(UIState *ui) noexcept : uiState(ui) {}
        virtual ~ModalProvider() = default;

        virtual std::vector<std::string> getIds() const = 0;
        virtual Ptr makeModal(const std::string &id, docker::DockerClient *docker_client) = 0;

    protected:
        UIState *uiState;
    };

    //--------------
    class ImagesModalProvider final : public ModalProvider<ImageWindow>, public WindowHandler
    {
    public:
        using Base = ModalProvider<ImageWindow>;
        explicit ImagesModalProvider(UIState *uiState) : Base(uiState) {};

        std::vector<std::string> getIds() const override
        {
            return uiState->image_modals;
        }

        Ptr makeModal(const std::string &id, docker::DockerClient *docker_client) override
        {
            return std::make_unique<ImageWindow>(id, docker_client, this);
        }

        void do_close(const std::string &id) override
        {
            uiState->show_image(id);
        }
    };

    //-------
    class ContainersModalProvider final : public ModalProvider<ContainerWindow>, public WindowHandler
    {
    public:
        using Base = ModalProvider<ContainerWindow>;
        explicit ContainersModalProvider(UIState *uiState) : Base(uiState) {};

        std::vector<std::string> getIds() const override
        {
            return uiState->container_modals;
        }

        Ptr makeModal(const std::string &id, docker::DockerClient *docker_client) override
        {
            return std::make_unique<ContainerWindow>(id, docker_client, this);
        }

        void do_close(const std::string &id) override
        {
            uiState->show_container(id);
        }
    };
}