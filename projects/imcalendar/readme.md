# ImCalendar

- https://howardhinnant.github.io/date/date.html

## Fonts

```bash
g++ misc/fonts/binary_to_compressed_c.cpp -o binary_to_compressed_c

./binary_to_compressed_c ../vendors/imgui/misc/fonts/Roboto-Medium.ttf Roboto > roboto.cpp
```

### Integration in ImGui

Once the tool has generated the C-style array in your source file, you can load the data in your C++ application using the ImGui functions designed for embedded, compressed data. A common function is `ImGui::GetIO().Fonts->AddFontFromMemoryCompressedTTF()` or `AddFontFromMemoryCompressedBase85TTF()`, depending on the flags used during generation
