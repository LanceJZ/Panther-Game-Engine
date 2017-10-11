#pragma once

#include <iostream>
#include "Math.h"

namespace Leopard
{
	namespace Math
	{
		struct Matrix
		{
			float Elements[4 * 4];


			Matrix();
			Matrix(float diagonal);
			~Matrix();

			static Matrix Identity();
			Matrix Multiply(const Matrix& other);

			static Matrix Orthographic(float left, float right, float top, float bottom, float near, float far);
			static Matrix Perspective(float fov, float aspectRatio, float near, float far);

			static Matrix Translation(const Vector3f& translation);
			static Matrix Rotation(float angle, const Vector3f& axis);
			static Matrix Scale(const Vector3f& scale);

			friend Matrix operator*(Matrix left, const Matrix& right);

			Matrix& operator*=(const Matrix& other);

			//friend std::ostream& operator<<(std::ostream& stream, const Matrix& Matrix);

		};

	}
}
