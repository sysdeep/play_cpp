#include <iostream>
#include "containers_frame.hpp"
#include "imgui.h"
#include "ui/icons/icons.hpp"
#include "ui/utils/humanize.hpp"

using namespace ui;

ContainersFrame::ContainersFrame(UIState *uiState,
                                 docker::DockerClient *docker_client) : uiState(uiState),
                                                                        docker_client(docker_client),
                                                                        containers_table(this)
{

    // new async update
    last_update = std::chrono::system_clock::now();

    // start
    this->start_update_task();
}

FrameMeta ContainersFrame::getMeta()
{
    return FrameMeta{ContainersFrame::title};
}

void ContainersFrame::draw()
{
    if (!uiState->containers_window)
        return;

    this->process_update();
    this->process_draw();
}

void ContainersFrame::process_draw()
{

    int containers_count = this->containers.size();

    ImGui::Text("total: %d", containers_count);
    ImGui::Text("futures: %ld", this->futures.size());

    // commands -------------------------------------------
    if (ImGui::Button(ICON_REFRESH " Обновить"))
    {
        this->start_update_task();
    }

    ImGui::Checkbox("All?", &this->show_all);

    // table ----------------------------------------------
    containers_table.draw(this->containers);
}

void ContainersFrame::process_update()
{
    // запуск фонового процесса
    // auto now = std::chrono::system_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - this->last_update);
    // if (elapsed > update_timeout)
    // {

    //     this->start_update_task();
    //     this->last_update = now;
    // }

    // обработка футур
    if (!futures.empty())
    {

        for (auto it = futures.begin(); it != futures.end();)
        {

            if (it->valid())
            {
                auto future_status = it->wait_for(std::chrono::seconds(0));
                if (future_status == std::future_status::ready)
                {
                    std::cout << "future status - ready, update containers and erase" << std::endl;
                    this->containers = it->get();
                    // remove element from vector
                    futures.erase(it);
                }
                else
                {
                    ++it;
                }
            }
            else
            {
                ++it;
            }
        }
    }
}

void ContainersFrame::start_update_task()
{
    std::cout << "start update containers async" << std::endl;
    auto task_future = std::async(std::launch::async, [this]()
                                  {
                                      //   auto info = this->docker_client->system->info();
                                      //   std::cout << info.ServerVersion << std::endl;
                                      auto containers = this->docker_client->containers->get_all(this->show_all);
                                      std::cout << "got containers: " << containers.size() << std::endl;

                                      //   std::this_thread::sleep_for(std::chrono::milliseconds(8000)); // Имитация долгой работы
                                      //   return 42;
                                      return containers;
                                      //
                                  });
    futures.push_back(std::move(task_future));
}

// ContainersTableHandler interface -------------------------------------------
void ContainersFrame::on_container_toggled(const std::string &id)
{
    uiState->toggle_container(id);
}