#include <vulkan/vulkan.h>
#include "display.hpp"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>

class VulkanObject {
	public:
		void run() {
			initwindow();
			initVulkan();
			mainLoop();
			clean();
		}
	
	private:
		Display affichage;

		void initwindow(){
			affichage.initDisplay();
		}
		
		void initVulkan(){
			
		}

		void mainLoop(){
			affichage.loop();
		}

		void clean(){
			affichage.clean();
		}
};




int main()
{
	VulkanObject vulkO;
	vulkO.run();
	return 0;
}