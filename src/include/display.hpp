#ifndef __DISPLAY__
#define __DISPLAY__
#define SDL_MAIN_HANDLED
#define SDL_INCLUDE_VULKAN
#include <SDL2/SDL.h>
#include <vector>

class Display {
  public:
    Display();
    void initDisplay();
    
    /*
    simple utilisation en getteur de la fonction "getInstance" de SDL2.
    Voir la doc pour plus d'info.
    */
    std::vector<const char*> getExtensions(unsigned int& number);
    void loop();
    void clean();

  private:
    SDL_Window *window;
    SDL_Event events;
    SDL_Renderer *renderer;
    
    bool is_running;
};

#endif