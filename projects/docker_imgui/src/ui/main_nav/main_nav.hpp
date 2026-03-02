#pragma once
#include "ui/pages/drawable_page.hpp"
#include "ui/ui_state.hpp"

namespace ui
{
    class MainNav : public DrawablePage
    {
    public:
        explicit MainNav(UIState *state);

        void draw() override;

    private:
        UIState *uiState;
    };
}