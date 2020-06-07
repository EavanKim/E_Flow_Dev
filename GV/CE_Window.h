#pragma once

class CE_Window : GV_Module
{
public:
	CE_Window(std::string _Name, int _Width, int _Height);
	virtual ~CE_Window();

	void InitializeWindow(void(*_framebufferResizeCallback)(GLFWwindow* _window, int _width, int _height), void(*_Key_Callback_Function)(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods));

	// GV_Module을(를) 통해 상속됨
	virtual void DestroyInstance(VkDevice _device) override;
	
	GLFWwindow* GetPoint();

protected:
	static void framebufferResizeCallback(GLFWwindow* _window, int _width, int _height);
	static void DefaultKey_callback(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods);

private:
	bool m_FramebufferResized = false;

	int m_WindowWidth = 800;
	int m_WindowHeight = 600;

	GLFWwindow* m_Window = nullptr;

};

