#include <concepts>
#include <cstddef>
#include <vector>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>
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
			createInstance();
			initVulkan();
			mainLoop();
			clean();
		}
	
	private:
		Display affichage;
		VkInstance instance;

		void initwindow(){
			affichage.initDisplay();
		}
		
		void initVulkan(){
			
		}

		const bool AllExtensionsValide(const char** currentExtensions, const int currentExtensioncount) {
			unsigned int vkEnumCount = 0;
			vkEnumerateInstanceExtensionProperties(nullptr, &vkEnumCount, nullptr);
			std::vector<VkExtensionProperties> extensions (vkEnumCount);
			vkEnumerateInstanceExtensionProperties(nullptr, &vkEnumCount, extensions.data());
			
			for (int i = 0; i < currentExtensioncount; i++) {
				bool find = false;
				for(VkExtensionProperties extension : extensions) {
					if(extension.extensionName == currentExtensions[i]) {
						find = true;
						break;
					}
				}
				if(!find) {
					return false;
				}
			}
			return true;
		}

		void createInstance() {
			VkApplicationInfo appInfo{};
			appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
			appInfo.pApplicationName = "Hello Triangle";
			appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
			appInfo.pEngineName = "No Engine";
			appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
   		appInfo.apiVersion = VK_API_VERSION_1_0;

			VkInstanceCreateInfo createInfo{};
			createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
			createInfo.pApplicationInfo = &appInfo;

			unsigned int extensionNumber = 0;
			const char** names = NULL;
			affichage.getExtensions(extensionNumber, names);
			createInfo.enabledExtensionCount = extensionNumber;
			createInfo.ppEnabledExtensionNames = names;

			createInfo.enabledLayerCount = 0;

			if(vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS
				&& !AllExtensionsValide(names, extensionNumber)) {
				std::cerr << "erreur lors de la création de l'instance de Vulkan." << std::endl;
			} else {
				std::cout << "L'instance vulkan a été crée avec succès." << std::endl;
			}
		}

		void mainLoop(){
			affichage.loop();
		}

		void clean(){
			vkDestroyInstance(instance, nullptr);
			affichage.clean();
		}
};




int main()
{
	VulkanObject vulkO;
	vulkO.run();
	return 0;
}