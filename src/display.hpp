#define SDL_MAIN_HANDLED
#define SDL_INCLUDE_VULKAN
#include <SDL2/SDL.h>

class Display {
  public:
    Display();
    void initDisplay();
    
    /*
    simple utilisation en getteur de la fonction "getInstance" de SDL2.
    Voir la doc pour plus d'info.
    */
    void getExtensions(unsigned int& number, const char** names);
    void loop();
    void clean();

  private:
    SDL_Window *window;
    SDL_Event events;
    SDL_Renderer *renderer;
    
    bool is_running;
};