#pragma once

#include "../Utilities/File.h"
#include "../Math/Math.h"
#include <iostream>
#include <vector>
#include <GL/glew.h>

#if _DEBUG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

namespace Leopard
{
	namespace Graphics
	{
		using namespace Math;

		class Shader
		{
		public:
		private:
			GLuint m_ShaderID;
			const char *m_VertPath, *m_FragPath;
		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();

			GLint getUniform(GLchar* name);

			void setUniform1f(const GLchar* name, float value);
			void setUniform1i(const GLchar* name, int value);
			void setUniform2f(const GLchar* name, const Vector2f& vecter2f);
			void setUniform3f(const GLchar* name, const Vector3f& vector3f);
			void setUniform4f(const GLchar* name, const Vector4f& vector4f);

			void setUniformMatrix(const GLchar* name, const Matrix& matrix);

			void Enable() const;
			void Disable() const;

		private:
			GLuint Load();
			GLint getUniformLocation(const GLchar * name);
		};
	}
}