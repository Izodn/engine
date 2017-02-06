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
double Vector3::GetX() const
{
	return m_X;
}
double Vector3::GetY() const
{
	return m_Y;
}
double Vector3::GetZ() const
{
	return m_Z;
}

// Default Vectors
Vector3 Vector3::Forward()
{
	return Vector3(0.0f, 0.0f, 1.0f);
}
Vector3 Vector3::Up()
{
	return Vector3(0.0f, 1.0f, 0.0f);
}
Vector3 Vector3::Right()
{
	return Vector3(1.0f, 0.0f, 0.0f);
}

// Static methods
double Vector3::Length(const Vector3& vec)
{
	return sqrt(
		pow(vec.GetX(), 2.0f)
		+ pow(vec.GetY(), 2.0f)
		+ pow(vec.GetZ(), 2.0f)
	);
}
Vector3 Vector3::Normalized(const Vector3& vec)
{
	return vec / vec.Length();
}
Vector3 Vector3::Normalize(Vector3 vec)
{
	return vec = Normalized(vec);
}
double Vector3::Distance(const Vector3& vec1, const Vector3& vec2)
{
	return (vec1 - vec2).Length();
}
double Vector3::Angle(const Vector3& vec1, const Vector3& vec2)
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
double Vector3::Dot(const Vector3& vec1, const Vector3& vec2)
{
	return (
		(vec1.GetX() * vec2.GetX()) +
		(vec1.GetY() * vec2.GetY()) +
		(vec1.GetZ() * vec2.GetZ())
	);
}
Vector3 Vector3::Cross(const Vector3& vec1, const Vector3& vec2)
{
	return Vector3(
		vec1.GetY() * vec2.GetZ() - vec1.GetZ() * vec2.GetY(),
		vec1.GetZ() * vec2.GetX() - vec1.GetX() * vec2.GetZ(),
		vec1.GetX() * vec2.GetY() - vec1.GetY() * vec2.GetX()
	);
}

// Methods
double Vector3::Length() const
{
	return Length(*this);
}
Vector3 Vector3::Normalize()
{
	return Normalize(*this);
}
Vector3 Vector3::Normalized() const
{
	return Normalized(*this);
}
double Vector3::Distance(const Vector3& target) const
{
	return Distance(*this, target);
}
double Vector3::Angle(const Vector3& target) const
{
	return Angle(*this, target);
}
double Vector3::Dot(const Vector3& target) const
{
	return Dot(*this, target);
}
Vector3 Vector3::Cross(const Vector3& target) const
{
	return Cross(*this, target);
}

// Operators
Vector3 Vector3::operator=(const Vector3& rh)
{
	m_X = rh.GetX();
	m_Y = rh.GetY();
	m_Z = rh.GetZ();
	return *this;
}

Vector3 Vector3::operator+(const Vector3& rh) const
{
	return Vector3(
		m_X + rh.GetX(),
		m_Y + rh.GetY(),
		m_Z + rh.GetZ()
	);
}
Vector3 Vector3::operator+(double rh) const
{
	return *this + Vector3(rh, rh, rh);
}
Vector3 Vector3::operator+=(const Vector3& rh)
{
	return *this = *this + rh;
}
Vector3 Vector3::operator+=(double rh)
{
	return *this = *this + rh;
}

Vector3 Vector3::operator-(const Vector3& rh) const
{
	return Vector3(
		m_X - rh.GetX(),
		m_Y - rh.GetY(),
		m_Z - rh.GetZ()
	);
}
Vector3 Vector3::operator-(double rh) const
{
	return *this - Vector3(rh, rh, rh);
}
Vector3 Vector3::operator-=(const Vector3& rh)
{
	return *this = *this - rh;
}
Vector3 Vector3::operator-=(double rh)
{
	return *this = *this - rh;
}

Vector3 Vector3::operator*(const Vector3& rh) const
{
	return Vector3(
		m_X * rh.GetX(),
		m_Y * rh.GetY(),
		m_Z * rh.GetZ()
	);
}
Vector3 Vector3::operator*(double rh) const
{
	return *this * Vector3(rh, rh, rh);
}
Vector3 Vector3::operator*=(const Vector3& rh)
{
	return *this = *this * rh;
}
Vector3 Vector3::operator*=(double rh)
{
	return *this = *this * rh;
}

Vector3 Vector3::operator/(const Vector3& rh) const
{
	return Vector3(
		m_X / rh.GetX(),
		m_Y / rh.GetY(),
		m_Z / rh.GetZ()
	);
}
Vector3 Vector3::operator/(double rh) const
{
	return *this / Vector3(rh, rh, rh);
}
Vector3 Vector3::operator/=(const Vector3& rh)
{
	return *this = *this / rh;
}
Vector3 Vector3::operator/=(double rh)
{
	return *this = *this / rh;
}

bool Vector3::operator==(const Vector3& rh) const
{
	return (
		m_X == rh.GetX()
		&& m_Y == rh.GetY()
		&& m_Z == rh.GetZ()
	);
}
bool Vector3::operator!=(const Vector3& rh) const
{
	return !(*this == rh);
}

Vector3::operator std::string() const
{
	std::ostringstream strX;
	std::ostringstream strY;
	std::ostringstream strZ;
	strX << m_X;
	strY << m_Y;
	strZ << m_Z;

	std::string retStr = "Vector3(" +
		strX.str() + "f, " +
		strY.str() + "f, " +
		strZ.str() + "f)";
	return retStr;
}