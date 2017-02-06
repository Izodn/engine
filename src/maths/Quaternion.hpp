#pragma once

#include "Vector3.hpp"

class Quaternion
{
	// Members
	protected:
		double m_X;
		double m_Y;
		double m_Z;
		double m_W;

	// Constructors
	public:
		Quaternion();
		Quaternion(double);
		Quaternion(const Vector3&, double);
		Quaternion(const Vector3&);
		Quaternion(double, double, double, double);

	// Getters/Setters
	public:
		Quaternion SetX(double);
		Quaternion SetY(double);
		Quaternion SetZ(double);
		Quaternion SetW(double);
		double GetX() const;
		double GetY() const;
		double GetZ() const;
		double GetW() const;

	// Static methods
	public:
		static Quaternion Identity();
		static double Norm(const Quaternion&);
		static double Length(const Quaternion&);
		static Quaternion Normalized(const Quaternion&);
		static Quaternion Normalize(Quaternion);
		static Quaternion FromAxisAngle(const Vector3&, double);
		static Quaternion FromEulerAngles(const Vector3&);
		static Vector3 ToEulerAngles(const Quaternion&);
		static Vector3 GetAxis(const Quaternion&);
		static Quaternion Rotation(const Vector3&, const Vector3&);
		static Quaternion Rotation(double, const Vector3&);
		static Vector3 Rotate(const Quaternion&, const Vector3&);
		static double Dot(const Quaternion&, const Quaternion&);
		static Quaternion LookAt(const Vector3&, const Vector3&);
		static double Angle(const Quaternion&);

	// Methods
	public:
		double Norm() const;
		double Length() const;
		Quaternion Normalized() const;
		Quaternion Normalize();
		Vector3 ToEulerAngles() const;
		Vector3 GetAxis() const;
		Vector3 Rotate(const Vector3&) const;
		double Dot(const Quaternion&) const;
		double Angle() const;

	// Operators
	public:
		Quaternion operator=(const Quaternion&);

		Quaternion operator+(const Quaternion&) const;
		Quaternion operator+=(const Quaternion&);

		Quaternion operator-(const Quaternion&) const;
		Quaternion operator-=(const Quaternion&);

		Quaternion operator*(const Quaternion&) const;
		Quaternion operator*=(const Quaternion&);

		Quaternion operator*(double) const;
		Quaternion operator*=(double);

		Quaternion operator/(double) const;
		Quaternion operator/=(double);

		bool operator==(const Quaternion&) const;
		bool operator!=(const Quaternion&) const;

		operator std::string() const;
};