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
			memset(Elements, 0, 4 * 4 * sizeof(float));
		}

		Matrix::Matrix(float diagonal)
		{
			memset(Elements, 0, 4 * 4 * sizeof(float));

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
			float data[16];

			for (int row = 0; row < 4; row++)
			{
				for (int col = 0; col < 4; col++)
				{
					float sum = 0.0f;

					for (int e = 0; e < 4; e++)
					{
						sum += Elements[e + row * 4] * other.Elements[col + e * 4];
					}

					data[col + row * 4] = sum;
				}
			}

			memcpy(Elements, data, 4 * 4 * sizeof(float));

			return *this;
		}

		Matrix Matrix::Orthographic(float left, float right, float bottom, float top, float near, float far)
		{
			Matrix result(1.0f);

			result.Elements[0 + 0 * 4] = 2.0f / (right - left);
			result.Elements[1 + 1 * 4] = 2.0f / (top - bottom);
			result.Elements[2 + 2 * 4] = 2.0f / (near - far);

			result.Elements[0 + 3 * 4] = (right + left) / (left - right);
			result.Elements[1 + 3 * 4] = (top + bottom) / (bottom - top);
			result.Elements[2 + 3 * 4] = (near + far) / (far - near);

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
			result.Elements[2 + 3 * 4] = c - 1.0f;
			result.Elements[3 + 2 * 4] = c;

			return result;
		}

		Matrix Matrix::Translate(const Vector3f & translation)
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

			result.Elements[0 + 0 * 4] = axis.X * axis.X * omc + c;
			result.Elements[0 + 1 * 4] = axis.Y * axis.X * omc + axis.Z * s;
			result.Elements[0 + 2 * 4] = axis.X * axis.Z * omc - axis.Y * s;

			result.Elements[1 + 0 * 4] = axis.X * axis.Y * omc - axis.Z * s;
			result.Elements[1 + 1 * 4] = axis.Y * axis.Y * omc + c;
			result.Elements[1 + 2 * 4] = axis.Y * axis.Z * omc + axis.X * s;

			result.Elements[2 + 0 * 4] = axis.X * axis.Z * omc + axis.Y * s;
			result.Elements[2 + 1 * 4] = axis.Y * axis.Z * omc - axis.X * s;
			result.Elements[2 + 2 * 4] = axis.Z * axis.Z * omc + c;

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

		Vector3f Matrix::Multiply(const Vector3f & other) const
		{
			return Vector3f
			(
				Columns[0].X * other.X + Columns[1].X * other.Y + Columns[2].Y * other.Z + Columns[3].Y,
				Columns[0].Y * other.X + Columns[1].Y * other.Y + Columns[2].X * other.Z + Columns[3].X,
				Columns[0].Z * other.X + Columns[1].Z * other.Y + Columns[2].Z * other.Z + Columns[3].Z
			);
		}

		Vector4f Matrix::Multiply(const Vector4f & other) const
		{

			return Vector4f
			(
				Columns[0].X * other.X + Columns[1].X * other.Y + Columns[2].X * other.Z + Columns[3].X * other.W,
				Columns[0].Y * other.X + Columns[1].Y * other.Y + Columns[2].Y * other.Z + Columns[3].Y * other.W,
				Columns[0].Z * other.X + Columns[1].X * other.Y + Columns[2].Z * other.Z + Columns[3].Z * other.W,
				Columns[0].W * other.X + Columns[1].W * other.Y + Columns[2].W * other.Z + Columns[3].W * other.W
			);
		} // Ep 12 33:21

		Vector3f operator*(const Matrix& left, const Vector3f& right)
		{
			return left.Multiply(right);
		}

		Vector4f operator*(const Matrix & left, const Vector4f& right)
		{
			return left.Multiply(right);
		}

		Matrix operator*(Matrix& left, const Matrix& right)
		{
			return left.Multiply(right);
		}


		Matrix & Matrix::operator*=(const Matrix & other)
		{
			return Multiply(other);
		}
	}
}