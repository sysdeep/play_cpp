#pragma once
#include "ui/core/drawable.hpp"

namespace ui
{
    struct FrameMeta
    {
        const char *title;
    };

    class Frame : public Drawable
    {
    public:
        virtual ~Frame() {};

        // virtual void draw() = 0;
        virtual FrameMeta getMeta() = 0;
    };
}