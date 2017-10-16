//#pragma comment(lib, "opengl32.lib")
//#pragma comment(lib, "glu32.lib")
//#pragma comment(lib, "glfw3.lib")
//#pragma comment(lib, "glew32s.lib") //Episode 10 19:42 for release mode. glfw3.lib;glew32s.lib;opengl32.lib;glu32.lib

#include "src/graphic/Window.h"
#include "src/graphic/Shader.h"
#include "src/graphic/Sprite.h"
#include "src/graphic/BatchedRenderer2D.h" // Episode 9 1:27
#include "src/Utilities/Timer.h"
#include "src\graphic\Layers\TileLayer.h"

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
#if 1
	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader shaderA("src/shaders/basic.vert", "src/shaders/basic.frag");
#else
	Shader shader("shaders/basic.vert", "shaders/basic.frag");
#endif

	shader.Enable();
	shaderA.Enable();
	shaderA.setUniform3f("light_pos", Vector3f(-2, -2, 1));
	shaderA.setUniform4f("color", Vector4f(0.5f, 0.5f, 0.5f, 1.0f));

	TileLayer layer(&shader);
	//layer.Add(new  Sprite(Vector3f(15.0f, 15.0f, 0.0f), Vector2f(55.0f, 55.0f), Vector4f(0.6f, 0.0f, 1.0f, 1.0f)));

	srand(time(NULL));

	std::vector<Sprite> sprites;

	for (int i = 0; i < 300; i++)
	{
		float x = (rand() % 800) - 400;
		float y = (rand() % 600) - 300;

		float r = (rand() % 100) *0.01f;
		float b = (rand() % 100) *0.01f;

		Vector2f size = Vector2f(rand() & 25 + 10, rand() & 25 + 10);

		Vector3f pos = Vector3f(x, y, 2.0f);
		Vector4f col = Vector4f(r, 0.0f, b, 1.0f);

		layer.Add( new Sprite(pos, Vector2f(15.0f, 15.0f), col));
	}

#if 0
	Matrix ortho = Matrix::Orthographic(-400.0f, 400.0f, -300.0f, 300.0f, -10.0f, 10.0f);
	shader.setUniformMatrix("pr_matrix", ortho);


	BatchedRenderer2D renderer;

	Sprite spriteA(Vector3f(15.0f, 15.0f, 0.0f), Vector2f(25.0f, 25.0f), Vector4f(0.6f, 0.0f, 1.0f, 1.0f));
	Sprite spriteB(Vector3f(0.0f, 0.0f, 0.0f), Vector2f(15.0f, 15.0f), Vector4f(0.8f, 0.0f, 0.5f, 1.0f));



#if 0
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	shader.setUniformMatrix("ml_matrix", Matrix::Translate(Vector3f(2, -1, 0)));
	shader.setUniformMatrix("vw_matrix", Matrix::Rotation(0.79f, Vector3f(0, 0, 1)));

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
	VertexArray sprite1, sprite2;
	IndexBuffer ibo(indices, 6);
	sprite1.addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite1.addBuffer(new Buffer(colorsA, 4 * 4, 4), 1);

	sprite2.addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite2.addBuffer(new Buffer(colorsB, 4 * 4, 4), 1);
#endif
#endif

	Timer time;

	unsigned int frames = 0;
	unsigned int totalFPS = 0;
	unsigned int totalSeconds = 0;
	//-----------------------Testing.


	while (!window.Closed())
	{

#if 0
		//if (joyNumber == 0)
		//{
		//	const unsigned char* button = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &joyButtonCount);

		//	if (button != NULL)
		//	{

		//		if (button[0] == GLFW_PRESS)
		//			LOG("JoyButton A Pressed");

		//		if (button[1] == GLFW_PRESS)
		//			LOG("JoyButton B Pressed");
		//	}
		//}

		//if (window.isKeyPressed(GLFW_KEY_A))
		//	LOG("A key pressed.");
#endif

		window.Clear();

		if (window.isButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
		{
			double x, y;
			window.getMousePosition(x, y);
			//float mX = ((float)x - 400.0f) * 0.15f, mY = (((float)y - 300.0f) * -1.0f) * 0.15f;
			float mX = ((float)x - 400.0f), mY = (((float)y - 300.0f) * -1.0f);

			//LOG(x << ", " << y);
			//LOG("Mouse X, Y " << mX << ", " << mY);

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
#if 0
		renderer.Begin();

		for (const Renderable2D renderable : sprites) //40FPS gain over for next loop.
			renderer.Submit(&renderable);

		renderer.Submit(&spriteA);
		renderer.Submit(&spriteB); //Working at 1:29

		renderer.End();
		renderer.Flush();
#endif

		layer.Draw();

		window.Update();

		frames++;

		if (time.Elapsed() > 1.0f)
		{
			printf("%d FPS\n", frames);
			totalFPS += frames;
			totalSeconds ++;
			printf("%d Average FPS\n", totalFPS / totalSeconds);
			frames = 0;
			time.Reset();
		}
	}
}
