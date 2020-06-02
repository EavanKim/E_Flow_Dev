#pragma once

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


#include "Graphic.h"

namespace Command
{
	class GRAPHIC_API Graphic
	{
	public:
		static void run()
		{
			initVulkan();
			mainLoop();
			cleanup();
		}

	private:
		static void initVulkan()
		{
			Graphic_Vulkan::GetInstance()->initWindow();
			Graphic_Vulkan::GetInstance()->initVulkan();
		}

		static void mainLoop()
		{
			Graphic_Vulkan::GetInstance()->mainLoop();
		}

		static void cleanup()
		{
			Graphic_Vulkan::GetInstance()->cleanup();
		}
	};
}
