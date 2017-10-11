#pragma once

#include <iostream>

namespace Leopard
{
	namespace Math
	{
		struct Vector3f
		{
			float X, Y, Z;

			Vector3f();
			Vector3f(const float& x, const float& y, const float& z);

			Vector3f& Add(const Vector3f& other);
			Vector3f& Subtract(const Vector3f& other);
			Vector3f& Multiply(const Vector3f& other);
			Vector3f& Divide(const Vector3f& other);

			~Vector3f();

			friend Vector3f operator+(Vector3f left, const Vector3f& right);
			friend Vector3f operator-(Vector3f left, const Vector3f& right);
			friend Vector3f operator*(Vector3f left, const Vector3f& right);
			friend Vector3f operator/(Vector3f left, const Vector3f& right);

			Vector3f& operator+=(const Vector3f& other);
			Vector3f& operator-=(const Vector3f& other);
			Vector3f& operator*=(const Vector3f& other);
			Vector3f& operator/=(const Vector3f& other);

			bool operator==(const Vector3f& other);
			bool operator!=(const Vector3f& other);

			friend std::ostream& operator<<(std::ostream& stream, const Vector3f& Vector3f);
		};
	}
}

