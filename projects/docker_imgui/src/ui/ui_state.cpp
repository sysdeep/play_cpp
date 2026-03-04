#include "ui_state.hpp"
#include <algorithm>

UIState::UIState() {};

void UIState::show_container(const std::string &id)
{
    auto it = std::find(container_modals.begin(), container_modals.end(), id);
    if (it == container_modals.end())
    {
        container_modals.push_back(id);
    }
    else
    {
        container_modals.erase(it);
    }
};

void UIState::show_image(const std::string &id)
{
    auto it = std::find(image_modals.begin(), image_modals.end(), id);
    if (it == image_modals.end())
    {
        image_modals.push_back(id);
    }
    else
    {
        image_modals.erase(it);
    }
};