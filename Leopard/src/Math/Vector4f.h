#pragma once

#include <iostream>

namespace Leopard
{
	namespace Math
	{
		struct Vector4f
		{
			float X, Y, Z, W;

			Vector4f();
			Vector4f(const float& x, const float& y, const float& z, const float& w);

			Vector4f& Add(const Vector4f& other);
			Vector4f& Subtract(const Vector4f& other);
			Vector4f& Multiply(const Vector4f& other);
			Vector4f& Divide(const Vector4f& other);

			~Vector4f();

			friend Vector4f operator+(Vector4f left, const Vector4f& right);
			friend Vector4f operator-(Vector4f left, const Vector4f& right);
			friend Vector4f operator*(Vector4f left, const Vector4f& right);
			friend Vector4f operator/(Vector4f left, const Vector4f& right);

			Vector4f& operator+=(const Vector4f& other);
			Vector4f& operator-=(const Vector4f& other);
			Vector4f& operator*=(const Vector4f& other);
			Vector4f& operator/=(const Vector4f& other);

			bool operator==(const Vector4f& other);
			bool operator!=(const Vector4f& other);

			friend std::ostream& operator<<(std::ostream& stream, const Vector4f& Vector4f);
		};
	}
}

