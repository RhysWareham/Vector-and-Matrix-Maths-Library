#include "CVector2.h"

#include <cmath>

CVector2::CVector2()
{
}

/// <summary>
/// Sets each instance of the vector 2 to be the value of an inputted float
/// </summary>
/// <returns></returns> 
CVector2::CVector2(const float a_x, const float a_y)
{
	m_afCoordinates[0] = a_x;
	m_afCoordinates[1] = a_y;
}

CVector2::~CVector2()
{
}

/// <summary>
/// Finds the address of the pointer to this vector 2
/// </summary>
/// <returns> The address of the pointer </returns> 
const float* CVector2::GetPointer() const
{
	return(float*)this;
}

/// <summary>
/// Finds the value of a specific instance of the vector 2
/// </summary>
/// <returns> Float </returns> 
const float CVector2::operator[](const int a_i) const
{
	float fCoordinate = m_afCoordinates[a_i];
	return fCoordinate;
}

/// <summary>
/// Creates a new vector 2 with the values of the previous vector 2 multiplied by an inputted float
/// </summary>
/// <returns> Vector 2 which has been multiplied </returns>
const CVector2 CVector2::operator*(const float a_other) const
{
	return CVector2(m_afCoordinates[0] * a_other, m_afCoordinates[1] * a_other);
}

/// <summary>
/// Sets each instance of the vector 2 to its value multiplied by an inputted float
/// </summary>
/// <returns></returns>
void CVector2::operator*=(const float a_other)
{
	m_afCoordinates[0] *= a_other;
	m_afCoordinates[1] *= a_other;
}

/// <summary>
/// Creates a new vector 2 with the values of the previous vector 2 multiplied by the values of an inputted vector 2
/// </summary>
/// <returns> Vector 2 which has been multiplied </returns>
const CVector2 CVector2::operator*(const CVector2 &a_other) const
{
	return CVector2(m_afCoordinates[0] * a_other.m_afCoordinates[0],
		m_afCoordinates[1] * a_other.m_afCoordinates[1]);
}

/// <summary>
/// Sets each instance of the vector 2 to its value multiplied by the values of an inputted vector 2
/// </summary>
/// <returns></returns>
void CVector2::operator*=(const CVector2 &a_other)
{
	m_afCoordinates[0] *= a_other.m_afCoordinates[0];
	m_afCoordinates[1] *= a_other.m_afCoordinates[1];
}

/// <summary>
/// Creates a new vector 2 with the values of the previous vector 2 divided by the values of an inputted vector 2
/// </summary>
/// <returns> Vector 2 which has been divided </returns>
const CVector2 CVector2::operator/(const CVector2 &a_other) const
{
	return CVector2(m_afCoordinates[0] / a_other.m_afCoordinates[0],
		m_afCoordinates[1] / a_other.m_afCoordinates[1]);
}

/// <summary>
/// Sets each instance of the vector 2 to its value divided by the values of an inputted vector 2
/// </summary>
/// <returns></returns>
void CVector2::operator/=(const CVector2 &a_other)
{
	m_afCoordinates[0] /= a_other.m_afCoordinates[0];
	m_afCoordinates[1] /= a_other.m_afCoordinates[1];
}

/// <summary>
/// Creates a new vector 2 with the values of the previous vector 2 divided by an inputted float
/// </summary>
/// <returns> Vector 2 which has been divided </returns>
const CVector2 CVector2::operator/(const float a_other) const
{
	return CVector2(m_afCoordinates[0] / a_other, m_afCoordinates[1] / a_other);
}

/// <summary>
/// Sets each instance of the vector 2 to its value divided by an inputted float
/// </summary>
/// <returns></returns>
void CVector2::operator/=(const float a_other)
{
	m_afCoordinates[0] /= a_other;
	m_afCoordinates[1] /= a_other;
}

/// <summary>
/// Creates a new vector 2 with the values of the previous vector 2 added to the values of an inputted vector 2
/// </summary>
/// <returns> Vector 2 which has been added to another </returns>
const CVector2 CVector2::operator+(const CVector2 &a_other) const
{
	return CVector2(m_afCoordinates[0] + a_other.m_afCoordinates[0],
		m_afCoordinates[1] + a_other.m_afCoordinates[1]);
}

