#pragma once
#include <string>
#include "window.hpp"
#include <iostream>

namespace ui
{
    class ImageWindow : public Window
    {
    public:
        ImageWindow(std::string id);
        ~ImageWindow()
        {
            std::cout << "image window deleted" << std::endl;
        };
        void draw() override;

    private:
        std::string id;
    };
}