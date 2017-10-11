#include "Vector2f.h"

namespace Leopard
{
	namespace Math
	{
		Vector2f::Vector2f()
		{
			this->X = 0.0f;
			this->Y = 0.0f;
		}

		Vector2f::Vector2f(const float & x, const float & y)
		{
			this->X = x;
			this->Y = y;
		}

		Vector2f & Vector2f::Add(const Vector2f & other)
		{
			X += other.X;
			Y += other.Y;

			return *this;
		}

		Vector2f & Vector2f::Subtract(const Vector2f & other)
		{
			X -= other.X;
			Y -= other.Y;

			return *this;
		}

		Vector2f & Vector2f::Multiply(const Vector2f & other)
		{
			X *= other.X;
			Y *= other.Y;

			return *this;
		}

		Vector2f & Vector2f::Divide(const Vector2f & other)
		{
			X /= other.X;
			Y /= other.Y;

			return *this;
		}


		Vector2f::~Vector2f()
		{
		}

		Vector2f &Vector2f::operator+=(const Vector2f & other)
		{
			return Add(other);
		}

		Vector2f &Vector2f::operator-=(const Vector2f & other)
		{
			return Subtract(other);
		}

		Vector2f &Vector2f::operator*=(const Vector2f & other)
		{
			return Multiply(other);
		}

		Vector2f &Vector2f::operator/=(const Vector2f & other)
		{
			return Divide(other);
		}

		bool Vector2f::operator==(const Vector2f & other)
		{
			return X == other.X && Y == other.Y;
		}

		bool Vector2f::operator!=(const Vector2f & other)
		{
			return !(*this == other);
		}

		Vector2f operator+(Vector2f left, const Vector2f &right)
		{
			return left.Add(right);
		}

		Vector2f operator-(Vector2f left, const Vector2f &right)
		{
			return left.Subtract(right);
		}

		Vector2f operator*(Vector2f left, const Vector2f &right)
		{
			return left.Multiply(right);
		}

		Vector2f operator/(Vector2f left, const Vector2f &right)
		{
			return left.Divide(right);
		}

		std::ostream & operator<<(std::ostream & stream, const Vector2f & vector2f)
		{
			stream << "Vector2f: (" << vector2f.X << ", " << vector2f.Y << ")";
			return stream;
		}

	}
}