/// <summary>
/// Sets each instance of the vector 2 to its value added to the values of an inputted vector 2
/// </summary>
/// <returns></returns>
void CVector2::operator+=(const CVector2 &a_other)
{
	m_afCoordinates[0] += a_other.m_afCoordinates[0];
	m_afCoordinates[1] += a_other.m_afCoordinates[1];
}

/// <summary>
/// Creates a new vector 2 with the values of the previous vector 2 subtracted by the values of an inputted vector 2
/// </summary>
/// <returns> Vector 2 which has been subtracted by another </returns>
const CVector2 CVector2::operator-(const CVector2 &a_other) const
{
	return CVector2(m_afCoordinates[0] - a_other.m_afCoordinates[0],
		m_afCoordinates[1] - a_other.m_afCoordinates[1]);
}

/// <summary>
/// Sets each instance of the vector 2 to its value subtracted by the values of an inputted vector 2
/// </summary>
/// <returns></returns>
void CVector2::operator-=(const CVector2 &a_other)
{
	m_afCoordinates[0] -= a_other.m_afCoordinates[0];
	m_afCoordinates[1] -= a_other.m_afCoordinates[1];
}

/// <summary>
/// Finds the magnitude of the vector 2
/// </summary>
/// <returns> The magnitude of the vector 2 </returns>
const float CVector2::magnitude() const
{
	float fAnswer = sqrt((m_afCoordinates[0] * m_afCoordinates[0]) +
		(m_afCoordinates[1] * m_afCoordinates[1]));
	return fAnswer;
}

/// <summary>
/// Finds the squared magnitude of the vector 2
/// </summary>
/// <returns> The squared magnitude of the vector 2 </returns>
const float CVector2::magnitudeSq() const
{
	float fAnswer = (m_afCoordinates[0] * m_afCoordinates[0]) +
		(m_afCoordinates[1] * m_afCoordinates[1]);
	return fAnswer;
}

/// <summary>
/// Finds the distance between the vector 2 and another in vector 2
/// </summary>
/// <returns> The distance between two vector 2 </returns>
const float CVector2::distance(const CVector2 &a_other) const
{
	float fDistance = sqrt(
		((m_afCoordinates[0] - a_other[0]) * (m_afCoordinates[0] - a_other[0])) +
		((m_afCoordinates[1] - a_other[1]) * (m_afCoordinates[1] - a_other[1])));
	return fDistance;
}

/// <summary>
/// Finds the squared distance between the vector 2 and an inputted vector 2
/// </summary>
/// <returns> The squared distance between two vector 2 </returns>
const float CVector2::distanceSq(const CVector2 &a_other) const
{
	float fDistance =
		((m_afCoordinates[0] - a_other[0]) * (m_afCoordinates[0] - a_other[0])) +
		((m_afCoordinates[1] - a_other[1]) * (m_afCoordinates[1] - a_other[1]));
	return fDistance;
}

/// <summary>
/// Finds the cross product of the vector 2 and an inputted vector 2
/// </summary>
/// <returns> Vector 2 which is the cross product of the two vector 2 </returns>
const CVector2 CVector2::crossProduct() const
{
	return CVector2(m_afCoordinates[1], -(m_afCoordinates[0]));
}

/// <summary>
/// Finds the dot product of the vector 2 and an inputted vector 2
/// </summary>
/// <returns> The dot product of two vector 2 </returns>
const float CVector2::dotProduct(const CVector2 &a_other) const
{
	float fDot = ((m_afCoordinates[0] * a_other[0]) +
		(m_afCoordinates[1] * a_other[1]));
	return fDot;
}

/// <summary>
/// Normalises the vector 2 by setting each instance of the vector to be divided by the magnitude
/// </summary>
/// <returns></returns> 
void CVector2::normalise()
{
	float fMagnitude = sqrt((m_afCoordinates[0] * m_afCoordinates[0]) +
		(m_afCoordinates[1] * m_afCoordinates[1]));

	m_afCoordinates[0] /= fMagnitude;
	m_afCoordinates[1] /= fMagnitude;
}

/// <summary>
/// Creates a new vector 2 which is normalised
/// </summary>
/// <returns> Vector 2 which has been normalised </returns> 
const CVector2 CVector2::normalised() const
{
	float fMagnitude = sqrt((m_afCoordinates[0] * m_afCoordinates[0]) +
		(m_afCoordinates[1] * m_afCoordinates[1]));

	return CVector2(m_afCoordinates[0] / fMagnitude,
		m_afCoordinates[1] / fMagnitude);
}

