#pragma once
#include <string>
#include "window.hpp"
#include "ui/core/async_fetcher.hpp"
#include "models/container_model.hpp"
#include "docker_client.hpp"

namespace ui
{
    class ContainerWindow : public Window
    {
    public:
        ContainerWindow(std::string id, docker::DockerClient *docker_client);
        ~ContainerWindow()
        {
            delete (fetcher);
        }
        void draw() override;

    private:
        std::string id;
        docker::DockerClient *docker_client;

        AsyncFetcher<docker::ContainerModel> *fetcher;

        docker::ContainerModel fetch();

        // draw
        void drawStatus(const docker::ContainerModel &model);
        void drawConfig(const docker::ContainerModel &model);
        void drawNetworks(const docker::ContainerModel &model);
        void drawVolumes(const docker::ContainerModel &model);
    };
}