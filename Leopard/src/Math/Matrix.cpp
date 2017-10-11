#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

#include "Matrix.h"

namespace Leopard
{
	namespace Math
	{

		Matrix::Matrix()
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				Elements[i] = 0.0f;
			}
		}

		Matrix::Matrix(float diagonal)
		{
			for (int i = 0; i < 4 * 4; i++)
			{
				Elements[i] = 0.0f;
			}

			for (int i = 0; i < 4; i++)
			{
				Elements[i + i * 4] = diagonal;
			}
		}


		Matrix::~Matrix()
		{

		}

		Matrix Matrix::Identity()
		{
			return Matrix(1.0f);
		}

		Matrix Matrix::Multiply(const Matrix & other)
		{
			for (int y = 0; y < 4; y++)
			{
				for (int x = 0; x < 4; x++)
				{
					float sum = 0.0f;

					for (int e = 0; e < 4; e++)
					{
						sum += Elements[x + e] * other.Elements[e + y * 4];
					}

					Elements[x + y * 4] = sum;
				}
			}


			return *this;
		}

		Matrix Matrix::Orthographic(float left, float right, float top, float bottom, float near, float far)
		{
			Matrix result(1.0f);

			result.Elements[0 + 0 * 4] = 2 / (right - left);
			result.Elements[1 + 1 * 4] = 2 / (top - bottom);
			result.Elements[2 + 2 * 4] = 2 / (near - far);

			result.Elements[0 + 3 * 4] = 2 / (right + left) / (right - left);
			result.Elements[1 + 3 * 4] = 2 / (top + bottom) / (top - bottom);
			result.Elements[2 + 3 * 4] = 2 / (near + far) / (near - far);

			return result;
		}

		Matrix Matrix::Perspective(float fov, float aspectRatio, float near, float far)
		{
			Matrix result(1.0f);

			//degrees * ((float)M_PI / 180.0f);

			float q = 1.0f / tan((0.5f * fov) * ((float)M_PI / 180.0f));
			float a = q / aspectRatio;

			float b = (near + far) / (near - far);
			float c = (2.0f * near * far) / (near - far);

			result.Elements[0 + 0 * 4] = a;
			result.Elements[1 + 1 * 4] = q;
			result.Elements[2 + 2 * 4] = b;
			result.Elements[3 + 2 * 4] = c - 1.0f;
			result.Elements[2 + 3 * 4] = c;

			return result;
		}

		Matrix Matrix::Translation(const Vector3f & translation)
		{
			Matrix result(1.0f);

			result.Elements[0 + 3 * 4] = translation.X;
			result.Elements[1 + 3 * 4] = translation.Y;
			result.Elements[2 + 3 * 4] = translation.Z;

			return result;
		}

		Matrix Matrix::Rotation(float radians, const Vector3f & axis)
		{
			Matrix result(1.0f);

			float c = cos(radians);
			float s = sin(radians);
			float omc = 1.0f - c;

			result.Elements[0 + 0 * 4] = axis.X * omc + c;
			result.Elements[1 + 0 * 4] = axis.Y * axis.X * omc + axis.Z * s;
			result.Elements[2 + 0 * 4] = axis.X * axis.Z * omc - axis.Y * s;

			result.Elements[0 + 1 * 4] = axis.X * axis.Y * omc - axis.Z * s;
			result.Elements[1 + 1 * 4] = axis.Y * omc + c;
			result.Elements[2 + 1 * 4] = axis.Y * axis.Z * omc + axis.X * s;

			result.Elements[0 + 2 * 4] = axis.X * axis.Z * omc + axis.Y * s;
			result.Elements[1 + 2 * 4] = axis.Y * axis.Z * omc - axis.X * s;
			result.Elements[2 + 2 * 4] = axis.Z * omc + c;

			return result;
		}

		Matrix Matrix::Scale(const Vector3f & scale)
		{
			Matrix result(1.0f);

			result.Elements[0 + 0 * 4] = scale.X;
			result.Elements[1 + 1 * 4] = scale.Y;
			result.Elements[2 + 2 * 4] = scale.Z;

			return result;
		}

		Matrix operator*(Matrix left, const Matrix & right)
		{
			return left.Multiply(right);
		}

		//std::ostream & operator<<(std::ostream & stream, const Matrix & Matrix)
		//{
		//	// TODO: insert return statement here
		//}

		Matrix & Matrix::operator*=(const Matrix & other)
		{
			return Multiply(other);
		}
	}
}