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
		double GetX();
		double GetY();
		double GetZ();

	// Methods
	public:
		double Length();
		Vector3 Normalize();
		Vector3 Normalized();
		double Distance(Vector3);
		double Angle(Vector3);
		double Dot(Vector3);
		Vector3 Cross(Vector3);

	// Static methods
	public:
		static double Distance(Vector3, Vector3);
		static double Angle(Vector3, Vector3);
		static double Dot(Vector3, Vector3);
		static Vector3 Cross(Vector3, Vector3);

	// Operators
	public:
		Vector3 operator+(Vector3);
		Vector3 operator+(double);
		Vector3 operator+=(Vector3);
		Vector3 operator+=(double);

		Vector3 operator-(Vector3);
		Vector3 operator-(double);
		Vector3 operator-=(Vector3);
		Vector3 operator-=(double);

		Vector3 operator*(Vector3);
		Vector3 operator*(double);
		Vector3 operator*=(Vector3);
		Vector3 operator*=(double);

		Vector3 operator/(Vector3);
		Vector3 operator/(double);
		Vector3 operator/=(Vector3);
		Vector3 operator/=(double);

		bool operator==(Vector3);
		bool operator!=(Vector3);

		operator std::string();
};