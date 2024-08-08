#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"
#include <vulkan/vulkan.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>


int main()
{
    SDL_Window* window;
    SDL_Event events;
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL initialising successful" << std::endl;

        window = SDL_CreateWindow("SDL Practice",
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 640, SDL_WINDOW_SHOWN);

        if (window != 0)
        {
            std::cout << "Window creation succeeded" << std::endl;
        }
        else
        {
            std::cout << "Window creation failed" << std::endl;
            return false;
        }
        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

        std::cout << extensionCount << " extensions supported\n";

        glm::mat4 matrix;
        glm::vec4 vec;
        auto test = matrix * vec;

        std::cout << extensionCount << " extensions supported\n";
    }
    else
    {
        std::cout << "SDL initalisation failed" << std::endl;
        return false;
    }
    bool is_running = true;
    while (is_running)
    {
        while (SDL_PollEvent(&events)) {
            if (events.window.event == SDL_WINDOWEVENT_CLOSE)
                is_running = false;
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}