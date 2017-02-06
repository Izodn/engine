#pragma once

#include <string>

class Vector3
{
	// Members
	protected:
		double m_X;
		double m_Y;
		double m_Z;

	// Constructors
	public:
		Vector3(double, double, double);
		Vector3();

	// Getters/Setters
	public:
		Vector3 SetX(double);
		Vector3 SetY(double);
		Vector3 SetZ(double);
		double GetX() const;
		double GetY() const;
		double GetZ() const;

	// Default Vectors
	public:
		static Vector3 Forward();
		static Vector3 Up();
		static Vector3 Right();

	// Static methods
	public:
		static double Length(const Vector3&);
		static Vector3 Normalized(const Vector3&);
		static Vector3 Normalize(Vector3);
		static double Distance(const Vector3&, const Vector3&);
		static double Angle(const Vector3&, const Vector3&);
		static double Dot(const Vector3&, const Vector3&);
		static Vector3 Cross(const Vector3&, const Vector3&);

	// Methods
	public:
		double Length() const;
		Vector3 Normalized() const;
		Vector3 Normalize();
		double Distance(const Vector3&) const;
		double Angle(const Vector3&) const;
		double Dot(const Vector3&) const;
		Vector3 Cross(const Vector3&) const;

	// Operators
	public:
		Vector3 operator=(const Vector3&);

		Vector3 operator+(const Vector3&) const;
		Vector3 operator+(double) const;
		Vector3 operator+=(const Vector3&);
		Vector3 operator+=(double);

		Vector3 operator-(const Vector3&) const;
		Vector3 operator-(double) const;
		Vector3 operator-=(const Vector3&);
		Vector3 operator-=(double);

		Vector3 operator*(const Vector3&) const;
		Vector3 operator*(double) const;
		Vector3 operator*=(const Vector3&);
		Vector3 operator*=(double);

		Vector3 operator/(const Vector3&) const;
		Vector3 operator/(double) const;
		Vector3 operator/=(const Vector3&);
		Vector3 operator/=(double);

		bool operator==(const Vector3&) const;
		bool operator!=(const Vector3&) const;

		operator std::string() const;
};