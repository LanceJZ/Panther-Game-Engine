#include "Window.h"

namespace Leopard
{
	namespace Graphics
	{
		Window::Window(const char *title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;

			if (!Init())
				glfwTerminate();

			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_Keys[i] = false;
			}

			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				m_MouseButtons[i] = false;
			}
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::isKeyPressed(unsigned int keyCode) const
		{
			if (keyCode >= MAX_KEYS)
				return false;

			return m_Keys[keyCode];
		}

		bool Window::isButtonPressed(unsigned int buttonCode) const
		{
			if (buttonCode >= MAX_BUTTONS)
				return false;

			return m_MouseButtons[buttonCode];
		}

		void Window::getMousePosition(double & mouseX, double & mouseY) const
		{
			mouseX = m_MouseX;
			mouseY = m_MouseY;
		}

		bool Window::Init()
		{
			if (!glfwInit())
			{
				LOG("Error: No GLFW");
				system("PAUSE");
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

			if (m_Window == NULL)
			{
				LOG("Window creation failed.");
				system("PAUSE");
				return false;
			}

			glfwMakeContextCurrent(m_Window);
			glfwSetFramebufferSizeCallback(m_Window, framebuffer_size_callback);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);
			glfwSwapInterval(0);

			if (glewInit() != GLEW_OK)
			{
				LOG("GLEW Initialize Failed.");
				return false;
			}

			LOG("OpenGL Version");
			LOG(glGetString(GL_VERSION));

			return true;
		}

		bool Window::Closed() const
		{
			return glfwWindowShouldClose(m_Window) == 1;
		}

		void Window::Clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::Update()
		{
			GLenum error = glGetError();

			if (error != GL_NO_ERROR)
			{
				LOG("OpenGL Error: " << error << std::endl);
			}

			glfwPollEvents();
			glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glfwSwapBuffers(m_Window);
		}

		void framebuffer_size_callback(GLFWwindow * window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

		void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);

			win->m_Keys[key] = action != GLFW_RELEASE;
		}
		void mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseButtons[button] = action != GLFW_RELEASE;
		}
		void cursor_position_callback(GLFWwindow * window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseX = xpos;
			win->m_MouseY = ypos;
		}
	}
}