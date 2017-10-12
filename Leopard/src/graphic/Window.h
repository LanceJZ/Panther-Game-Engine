#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#if _DEBUG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

namespace Leopard
{
	namespace Graphics
	{
		class Window
		{
		private:
			const char *m_Title;
			int m_Width, m_Height;
			GLFWwindow *m_Window;
			bool m_Closed;
			bool m_Keys[MAX_KEYS];
			bool m_MouseButtons[MAX_BUTTONS];
			double m_MouseX, m_MouseY;

		public:
			Window(const char *name, int width, int height);
			~Window();
			void Clear() const;
			void Update();
			bool Closed() const;

			inline int getWidth() const { return m_Width; };
			inline int getHeight() const { return m_Height;	};

			inline GLFWwindow *getWindow() const { return m_Window; }

			bool isKeyPressed(unsigned int keyCode) const;
			bool isButtonPressed(unsigned int buttonCode) const;
			void getMousePosition(double& mouseX, double& mouseY) const;
		private:
			bool Init();
			friend static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
			friend static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
			friend static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods);
			friend static void cursor_position_callback(GLFWwindow *window, double xpos, double ypos);
		};
	}
}