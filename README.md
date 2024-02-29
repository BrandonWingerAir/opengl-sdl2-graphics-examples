# How to compile from source:

## Example - test_sdl2

### Linux:
g++ -std=c++17 main.cpp glad/src/glad.c -I./glad/include -o program -lSDL2 -ldl

### Windows (using msys64 MinGW)
g++ main.cpp ./glad/src/glad.c -I./glad/include -o program.exe -lmingw32 -lSDL2main -lSDL2

## Example - function_glGetString

### Linux:
g++ -std=c++17 main.cpp -o program -lSDL2 -ldl

### Windows (using msys64 MinGW)
g++ main.cpp -o program.exe -lmingw32 -lSDL2main -lSDL2