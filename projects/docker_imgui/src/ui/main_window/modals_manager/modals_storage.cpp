#include "modals_storage.hpp"
#include <algorithm>
#include <iostream>

using namespace ui;

template <class T>
ModalsStorage<T>::ModalsStorage(ModalProvider<T> &provider, docker::DockerClient *docker_client) : provider(provider),
                                                                                                   docker_client(docker_client) {}

template <typename T>
void ModalsStorage<T>::draw()
{

    auto ids = provider.getIds();

    // add modal if
    for (auto &image_id : ids)
    {
        auto it = modals.find(image_id);
        if (it == modals.end())
        {
            modals[image_id] = provider.makeModal(image_id, docker_client);
        }
    }

    // remove modal if
    std::vector<std::string> need_remove;
    for (const auto &mpair : modals)
    {

        auto vit = std::find(ids.begin(), ids.end(), mpair.first);
        if (vit == ids.end())
        {
            need_remove.push_back(mpair.first);
        }
    }

    for (auto const &id : need_remove)
    {
        modals.erase(id);
    }

    // draw modals
    for (const auto &mpair : modals)
    {
        mpair.second->draw();
    }
}

// Явные инстанциации
template class ui::ModalsStorage<ImageWindow>;
template class ui::ModalsStorage<ContainerWindow>;