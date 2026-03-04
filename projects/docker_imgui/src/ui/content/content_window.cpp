#include "imgui.h"
#include "content_window.hpp"

using namespace ui;

ContentWindow::ContentWindow()
{

    contentFrame = new ContentFrame();
};

void ContentWindow::draw()
{
    ImGuiViewport *viewport = ImGui::GetMainViewport();
    // ImVec2 window_pos = ImVec2(viewport->WorkPos.x, viewport->WorkPos.y + viewport->WorkSize.y);

    // ImGui::SetNextWindowPos(window_pos, ImGuiCond_Always);
    // ImVec2(0.0f, 1.0f)
    // ); // Use pivot for bottom alignment

    // 1. Устанавливаем позицию и размер на весь экран
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    // ImGui::SetNextWindowViewport(viewport->ID);

    // 2. Настраиваем прозрачность фона (опционально)
    // ImGui::SetNextWindowBgAlpha(1.0f); // 0.0f для полной прозрачности

    // 3. Флаги: убираем оформление и запрещаем перемещение на передний план
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDecoration |
                                    ImGuiWindowFlags_NoMove |
                                    ImGuiWindowFlags_NoResize |
                                    ImGuiWindowFlags_NoSavedSettings |
                                    ImGuiWindowFlags_NoBringToFrontOnFocus;

    ImGui::Begin("Content", nullptr, window_flags);
    contentFrame->draw();
    ImGui::End();
};

void ContentWindow::registerPage(Frame *frame)
{
    if (contentFrame == nullptr)
        return;

    contentFrame->registerPage(frame);
}