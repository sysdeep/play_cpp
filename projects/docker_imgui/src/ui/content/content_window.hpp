#pragma once
#include "ui/core/drawable.hpp"
#include "content_frame.hpp"

namespace ui
{
    class ContentWindow : public Drawable
    {
    public:
        explicit ContentWindow();
        void draw() override;

        void registerPage(int pageId, Frame *frame);

    private:
        ContentFrame *contentFrame;
    };
}