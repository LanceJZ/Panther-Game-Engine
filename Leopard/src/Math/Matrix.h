#pragma once

#include <iostream>
#include "Math.h"

namespace Leopard
{
	namespace Math
	{
		struct Matrix
		{
			union
			{
				float Elements[4 * 4];
				Vector4f Columns[4];
			};

			Matrix();
			Matrix(float diagonal);
			~Matrix();

			static Matrix Identity();

			static Matrix Orthographic(float left, float right, float bottom, float top, float near, float far);
			static Matrix Perspective(float fov, float aspectRatio, float near, float far);

			static Matrix Translate(const Vector3f& translation);
			static Matrix Rotation(float angle, const Vector3f& axis);
			static Matrix Scale(const Vector3f& scale);
			friend Matrix operator*(Matrix& left, const Matrix& right);


			Vector3f Multiply(const Vector3f& other) const;
			friend Vector3f operator*(const Matrix& left, const Vector3f& right);

			Vector4f Multiply(const Vector4f& other) const;
			friend Vector4f operator*(const Matrix& left, const Vector4f& right);

			Matrix Multiply(const Matrix& other);
			Matrix& operator*=(const Matrix& other);

			Vector4f getColumn(int index)
			{
				index *= 4;
				return Vector4f(Elements[index], Elements[index + 1], Elements[index + 2], Elements[index + 3]);}
			};

	}
}
