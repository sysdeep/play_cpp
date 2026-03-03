#pragma once

namespace ui
{

    class Drawable
    {
    public:
        virtual ~Drawable() {};

        virtual void draw() = 0;
    };
}