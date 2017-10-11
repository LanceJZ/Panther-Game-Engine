#include "Vector3f.h"

namespace Leopard
{
	namespace Math
	{
		Vector3f::Vector3f()
		{
			this->X = 0.0f;
			this->Y = 0.0f;
			this->Z = 0.0f;
		}

		Vector3f::Vector3f(const float & x, const float & y, const float & z)
		{
			this->X = x;
			this->Y = y;
			this->Z = z;
		}

		Vector3f & Vector3f::Add(const Vector3f & other)
		{
			X += other.X;
			Y += other.Y;
			Z += other.Z;

			return *this;
		}

		Vector3f & Vector3f::Subtract(const Vector3f & other)
		{
			X -= other.X;
			Y -= other.Y;
			Z -= other.Z;

			return *this;
		}

		Vector3f & Vector3f::Multiply(const Vector3f & other)
		{
			X *= other.X;
			Y *= other.Y;
			Z *= other.Z;

			return *this;
		}

		Vector3f & Vector3f::Divide(const Vector3f & other)
		{
			X /= other.X;
			Y /= other.Y;
			Z /= other.Z;

			return *this;
		}


		Vector3f::~Vector3f()
		{
		}

		Vector3f & Vector3f::operator+=(const Vector3f & other)
		{
			return Add(other);
		}

		Vector3f & Vector3f::operator-=(const Vector3f & other)
		{
			return Subtract(other);
		}

		Vector3f & Vector3f::operator*=(const Vector3f & other)
		{
			return Multiply(other);
		}

		Vector3f & Vector3f::operator/=(const Vector3f & other)
		{
			return Divide(other);
		}

		bool Vector3f::operator==(const Vector3f & other)
		{
			return X == other.X && Y == other.Y && Z == other.Z;
		}

		bool Vector3f::operator!=(const Vector3f & other)
		{
			return !(*this == other);
		}

		Vector3f operator+(Vector3f left, const Vector3f &right)
		{
			return left.Add(right);
		}

		Vector3f operator-(Vector3f left, const Vector3f &right)
		{
			return left.Subtract(right);
		}

		Vector3f operator*(Vector3f left, const Vector3f &right)
		{
			return left.Multiply(right);
		}

		Vector3f operator/(Vector3f left, const Vector3f &right)
		{
			return left.Divide(right);
		}

		std::ostream & operator<<(std::ostream & stream, const Vector3f & Vector3f)
		{
			stream << "Vector3f: (" << Vector3f.X << ", " << Vector3f.Y << ", " << Vector3f.Z << ")";
			return stream;
		}

	}
}