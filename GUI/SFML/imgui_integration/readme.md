# SFML cmake example + imgui

- https://github.com/SFML/imgui-sfml/tree/v2.5
- https://github.com/ocornut/imgui

действуем по документации по ручному подключению

## integrating into your project manually

- Download ImGui
- Add ImGui folder to your include directories
- Add imgui.cpp, imgui_widgets.cpp, imgui_draw.cpp and imgui_tables.cpp to your build/project
- Copy the contents of imconfig-SFML.h to your imconfig.h file. (to be able to cast ImVec2 to sf::Vector2f and vice versa)
- Add a folder which contains imgui-SFML.h to your include directories
- Add imgui-SFML.cpp to your build/project
- Link OpenGL if you get linking errors

рабочая версия imgui - 1.80

1.92.5 - ошибки линковки, если смотреть мастер imgui-sfml - то там и требования на sfml другие(> 3) и imgui посвежее
