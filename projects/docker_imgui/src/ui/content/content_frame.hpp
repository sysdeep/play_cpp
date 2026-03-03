#pragma once
#include <vector>
#include <map>
#include "ui/core/drawable.hpp"
#include "ui/frames/frame.hpp"

namespace ui
{
    class ContentFrame : public Drawable
    {
    public:
        explicit ContentFrame();
        void draw() override;

        void registerPage(int pageId, Frame *frame);

    private:
        std::map<int, Frame *> pages;
    };
}