#pragma once
#include "ui/ui_state.hpp"

class MainMenu
{
public:
    MainMenu(UIState *state);
    void draw();

private:
    UIState *state;
};
