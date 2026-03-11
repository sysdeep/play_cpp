#pragma once
#include <string>
#include <vector>
#include "window.hpp"
#include <iostream>
#include "window_handler.hpp"
#include "docker_client.hpp"
#include "models/image_model.hpp"
#include "models/image_history_model.hpp"
#include "ui/core/async_fetcher.hpp"

namespace ui
{
    class ImageWindow : public Window
    {
    public:
        ImageWindow(std::string id, docker::DockerClient *docker_client, WindowHandler *window_handler);
        ~ImageWindow()
        {
            delete (fetcher);
            delete (history_fetcher);
        };
        void draw() override;

    private:
        std::string id;
        docker::DockerClient *docker_client;
        WindowHandler *window_handler;

        bool is_running = true;

        // image data fetcher
        AsyncFetcher<docker::ImageModel> *fetcher;
        AsyncFetcher<std::vector<docker::ImageHistoryModel>> *history_fetcher;

        // draw
        void draw_details(docker::ImageModel &payload);
        void draw_config(docker::ImageModel &payload);
        void draw_history(const std::vector<docker::ImageHistoryModel> &payload);
    };
}