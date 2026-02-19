#include "about_page.hpp"
#include "imgui.h"

AboutPage::AboutPage(UIState *state) : state{state} {}

void AboutPage::draw()
{
    if (!state->about_window)
        return;

    ImGui::Begin("About", &this->state->about_window);
    // ImGui::Begin("Another Window",
    //          &show_another_window); // Pass a pointer to our bool variable (the
    //                                 // window will have a closing button that will
    //                                 // clear the bool when clicked)
    ImGui::Text("Docker ImGui example");

    if (ImGui::Button("Закрыть"))
        this->state->about_window = false;

    ImGui::End();
}