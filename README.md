# OpenGL SDL2 Graphics Programming - Examples
Following a lesson series: https://www.youtube.com/playlist?list=PLvv0ScY6vfd9zlZkIIqGDeG5TUWswkMox

## How to view an example:
Run program.exe file found in the directory.

## How to compile source files (Test SDL2, OpenGL Information and Draw Triangle):

### Linux:
g++ -std=c++17 main.cpp glad/src/glad.c -I./glad/include -o program -lSDL2 -ldl

### Windows (using msys64 MinGW)
g++ main.cpp ./glad/src/glad.c -I./glad/include -o program.exe -lmingw32 -lSDL2main -lSDL2

## How to compile C source files (Object Example):

### Linux:
gcc main.c object.c -o program

### Windows
gcc main.c object.c -o program.exe

## How to compile source files (Triangle Refactored Example):
### Linux:
g++ -std=c++17 ./src/*.cpp -o program.exe -I ./include/ -lSDL2 -ldl

### Windows (using msys64 MinGW)

g++ ./src/*.cpp -o program.exe ./include/glad/src/glad.c -I./include/glad/include -lmingw32 -lSDL2main -lSDL2