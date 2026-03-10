#pragma once
#include "ui/core/drawable.hpp"
#include "ui/core/async_fetcher.hpp"
#include "models/system_info.hpp"
#include "docker_client.hpp"

namespace ui
{

    class SysInfoBar : public Drawable
    {
    public:
        SysInfoBar(docker::DockerClient *docker_client);

        void draw() override;

    private:
        docker::DockerClient *docker_client;
        AsyncFetcher<docker::SystemInfo> *fetcher;
    };
}