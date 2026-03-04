#include "imgui.h"
#include "content_window.hpp"

using namespace ui;

ContentWindow::ContentWindow()
{

    contentFrame = new ContentFrame();
};

void ContentWindow::draw()
{
    ImGui::Begin("Content");
    contentFrame->draw();
    ImGui::End();
};

void ContentWindow::registerPage(Frame *frame)
{
    if (contentFrame == nullptr)
        return;

    contentFrame->registerPage(frame);
}