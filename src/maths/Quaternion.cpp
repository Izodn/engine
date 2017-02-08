#include "Quaternion.hpp"
#include <cmath>
#include <sstream>

// Constructors
Quaternion::Quaternion()
{
	Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
}
Quaternion::Quaternion(double scalar)
{
	Quaternion(scalar, scalar, scalar, scalar);
}
Quaternion::Quaternion(const Vector3& vec, double w)
{
	Quaternion(vec.GetX(), vec.GetY(), vec.GetZ(), w);
}
Quaternion::Quaternion(const Vector3& vec)
{
	Quaternion quat = Quaternion::FromEulerAngles(vec);
	Quaternion(quat.GetX(), quat.GetY(), quat.GetZ(), quat.GetW());
}
Quaternion::Quaternion(double x, double y, double z, double w)
{
	m_X = x;
	m_Y = y;
	m_Z = z;
	m_W = w;
}

// Getters/Setters
Quaternion Quaternion::SetX(double x)
{
	m_X = x;
	return *this;
}
Quaternion Quaternion::SetY(double y)
{
	m_Y = y;
	return *this;
}
Quaternion Quaternion::SetZ(double z)
{
	m_Z = z;
	return *this;
}
Quaternion Quaternion::SetW(double w)
{
	m_W = w;
	return *this;
}
double Quaternion::GetX() const
{
	return m_X;
}
double Quaternion::GetY() const
{
	return m_Y;
}
double Quaternion::GetZ() const
{
	return m_Z;
}
double Quaternion::GetW() const
{
	return m_W;
}

