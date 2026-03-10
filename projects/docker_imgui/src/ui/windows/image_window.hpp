#pragma once
#include <string>
#include "window.hpp"
#include <iostream>
#include "window_handler.hpp"
#include "docker_client.hpp"
#include "models/image_model.hpp"
#include "ui/core/async_fetcher.hpp"

namespace ui
{
    class ImageWindow : public Window
    {
    public:
        ImageWindow(std::string id, docker::DockerClient *docker_client, WindowHandler *window_handler);
        ~ImageWindow()
        {
            std::cout << "image window deleted" << std::endl;
        };
        void draw() override;

    private:
        std::string id;
        docker::DockerClient *docker_client;
        WindowHandler *window_handler;

        bool is_running = true;

        AsyncFetcher<docker::ImageModel> *fetcher;

        // draw
        void draw_details(docker::ImageModel &payload);
        void draw_config(docker::ImageModel &payload);
    };
}