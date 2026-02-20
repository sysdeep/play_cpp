#pragma once
#include "ui/ui_state.hpp"
#include "ui/pages/drawable_page.hpp"
#include "docker_client.hpp"
#include "models/system_info.hpp"
#include <thread>
#include <atomic>
#include <condition_variable>
#include <chrono>
#include <future>
#include <vector>
#include <deque>

class SystemInfoPage : public DrawablePage
{
public:
    SystemInfoPage(UIState *state, DockerClient *docker_client);

    void draw() override;

private:
    UIState *state;
    DockerClient *docker_client;

    void process_draw();

    // main data model
    SystemInfo system_info{};

    // async update
    std::chrono::system_clock::time_point last_update;
    std::vector<std::future<SystemInfo>> futures;
    void process_update();
};
