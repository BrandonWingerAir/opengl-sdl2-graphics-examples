# OpenGL SDL2 Graphics - Programming Examples
Following a tutorial series: https://www.youtube.com/playlist?list=PLvv0ScY6vfd9zlZkIIqGDeG5TUWswkMox

## How to compile source files:

### Linux:
g++ -std=c++17 main.cpp glad/src/glad.c -I./glad/include -o program -lSDL2 -ldl

### Windows (using msys64 MinGW)
g++ main.cpp ./glad/src/glad.c -I./glad/include -o program.exe -lmingw32 -lSDL2main -lSDL2