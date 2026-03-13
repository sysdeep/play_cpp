#pragma once
#include <string>

namespace ui
{
    // обработчик который передаётся внутрь окна для обработки событий окна
    class WindowHandler
    {
    public:
        virtual ~WindowHandler() = default; // make it abstract

        // запрос на закрытие окна
        virtual void do_close(const std::string &id) = 0;

        // запрос на отображение контейнера
        virtual void do_toggle_container(const std::string &id) = 0;
    };
}