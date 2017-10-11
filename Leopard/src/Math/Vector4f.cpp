#include "Vector4f.h"

namespace Leopard
{
	namespace Math
	{
		Vector4f::Vector4f()
		{
			this->X = 0.0f;
			this->Y = 0.0f;
			this->Z = 0.0f;
			this->W = 0.0f;
		}

		Vector4f::Vector4f(const float & x, const float & y, const float & z, const float & w)
		{
			this->X = x;
			this->Y = y;
			this->Z = z;
			this->W = w;
		}

		Vector4f & Vector4f::Add(const Vector4f & other)
		{
			X += other.X;
			Y += other.Y;
			Z += other.Z;
			W += other.W;

			return *this;
		}

		Vector4f & Vector4f::Subtract(const Vector4f & other)
		{
			X -= other.X;
			Y -= other.Y;
			Z -= other.Z;
			W -= other.W;

			return *this;
		}

		Vector4f & Vector4f::Multiply(const Vector4f & other)
		{
			X *= other.X;
			Y *= other.Y;
			Z *= other.Z;
			W *= other.W;

			return *this;
		}

		Vector4f & Vector4f::Divide(const Vector4f & other)
		{
			X /= other.X;
			Y /= other.Y;
			Z /= other.Z;
			W /= other.W;

			return *this;
		}


		Vector4f::~Vector4f()
		{
		}

		Vector4f & Vector4f::operator+=(const Vector4f & other)
		{
			return Add(other);
		}

		Vector4f & Vector4f::operator-=(const Vector4f & other)
		{
			return Subtract(other);
		}

		Vector4f & Vector4f::operator*=(const Vector4f & other)
		{
			return Multiply(other);
		}

		Vector4f & Vector4f::operator/=(const Vector4f & other)
		{
			return Divide(other);
		}

		bool Vector4f::operator==(const Vector4f & other)
		{
			return X == other.X && Y == other.Y && Z == other.Z && W == other.W;
		}

		bool Vector4f::operator!=(const Vector4f & other)
		{
			return !(*this == other);
		}

		Vector4f operator+(Vector4f left, const Vector4f &right)
		{
			return left.Add(right);
		}

		Vector4f operator-(Vector4f left, const Vector4f &right)
		{
			return left.Subtract(right);
		}

		Vector4f operator*(Vector4f left, const Vector4f &right)
		{
			return left.Multiply(right);
		}

		Vector4f operator/(Vector4f left, const Vector4f &right)
		{
			return left.Divide(right);
		}

		std::ostream & operator<<(std::ostream & stream, const Vector4f & Vector4f)
		{
			stream << "Vector4f: (" << Vector4f.X << ", " << Vector4f.Y << ", " << Vector4f.Z << ", " << Vector4f.W << ")";
			return stream;
		}

	}
}