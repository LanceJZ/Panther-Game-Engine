#include "Shader.h"

namespace Leopard
{
	namespace Graphics
	{
		Shader::Shader(const char* vertPath, const char* fragPath)
			: m_VertPath(vertPath), m_FragPath(fragPath)
		{
			m_ShaderID = Load();
		}

		Shader::~Shader()
		{
			glDeleteProgram(m_ShaderID);
		}

		void Shader::setUniform1f(const GLchar * name, float value)
		{
			glUniform1f(getUniformLocation(name), value);
		}

		void Shader::setUniform1i(const GLchar * name, int value)
		{
			glUniform1i(getUniformLocation(name), value);
		}

		void Shader::setUniform2f(const GLchar * name, const Vector2f & vector2f)
		{
			glUniform2f(getUniformLocation(name), vector2f.X, vector2f.Y);
		}

		void Shader::setUniform3f(const GLchar * name, const Vector3f & vector3f)
		{
			glUniform3f(getUniformLocation(name), vector3f.X, vector3f.Y, vector3f.Z);
		}

		void Shader::setUniform4f(const GLchar * name, const Vector4f & vector4f)
		{
			glUniform4f(getUniformLocation(name), vector4f.X, vector4f.Y, vector4f.Z, vector4f.W);
		}

		void Shader::setUniformMatrix(const GLchar * name, const Matrix & matrix)
		{
			glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.Elements);
		}

		void Shader::Enable() const
		{
			glUseProgram(m_ShaderID);
		}

		void Shader::Disable() const
		{
			glUseProgram(0);
		}

		GLuint Shader::Load()
		{
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertFile = Utilities::read_file(m_VertPath);
			std::string fragFile = Utilities::read_file(m_FragPath);

			const char* vertSource = vertFile.c_str();
			const char* fragSource = fragFile.c_str();

			glShaderSource(vertex, 1, &vertSource, NULL);
			glCompileShader(vertex);

			GLint result;

			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);

				LOG("Failed to compile vertex shader." << std::endl << &error[0]);

				glDeleteShader(vertex);
				return 0;
			}

			glShaderSource(fragment, 1, &fragSource, NULL);
			glCompileShader(fragment);

			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);

				LOG("Failed to compile fragment shader." << std::endl << &error[0]);

				glDeleteShader(fragment);
				return 0;
			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			glLinkProgram(program);
			glValidateProgram(program);

			glDetachShader(program, vertex);
			glDetachShader(program, fragment);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return program;
		}

		GLint Shader::getUniformLocation(const GLchar * name)
		{
			return glGetUniformLocation(m_ShaderID, name);
		}
	}
}