#pragma once
#include "imgui.h"

class UIState
{
public:
    UIState() {};

    // components
    bool demo_window{false};
    bool about_window{false};
    bool system_info_window{true};

    // fonts
    ImFont *fontRegular = nullptr;
    ImFont *fontMono = nullptr;
};
