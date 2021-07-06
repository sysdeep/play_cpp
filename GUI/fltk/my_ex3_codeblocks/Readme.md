# FLTK CodeBlocks


Project -> build options


Примечание - необходимо установить для всех конфигураций


## Compiller

на вкладке Compiller settings -> Other compiller options

```
`../../fltk/fltk-config --cxxflags`
```

полный путь до fltk-config


или если fltk-config в path

```
`fltk-config --cxxflags`
```

или полный выхлоп fltk-config --cxxflags

мой пример 
```
../../fltk/fltk-config --cxxflags

-I../../fltk -I../../fltk/jpeg -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT
```


## Linker

на вкладке Linker settings -> Other linker options

```
`../../fltk/fltk-config --ldstaticflags`
```

полный путь до fltk-config


или если fltk-config в path

```
`fltk-config --ldstaticflags`
```

или полный выхлоп fltk-config --ldstaticflags

мой пример 
```
../../fltk/fltk-config --ldstaticflags

../../fltk/lib/libfltk.a -lXrender -lXcursor -lXfixes -lXext -lXft -lfontconfig -lXinerama -lpthread -ldl -lm -lX11
```

ВНИМАНИЕ - порядок библиотек очень важен!!!