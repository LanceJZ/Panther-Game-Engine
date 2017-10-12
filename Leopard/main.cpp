#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
//glfw3dll.lib
//glfw3.lib
//glew32.lib
//glew32s.lib

#include "src/graphic/Window.h"
#include "src/graphic/Shader.h"
#include "src/Math/Math.h"
#include "src/Utilities/File.h"

#if _DEBUG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

int main()
{
	using namespace Leopard;
	using namespace Graphics;
	using namespace Math;

	int joyButtonCount = 0;
	int joyNumber = glfwJoystickPresent(GLFW_JOYSTICK_1);

	Window window("Leopard Game Engine", 800, 600);
	glClearColor(0.01f, 0, 0.04f, 1);

	//-----------------------Testing.
	GLfloat vertices[] =
	{
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	Matrix ortho = Matrix::Orthographic(-8.0f, 8.0f, -6.0f, 6.0f, -1.0f, 1.0f);

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.Enable();
	shader.setUniformMatrix("pr_matrix", ortho);
	shader.setUniformMatrix("ml_matrix", Matrix::Translate(Vector3f(2, -1, 0)));
	shader.setUniformMatrix("vw_matrix", Matrix::Rotation(0.79f, Vector3f(0, 0, 1)));
	shader.setUniform3f("light_pos", Vector3f(2, 1, 3));
	shader.setUniform4f("setcolor", Vector4f(0.5f, 0.0f, 0.6f, 1.0f));

	//-----------------------Testing.


	while (!window.Closed())
	{
		if (joyNumber == 0)
		{
			const unsigned char* button = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &joyButtonCount);

			if (button != NULL)
			{

				if (button[0] == GLFW_PRESS)
					LOG("JoyButton A Pressed");

				if (button[1] == GLFW_PRESS)
					LOG("JoyButton B Pressed");
			}
		}

		if (window.isKeyPressed(GLFW_KEY_A))
			LOG("A key pressed.");

		if (window.isButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
		{
			double x, y;
			window.getMousePosition(x, y);
			LOG(x << ", " << y);
		}

		window.Clear();

		glDrawArrays(GL_TRIANGLES, 0, 6);

		window.Update();
	}
}
