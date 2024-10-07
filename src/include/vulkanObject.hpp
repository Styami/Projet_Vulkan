#ifndef __VULKANOBJECT__
#define __VULKANOBJECT__
#include "display.hpp"
#include <vulkan/vulkan_core.h>

class VulkanObject {
	public:
		void run();
	
	private:
		Display affichage;
		VkInstance instance;
		const std::vector<const char*> validationLayers = {
			"VK_LAYER_KHRONOS_validation"
		};

		#ifdef NDEBUG
			const bool enableValidtionLayers = false;
		#else
			const bool enableValidtionLayers = true;
		#endif

        void initwindow();
		void initVulkan();
		const bool checkValidationLayerSupport();
		const bool AllExtensionsValide(const char** currentExtensions, const int currentExtensioncount);
		std::vector<const char*> getRequiredExtension();
		void createInstance();
		void mainLoop();
		void clean();
};

#endif