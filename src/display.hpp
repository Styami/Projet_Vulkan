#define SDL_MAIN_HANDLED
#define SDL_INCLUDE_VULKAN
#include <SDL2/SDL.h>

class Display {
  public:
    Display();
    void initDisplay();
    void loop();
    void clean();

  private:
    SDL_Window *window;
    SDL_Event events;
    SDL_Renderer *renderer;
    bool is_running;
};