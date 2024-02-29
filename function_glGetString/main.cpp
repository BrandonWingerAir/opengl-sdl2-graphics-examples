#include <SDL2/SDL.h>
#include <iostream>

void InitializeProgram(){
  if(SDL_Init(SDL_INIT_VIDEO) < 0){
    std::cout << "SDL2 could not initialize video subsystem"
              << std::endl;
    exit(1);
  }
}

void MainLoop(){

}

void CleanUp(){
  SDL_Quit();
}

int main(int, char **){
  InitializeProgram();
  MainLoop();
  CleanUp();

  return 0;
}