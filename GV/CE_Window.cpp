#include "CVulkan_Core.h"

CE_Window::CE_Window(std::string _Name, int _Width, int _Height)
	: GV_Module(_Name)
	, m_WindowWidth(_Width)
	, m_WindowHeight(_Height)
{

}

CE_Window::~CE_Window()
{

}

void CE_Window::InitializeWindow(void(*_framebufferResizeCallback)(GLFWwindow* _window, int _width, int _height), void(*_Key_Callback_Function)(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods))
{
	///
	//default
	glfwInit();
	///

	///
	//Instance
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	//glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	m_Window = glfwCreateWindow(m_WindowWidth, m_WindowHeight, "EW_GV", nullptr, nullptr);
	///

	///
	//Swap Chain Recreation
	if (!_framebufferResizeCallback)
		glfwSetFramebufferSizeCallback(m_Window, _framebufferResizeCallback);
	else
		glfwSetFramebufferSizeCallback(m_Window, framebufferResizeCallback);
	///

	if (!_Key_Callback_Function)
		glfwSetKeyCallback(m_Window, _Key_Callback_Function);
	else
		glfwSetKeyCallback(m_Window, DefaultKey_callback);
}

void CE_Window::DestroyInstance(VkDevice _device)
{
	glfwDestroyWindow(m_Window);

	glfwTerminate();
}

GLFWwindow* CE_Window::GetPoint()
{
	return m_Window;
}

void CE_Window::framebufferResizeCallback(GLFWwindow* _window, int _width, int _height)
{

}

void CE_Window::DefaultKey_callback(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods)
{

}