// Static methods
Quaternion Quaternion::Identity()
{
	return Quaternion(
		0.0f,
		0.0f,
		0.0f,
		1.0f
	);
}
double Quaternion::Norm(const Quaternion& quat)
{
	return (
		(quat.GetX() * quat.GetX())
		+ (quat.GetY() * quat.GetY())
		+ (quat.GetZ() * quat.GetZ())
		+ (quat.GetW() * quat.GetW())
	);
}
double Quaternion::Length(const Quaternion& quat)
{
	return sqrt(Norm(quat));
}
Quaternion Quaternion::Normalized(const Quaternion& quat)
{
	return quat * (1.0f / Norm(quat));
}
Quaternion Quaternion::Normalize(Quaternion quat)
{
	return quat = Normalized(quat);
}
Quaternion Quaternion::FromAxisAngle(const Vector3& axis, double angle)
{
	double halfAngle = angle / 2.0f;
	double s = sin(halfAngle);
	return Quaternion(
		axis.GetX() * s,
		axis.GetY() * s,
		axis.GetZ() * s,
		cos(halfAngle)
	);
}
Quaternion Quaternion::FromEulerAngles(const Vector3& vec)
{
	double vX, vY, vZ, t0, t1, t2, t3, t4, t5;
	vX = vec.GetX();
	vY = vec.GetY();
	vZ = vec.GetZ();

	t0 = cos(vX * 0.5f);
	t1 = sin(vX * 0.5f);
	t2 = cos(vY * 0.5f);
	t3 = sin(vY * 0.5f);
	t4 = cos(vZ * 0.5f);
	t5 = sin(vZ * 0.5f);

	return Quaternion(
		/*X*/ t1 * t2 * t4 + t0 * t3 * t5,
		/*Y*/ t0 * t3 * t4 - t1 * t2 * t5,
		/*Z*/ t0 * t2 * t5 + t1 * t3 * t4,
		/*W*/ t0 * t2 * t4 - t1 * t3 * t5
	);
}
Vector3 Quaternion::ToEulerAngles(const Quaternion& quat)
{
	double qX, qY, qZ, qW, t0, t1, t2, t3, t4;
	qX = quat.GetX();
	qY = quat.GetY();
	qZ = quat.GetZ();
	qW = quat.GetW();

	t0 = 2.0f         * ((qW * qX) - (qY * qZ)) ; // Pitch
	t1 = 1.0f - (2.0f * ((qX * qX) + (qY * qY))); // Pitch
	t2 = 2.0f         * ((qW * qY) + (qZ * qX)) ; // Yaw
	t3 = 2.0f         * ((qW * qZ) - (qX * qY)) ; // Roll
	t4 = 1.0f - (2.0f * ((qY * qY) + (qZ * qZ))); // Roll

	// Gimble lock check
	t2 = t2 >  1.0f ?  1.0f : t2;
	t2 = t2 < -1.0f ? -1.0f : t2;

	return Vector3(
		/*Pitch*/ atan2(t0, t1),
		/*Yaw*/ asin(t2),
		/*Roll*/ atan2(t3, t4)
	);
}
Vector3 Quaternion::GetAxis(const Quaternion& quat)
{
	double x1 = 1.0f - quat.GetW() * quat.GetW();
	double x2 = x1 * x1;

	// Devide by 0 check
	if (x2 == 0.0f) {
		return Vector3::Forward();
	}

	return Vector3(quat.GetX(), quat.GetY(), quat.GetZ()) / x2;
}
Quaternion Quaternion::Rotation(const Vector3& uVec1, const Vector3& uVec2)
{
	double cosHalfAngleX2 = sqrt(
		(2.0f * (1.0f + uVec1.Dot(uVec2)))
	);
	double recipCosHalfAngleX2 = (1.0f / cosHalfAngleX2);
	return Quaternion(
		(uVec1.Cross(uVec2) * recipCosHalfAngleX2),
		(cosHalfAngleX2 * 0.5f)
	);
}
Quaternion Quaternion::Rotation(double radians, const Vector3& uVec)
{
	double angle = radians * 0.5f;
	return Quaternion((uVec * sin(angle)), cos(angle));
}
Vector3 Quaternion::Rotate(const Quaternion& quat, const Vector3& vec)
{
	double qX = quat.GetX();
	double qY = quat.GetY();
	double qZ = quat.GetZ();
	double qW = quat.GetW();
	double vX = vec.GetX();
	double vY = vec.GetY();
	double vZ = vec.GetZ();

	double x = (((qW * vX) + (qY * vZ)) - (qZ * vY));
	double y = (((qW * vY) + (qZ * vX)) - (qX * vZ));
	double z = (((qW * vZ) + (qX * vY)) - (qY * vX));
	double w = (((qX * vX) + (qY * vY)) + (qZ * vZ));

	return Vector3(
		((((w * qX) + (x * qW)) - (y * qZ))+ (z * qY)),
		((((w * qY) + (y * qW)) - (z * qX))+ (x * qZ)),
		((((w * qZ) + (z * qW)) - (x * qY))+ (y * qX))
	);
}
Quaternion Quaternion::Rotate(const Quaternion& quat, const Vector3& axis, double angle)
{
	return quat * Quaternion::FromAxisAngle(axis, angle);
}
double Quaternion::Dot(const Quaternion& quat1, const Quaternion& quat2)
{
	return (
		(quat1.GetX() * quat2.GetX())
		+ (quat1.GetY() * quat2.GetY())
		+ (quat1.GetZ() * quat2.GetZ())
		+ (quat1.GetW() * quat2.GetW())
	);
}
Quaternion Quaternion::LookAt(const Vector3& origin, const Vector3& target)
{
	Vector3 forward = (target - origin).Normalized();

	double dot = Vector3::Forward().Dot(forward);

	if (abs(dot - (-1.0f)) < 0.000001f) {
		return Quaternion(
			Vector3::Up(),
			/*PI*/4*atan(1)
		);
	}
	if (abs(dot - (1.0f)) < 0.000001f) {
		return Quaternion::Identity();
	}

	return FromAxisAngle(
		Vector3::Forward().Cross(forward).Normalized(),
		acos(dot)
	);
}
double Quaternion::Angle(const Quaternion& quat)
{
	return 2 * acos(quat.GetW());
}

