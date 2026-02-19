#pragma once
#include "ui/ui_state.hpp"
#include "ui/pages/drawable_page.hpp"

class AboutPage : public DrawablePage
{
public:
    AboutPage(UIState *state);

    void draw() override;

private:
    UIState *state;
};