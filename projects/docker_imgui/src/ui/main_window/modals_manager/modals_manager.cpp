#include "modals_manager.hpp"
#include <algorithm>
#include <iostream>

using namespace ui;

// ----------------------------------------------------------------------------
ModalsManager::ModalsManager(UIState *uiState, docker::DockerClient *docker_client) : uiState(uiState),
                                                                                      images_provider(uiState),
                                                                                      images_storage(images_provider, docker_client),
                                                                                      container_provider(uiState),
                                                                                      containers_storage(container_provider, docker_client)
{
    // auto images_provider = new ImagesModalProvider(uiState);
    // std::cout << "images ids size" << images_provider->getIds().size() << std::endl;
    // auto mm = images_provider->makeModal("foo");

    // auto containers_provider = new ContainersModalProvider(uiState);

    // auto ms = new ModalsStorage(images_provider);
    // ms->draw();
    // auto ms = new ModalsStorage(containers_provider);
    // auto ms = new ModalsStorage<ImageWindow *>(images_provider);
    // images_storage = new ModalsStorage<ImageWindow *>(images_provider);
}

void ModalsManager::draw()
{

    images_storage.draw();
    containers_storage.draw();
    // // add modal
    // for (auto image_id : uiState->image_modals)
    // {
    //     auto it = this->image_modals.find(image_id);
    //     if (it == image_modals.end())
    //     {
    //         // create modal
    //         this->image_modals[image_id] = new ImageWindow(image_id);
    //     }
    // }

    // // remove modal
    // for (const auto mpair : this->image_modals)
    // {

    //     auto vit = std::find(uiState->image_modals.begin(), uiState->image_modals.end(), mpair.first);
    //     if (vit == uiState->image_modals.end())
    //     {
    //         this->image_modals.erase(mpair.first);
    //     }
    // }

    // // draw modals
    // for (const auto mpair : this->image_modals)
    // {
    //     mpair.second->draw();
    // }
}