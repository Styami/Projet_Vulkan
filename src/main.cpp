#include <stdexcept>
#include <vector>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_core.h>
#include "display.hpp"
#include <cstring>

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
		const std::vector<const char*> validationLayers = {
			"VK_LAYER_KHRONOS_validation"
		};

		#ifdef NDEBUG
			const bool enableValidtionLayers = false;
		#else
			const bool enableValidtionLayers = true;
		#endif

		void initwindow(){
			affichage.initDisplay();
		}
		
		void initVulkan(){
			
		}
		

		const bool checkValidationLayerSupport() {
			unsigned int validationLayerCount = 0;

			vkEnumerateInstanceLayerProperties(&validationLayerCount, nullptr);
			std::vector<VkLayerProperties> availableLayers(validationLayerCount);
			vkEnumerateInstanceLayerProperties(&validationLayerCount, availableLayers.data());

			for (const char* validationLayer : validationLayers) {
				bool found = false;

				for(VkLayerProperties availableLayer : availableLayers) {
					if(!std::strcmp(validationLayer, availableLayer.layerName)) {
						found = true;
						break;
					}
				}
				if(!found)
					return false;
			}
			return true;
		}



		const bool AllExtensionsValide(const char** currentExtensions, const int currentExtensioncount) {
			unsigned int vkEnumCount = 0;

			vkEnumerateInstanceExtensionProperties(nullptr, &vkEnumCount, nullptr);
			std::vector<VkExtensionProperties> extensions (vkEnumCount);
			vkEnumerateInstanceExtensionProperties(nullptr, &vkEnumCount, extensions.data());
			
			for (int i = 0; i < currentExtensioncount; i++) {
				bool find = false;
				for(VkExtensionProperties extension : extensions) {
					if(std::strcmp(extension.extensionName,currentExtensions[i])) {
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



		std::vector<const char*> getRequiredExtension() {
			unsigned int extensionNumber = 0;
			//const char** names = NULL;
			std::vector<const char*> names = affichage.getExtensions(extensionNumber);
			if(enableValidtionLayers) {
				names.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
			}
			return names;
		}



		void createInstance() {
			if(enableValidtionLayers && !checkValidationLayerSupport()) {
				throw std::runtime_error("validation layers requested, but not available!");
			}

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

			std::vector<const char*> extensions = getRequiredExtension();
			createInfo.enabledExtensionCount = extensions.size();
			createInfo.ppEnabledExtensionNames = extensions.data();

			if(enableValidtionLayers) {
				createInfo.enabledLayerCount = validationLayers.size();
				createInfo.ppEnabledLayerNames = validationLayers.data();
			}	else {
				createInfo.enabledLayerCount = 0;
			}

			if(vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS
				&& !AllExtensionsValide(extensions.data(), extensions.size())) {
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




int main(int argc, char *argv[])
{
	VulkanObject vulkO;
	vulkO.run();
	return 0;
}