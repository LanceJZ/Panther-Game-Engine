#pragma once

#include <iostream>

namespace Leopard
{
	namespace Math
	{
		struct Vector2f
		{
			float X, Y;

			Vector2f();
			Vector2f(const float& x, const float& y);

			Vector2f& Add(const Vector2f& other);
			Vector2f& Subtract(const Vector2f& other);
			Vector2f& Multiply(const Vector2f& other);
			Vector2f& Divide(const Vector2f& other);

			~Vector2f();

			friend Vector2f operator+(Vector2f left, const Vector2f& right);
			friend Vector2f operator-(Vector2f left, const Vector2f& right);
			friend Vector2f operator*(Vector2f left, const Vector2f& right);
			friend Vector2f operator/(Vector2f left, const Vector2f& right);

			Vector2f& operator+=(const Vector2f& other);
			Vector2f& operator-=(const Vector2f& other);
			Vector2f& operator*=(const Vector2f& other);
			Vector2f& operator/=(const Vector2f& other);

			bool operator==(const Vector2f& other);
			bool operator!=(const Vector2f& other);

			friend std::ostream& operator<<(std::ostream& stream, const Vector2f& vector2f);
		};
	}
}

