#pragma once
#include <string>
#include "window.hpp"

namespace ui
{
    class ImageWindow : public Window
    {
    public:
        ImageWindow(std::string id);
        void draw() override;

    private:
        std::string id;
    };
}