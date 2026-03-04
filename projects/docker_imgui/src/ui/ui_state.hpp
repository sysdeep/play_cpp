#pragma once
#include <string>
#include <vector>
#include "imgui.h"

class UIState
{
public:
    UIState();

    // components -------------------------------------------------------------

    // demo с примерами использования
    bool demo_window{false};

    // окно с примером и с рейтом
    bool example_window{false};

    // окно about
    bool about_window{false};

    bool system_info_window{true};
    bool images_window{true};
    bool containers_window{true};

    // fonts
    ImFont *fontRegular = nullptr;
    ImFont *fontMono = nullptr;

    // open modals
    void show_container(const std::string &id);
    std::vector<std::string> container_modals;

    void show_image(const std::string &id);
    std::vector<std::string> image_modals;
};
