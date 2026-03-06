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
    };
}