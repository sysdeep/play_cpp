#pragma once
#include <string>
#include "window.hpp"

namespace ui
{
    class ContainerWindow : public Window
    {
    public:
        ContainerWindow(std::string id);
        void draw() override;

    private:
        std::string id;
    };
}