// Methods
double Quaternion::Norm() const
{
	return Norm(*this);
}
double Quaternion::Length() const
{
	return Length(*this);
}
Quaternion Quaternion::Normalized() const
{
	return Normalized(*this);
}
Quaternion Quaternion::Normalize()
{
	return Normalize(*this);
}
Vector3 Quaternion::ToEulerAngles() const
{
	return ToEulerAngles(*this);
}
Vector3 Quaternion::GetAxis() const
{
	return GetAxis(*this);
}
Vector3 Quaternion::Rotate(const Vector3& vec) const
{
	return Rotate(*this, vec);
}
Quaternion Quaternion::Rotate(const Vector3& axis, double angle)
{
	return *this = Quaternion::Rotate(*this, axis, angle);
}
double Quaternion::Dot(const Quaternion& target) const
{
	return Dot(*this, target);
}
double Quaternion::Angle() const
{
	return Quaternion::Angle(*this);
}

// Operators
Quaternion Quaternion::operator=(const Quaternion& rh)
{
	m_X = rh.GetX();
	m_Y = rh.GetY();
	m_Z = rh.GetZ();
	m_W = rh.GetW();
	return *this;
}

Quaternion Quaternion::operator+(const Quaternion& rh) const
{
	return Quaternion(
		m_X + rh.GetX(),
		m_Y + rh.GetY(),
		m_Z + rh.GetZ(),
		m_W + rh.GetW()
	);
}
Quaternion Quaternion::operator+=(const Quaternion& rh)
{
	return *this = *this + rh;
}

Quaternion Quaternion::operator-(const Quaternion& rh) const
{
	return Quaternion(
		m_X - rh.GetX(),
		m_Y - rh.GetY(),
		m_Z - rh.GetZ(),
		m_W - rh.GetW()
	);
}
Quaternion Quaternion::operator-=(const Quaternion& rh)
{
	return *this = *this - rh;
}

Quaternion Quaternion::operator*(const Quaternion& rh) const
{
	double qX = rh.GetX();
	double qY = rh.GetY();
	double qZ = rh.GetZ();
	double qW = rh.GetW();
	return Normalize(
		Quaternion(
			(((m_W * qX) + (m_X * qW)) + (m_Y * qZ)) - (m_Z * qY),
			(((m_W * qY) + (m_Y * qW)) + (m_Z * qX)) - (m_X * qZ),
			(((m_W * qZ) + (m_Z * qW)) + (m_X * qY)) - (m_Y * qX),
			(((m_W * qW) - (m_X * qX)) - (m_Y * qY)) - (m_Z * qZ)
		)
	);
}
Quaternion Quaternion::operator*=(const Quaternion& rh)
{
	return *this = *this * rh;
}

Quaternion Quaternion::operator*(double rh) const
{
	return Quaternion(
		rh * GetX(),
		rh * GetY(),
		rh * GetZ(),
		rh * GetW()
	);
}
Quaternion Quaternion::operator*=(double rh)
{
	return *this = *this * rh;
}

Quaternion Quaternion::operator/(double rh) const
{
	return Quaternion(
		rh / GetX(),
		rh / GetY(),
		rh / GetZ(),
		rh / GetW()
	);
}
Quaternion Quaternion::operator/=(double rh)
{
	return *this = *this / rh;
}

bool Quaternion::operator==(const Quaternion& rh) const
{
	return (
		m_X == rh.GetX()
		&& m_Y == rh.GetY()
		&& m_Z == rh.GetZ()
		&& m_W == rh.GetW()
	);
}
bool Quaternion::operator!=(const Quaternion& rh) const
{
	return !(*this == rh);
}

Quaternion::operator std::string() const
{
	std::ostringstream strX;
	std::ostringstream strY;
	std::ostringstream strZ;
	std::ostringstream strW;
	strX << m_X;
	strY << m_Y;
	strZ << m_Z;
	strW << m_W;

	std::string retStr = "Quaternion(" +
		strX.str() + "f, " +
		strY.str() + "f, " +
		strZ.str() + "f, " +
		strW.str() + "f)";
	return retStr;
}