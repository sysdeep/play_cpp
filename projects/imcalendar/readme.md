# ImCalendar

- https://howardhinnant.github.io/date/date.html

## TODO

- [x] BUG ноябрь 2026 - 31 число отображается в субботу, хотя 31 вообще нет
- [x] подсветить выходные
- [ ] добавить сочетание клавиш для выхода, например q или Esq
- [ ] добавить about
- [ ] сетка 7x5 - в пустые клетки добавить отображение пред-след месяца - заблокированные
- [x] аргументы cmd - version
- [x] добавить шрифт в ресурсы
- [x] добавить кнопку today
- [x] дефект - разные месяцы содержат разное кол-во строк -> скачки то что ниже сетки

## Dev

### argparse

https://github.com/p-ranav/argparse

##№ Fonts

```bash
g++ misc/fonts/binary_to_compressed_c.cpp -o binary_to_compressed_c

./binary_to_compressed_c ../vendors/imgui/misc/fonts/Roboto-Medium.ttf Roboto > roboto.cpp
./binary_to_compressed_c ../vendors/fonts/JetBrainsMonoNerdFontMono-Regular.ttf JetBrains > ../src/ui/gen/font.cpp
```

### Integration in ImGui

Once the tool has generated the C-style array in your source file, you can load the data in your C++ application using the ImGui functions designed for embedded, compressed data. A common function is `ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF()` or `AddFontFromMemoryCompressedBase85TTF()`, depending on the flags used during generation

TODO: - добавить рекомпеляцию в make

1 - поместить нужный шрифт в vendors/fonts/
2 - скомпилировать `./binary_to_compressed_c ../vendors/fonts/JetBrainsMonoNerdFontMono-Regular.ttf JetBrains > ../src/ui/gen/font_FONTNAME.cpp`
3 - подключить в main_window `io->Fonts->AddFontFromMemoryCompressedTTF(JetBrains_compressed_data, JetBrains_compressed_size);`
