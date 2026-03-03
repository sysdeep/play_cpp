#pragma once
#include "ui/core/drawable.hpp"

namespace ui
{
    class Frame : public Drawable
    {
    public:
        virtual ~Frame() {};

        // virtual void draw() = 0;
    };
}