#pragma once

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "CVulkan_Core.h"
//#include "Graphic.h"

namespace Command
{
	class Graphic
	{
	public:
		static void run(std::string _ProcName, int _Width, int _Height)
		{
			initVulkan(_ProcName, _Width, _Height);
			mainLoop();
			cleanup();
		}

	private:
		static void initVulkan(std::string _ProcName, int _Width, int _Height)
		{
			//Graphic_Vulkan::GetInstance()->initWindow();
			//Graphic_Vulkan::GetInstance()->initVulkan();

			GV_Core::CVulkan_Core::CreateInstance(_ProcName, _Width, _Height);
			GV_Core::CVulkan_Core::GetInstance()->initVulkan();
		}

		static void SceneChange()
		{
			GV_Core::CVulkan_Core::GetInstance()->Suspend();



			GV_Core::CVulkan_Core::GetInstance()->Reseum();
		}

		static void mainLoop()
		{
			//Graphic_Vulkan::GetInstance()->mainLoop();

			GV_Core::CVulkan_Core::GetInstance()->mainLoop();
		}

		static void cleanup()
		{
			//Graphic_Vulkan::GetInstance()->cleanup();

			GV_Core::CVulkan_Core::GetInstance()->cleanup();
		}
	};
}
