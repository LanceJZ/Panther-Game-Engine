#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
//glfw3dll.lib
//glfw3.lib
//glew32.lib
//glew32s.lib

#include "src/graphic/Window.h"
#include "src/Math/Math.h"

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


	Window window("Leopard!", 800, 600);
	glClearColor(0.05f, 0, 0.15f, 1);

	Matrix pos = Matrix::Translation(Vector3f(1, 2, 3));
	pos * Matrix::Identity();


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


		window.Clear();

		if (window.isKeyPressed(GLFW_KEY_A))
			LOG("A key pressed.");

		if (window.isButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
		{
			double x, y;
			window.getMousePosition(x, y);
			LOG(x << ", " << y);
		}

		glBegin(GL_QUADS); //Test drawing.
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		window.Update();
	}
}
