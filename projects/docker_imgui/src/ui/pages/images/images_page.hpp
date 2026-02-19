#pragma once
#include "imgui.h"

class ImagesPage
{
public:
    ImagesPage();

    void draw();

private:
    ImGuiTableFlags table_flags;
    //     bool is_visible{false};
};