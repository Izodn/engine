#include "Vector3.hpp"
#include <cmath>
#include <sstream>

// Constructors
Vector3::Vector3(double x, double y, double z)
{
	SetX(x);
	SetY(y);
	SetZ(z);
}
Vector3::Vector3()
{
	Vector3(0.0f, 0.0f, 0.0f);
}

// Getters/Setters
Vector3 Vector3::SetX(double x)
{
	m_X = x;
	return *this;
}
Vector3 Vector3::SetY(double y)
{
	m_Y = y;
	return *this;
}
Vector3 Vector3::SetZ(double z)
{
	m_Z = z;
	return *this;
}
double Vector3::GetX()
{
	return m_X;
}
double Vector3::GetY()
{
	return m_Y;
}
double Vector3::GetZ()
{
	return m_Z;
}

// Methods
double Vector3::Length()
{
	return sqrt(
		pow(m_X, 2.0f) + pow(m_Y, 2.0f) + pow(m_Z, 2.0f)
	);
}
Vector3 Vector3::Normalize()
{
	return *this /= Length();
}
Vector3 Vector3::Normalized()
{
	Vector3 vec(GetX(), GetY(), GetZ());
	return vec /= vec.Length();
}
double Vector3::Distance(Vector3 target)
{
	return Distance(*this, target);
}
double Vector3::Angle(Vector3 target)
{
	return Angle(*this, target);
}
double Vector3::Dot(Vector3 target)
{
	return Dot(*this, target);
}
Vector3 Vector3::Cross(Vector3 target)
{
	return Cross(*this, target);
}

// Static methods
double Vector3::Distance(Vector3 vec1, Vector3 vec2)
{
	return (vec1 - vec2).Length();
}
double Vector3::Angle(Vector3 vec1, Vector3 vec2)
{
	double denominator = (
		vec1.Length() * vec2.Length()
	);

	// if devide by zero, then must be a 90-degree angle
	if (denominator == 0.0f) {
		return 90.0f;
	}

	return acos(
		(
			(vec1.GetX() * vec2.GetX()) +
			(vec1.GetY() * vec2.GetY()) +
			(vec1.GetZ() * vec2.GetZ())
		) / denominator
	) * 180 / (/*PI*/4*atan(1));
}
double Vector3::Dot(Vector3 vec1, Vector3 vec2)
{
	return (
		(vec1.GetX() * vec2.GetX()) +
		(vec1.GetY() * vec2.GetY()) +
		(vec1.GetZ() * vec2.GetZ())
	);
}
Vector3 Vector3::Cross(Vector3 vec1, Vector3 vec2)
{
	return Vector3(
		vec1.GetY() * vec2.GetZ() - vec1.GetZ() * vec2.GetY(),
		vec1.GetZ() * vec2.GetX() - vec1.GetX() * vec2.GetZ(),
		vec1.GetX() * vec2.GetY() - vec1.GetY() * vec2.GetX()
	);
}

// Operators
Vector3 Vector3::operator+(Vector3 rh)
{
	return Vector3(
		GetX() + rh.GetX(),
		GetY() + rh.GetY(),
		GetZ() + rh.GetZ()
	);
}
Vector3 Vector3::operator+(double rh)
{
	return *this + Vector3(rh, rh, rh);
}
Vector3 Vector3::operator+=(Vector3 rh)
{
	return *this = *this + rh;
}
Vector3 Vector3::operator+=(double rh)
{
	return *this = *this + rh;
}

Vector3 Vector3::operator-(Vector3 rh)
{
	return Vector3(
		GetX() - rh.GetX(),
		GetY() - rh.GetY(),
		GetZ() - rh.GetZ()
	);
}
Vector3 Vector3::operator-(double rh)
{
	return *this - Vector3(rh, rh, rh);
}
Vector3 Vector3::operator-=(Vector3 rh)
{
	return *this = *this - rh;
}
Vector3 Vector3::operator-=(double rh)
{
	return *this = *this - rh;
}

Vector3 Vector3::operator*(Vector3 rh)
{
	return Vector3(
		GetX() * rh.GetX(),
		GetY() * rh.GetY(),
		GetZ() * rh.GetZ()
	);
}
Vector3 Vector3::operator*(double rh)
{
	return *this * Vector3(rh, rh, rh);
}
Vector3 Vector3::operator*=(Vector3 rh)
{
	return *this = *this * rh;
}
Vector3 Vector3::operator*=(double rh)
{
	return *this = *this * rh;
}

Vector3 Vector3::operator/(Vector3 rh)
{
	return Vector3(
		GetX() / rh.GetX(),
		GetY() / rh.GetY(),
		GetZ() / rh.GetZ()
	);
}
Vector3 Vector3::operator/(double rh)
{
	return *this / Vector3(rh, rh, rh);
}
Vector3 Vector3::operator/=(Vector3 rh)
{
	return *this = *this / rh;
}
Vector3 Vector3::operator/=(double rh)
{
	return *this = *this / rh;
}

bool Vector3::operator==(Vector3 rh)
{
	return (
		GetX() == rh.GetX()
		&& GetY() == rh.GetY()
		&& GetZ() == rh.GetZ()
	);
}
bool Vector3::operator!=(Vector3 rh)
{
	return !(*this == rh);
}

Vector3::operator std::string()
{
	std::ostringstream strX;
	std::ostringstream strY;
	std::ostringstream strZ;
	strX << GetX();
	strY << GetY();
	strZ << GetZ();

	std::string retStr = "Vector3(" +
		strX.str() + "f, " +
		strY.str() + "f, " +
		strZ.str() + "f)";
	return retStr;
}