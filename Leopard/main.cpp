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
#include "src/graphic/Simple2DRenderer.h"
#include "src/Math/Math.h"
#include "src/Utilities/File.h"
#include "src/graphic/Buffer/Buffer.h"
#include "src/graphic/Buffer/IndexBuffer.h"
#include "src/graphic/Buffer/VertexArray.h"

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

	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.Enable();

	Matrix ortho = Matrix::Orthographic(-80.0f, 80.0f, -60.0f, 60.0f, -1.0f, 1.0f);

	shader.setUniform3f("light_pos", Vector3f(2, 1, 1));
	shader.setUniform4f("setcolor", Vector4f(0.3f, 0.0f, 0.6f, 1.0f));
	shader.setUniformMatrix("pr_matrix", ortho);

	Renderable2D spriteA(Vector3f(15, 15, 0), Vector2f(25, 25), Vector4f(0.6, 0, 1, 1), shader);
	Renderable2D spriteB(Vector3f(-15, -10, 0), Vector2f(15, 15), Vector4f(0.8, 0, 0.5, 1), shader);
	Simple2DRenderer renderer;


#if 0
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	shader.setUniformMatrix("ml_matrix", Matrix::Translate(Vector3f(2, -1, 0)));
	shader.setUniformMatrix("vw_matrix", Matrix::Rotation(0.79f, Vector3f(0, 0, 1)));
#endif

	GLfloat vertices[] =
	{
		-10.5f, -10.5f, 0.0f,
		-10.5f,  10.5f, 0.0f,
		 10.5f,  10.5f, 0.0f,
		 10.5f, -10.5f, 0.0f
	};

	GLushort indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	GLfloat colorsA[] =
	{
		0.1, 0, 0.2, 1,
		0.2, 0, 0.3, 1,
		0.3, 0, 0.4, 1,
		0.4, 0, 0.5, 1
	};

	GLfloat colorsB[] =
	{
		0.5, 0, 0.4, 1,
		0.6, 0, 0.3, 1,
		0.7, 0, 0.2, 1,
		0.8, 0, 0.1, 1
	};

#if 0
	VertexArray sprite1, sprite2;
	IndexBuffer ibo(indices, 6);
	sprite1.addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite1.addBuffer(new Buffer(colorsA, 4 * 4, 4), 1);

	sprite2.addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite2.addBuffer(new Buffer(colorsB, 4 * 4, 4), 1);
#endif

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


		window.Clear();

		if (window.isButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
		{
			double x, y;
			window.getMousePosition(x, y);
			float mX = ((float)x - 400.0f) * 0.15f, mY = (((float)y - 300.0f) * -1.0f) * 0.15f;

			LOG(x << ", " << y);
			LOG("Mouse X, Y " << mX << ", " << mY);

			shader.setUniform3f("light_pos", Vector3f(mX, mY, 1));
		}
		else
		{
			shader.setUniform3f("light_pos", Vector3f(2, 1, 0));
		}
#if 0
		glDrawArrays(GL_TRIANGLES, 0, 6);
#elseif 0
		sprite1.Bind();
		ibo.Bind();
		shader.setUniformMatrix("ml_matrix", Matrix::Translate(Vector3f(20, -10, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		sprite1.Unbind();
		ibo.Unbind();

		sprite2.Bind();
		ibo.Bind();
		shader.setUniformMatrix("ml_matrix", Matrix::Translate(Vector3f(-20, 10, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		sprite2.Unbind();
		ibo.Unbind();
#endif

		renderer.Submit(&spriteA);
		renderer.Submit(&spriteB);
		renderer.Flush();

		window.Update();
	}
}
