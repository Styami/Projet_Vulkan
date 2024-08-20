#include "display.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

Display::Display() {
  is_running = true;
}

void Display::initDisplay() {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("vulkan", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 450, SDL_WINDOW_SHOWN);
  SDL_SetWindowResizable(window, SDL_FALSE);
}


void Display::getExtensions(unsigned int& number, const char** names) {
  SDL_Vulkan_GetInstanceExtensions(window, &number, names);
}

void Display::loop() {
  while (is_running)
  {
    while (SDL_PollEvent(&events)) {
      if (events.window.event == SDL_WINDOWEVENT_CLOSE)
        is_running = false;
    }
  }
}

void Display::clean() {
  SDL_DestroyWindow(window);
  SDL_Quit();
}