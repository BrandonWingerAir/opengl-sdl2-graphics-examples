# OpenGL SDL2 Graphics Programming - Examples
Following a lesson series: https://www.youtube.com/playlist?list=PLvv0ScY6vfd9zlZkIIqGDeG5TUWswkMox

## How to view an example:
Run program.exe file found in the directory.

## How to compile source files:

### Linux:
g++ -std=c++17 main.cpp glad/src/glad.c -I./glad/include -o program -lSDL2 -ldl

### Windows (using msys64 MinGW)
g++ main.cpp ./glad/src/glad.c -I./glad/include -o program.exe -lmingw32 -lSDL2main -lSDL2

## How to compile C source files (objects example):

### Linux:
gcc main.c object.c -o program

### Windows
gcc main.c object.c -o program.exe