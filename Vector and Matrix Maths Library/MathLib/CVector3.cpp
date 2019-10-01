#include "CVector3.h"
#include "CVector2.h"
#include "CMatrix3.h"

#include <cmath>

const float CVector3::operator[](const int a_i) const
{
	float fCoordinate = m_afCoordinates[a_i];
	return fCoordinate;
}

/// <summary>
/// Creates a new vector 3 with the values of the previous vector 3 multiplied by an inputted float
/// </summary>
/// <returns> Vector 3 which has been multiplied </returns>
const CVector3 CVector3::operator*(const float a_other) const
{
	return CVector3(m_afCoordinates[0] * a_other,
		m_afCoordinates[1] * a_other,
		m_afCoordinates[2] * a_other);
}

/// <summary>
/// Sets each instance of the vector 3 to its value multiplied by an inputted float
/// </summary>
/// <returns></returns>
void CVector3::operator*=(const float a_other)
{
	for (int i = 0; i < 3; i++)
	{
		m_afCoordinates[i] *= a_other;
	}
}

/// <summary>
/// Creates a new vector 3 with the values of the previous vector 3 multiplied by the values of an inputted vector 3
/// </summary>
/// <returns> Vector 3 which has been multiplied </returns>
const CVector3 CVector3::operator*(const CVector3 & a_other) const
{
	return CVector3(m_afCoordinates[0] * a_other.m_afCoordinates[0],
		m_afCoordinates[1] * a_other.m_afCoordinates[1],
		m_afCoordinates[2] * a_other.m_afCoordinates[2]);
}

/// <summary>
/// Sets each instance of the vector 3 to its value multiplied by the values of an inputted vector 3
/// </summary>
/// <returns></returns>
void CVector3::operator*=(const CVector3 & a_other)
{
	for (int i = 0; i < 3; i++)
	{
		m_afCoordinates[i] *= a_other.m_afCoordinates[i];
	}
}

/// <summary>
/// Creates a new vector 3 with the values of the previous vector 3 divided by the values of an inputted vector 3
/// </summary>
/// <returns> Vector 3 which has been divided </returns>
const CVector3 CVector3::operator/(const CVector3 & a_other) const
{
	return CVector3(m_afCoordinates[0] / a_other.m_afCoordinates[0],
		m_afCoordinates[1] / a_other.m_afCoordinates[1],
		m_afCoordinates[2] / a_other.m_afCoordinates[2]);
}

/// <summary>
/// Sets each instance of the vector 3 to its value divided by the values of an inputted vector 3
/// </summary>
/// <returns></returns>
void CVector3::operator/=(const CVector3 & a_other)
{
	for (int i = 0; i < 3; i++)
	{
		m_afCoordinates[i] /= a_other.m_afCoordinates[i];
	}
}

/// <summary>
/// Creates a new vector 3 with the values of the previous vector 3 divided by an inputted float
/// </summary>
/// <returns> Vector 3 which has been divided </returns>
const CVector3 CVector3::operator/(const float a_other) const
{
	return CVector3(m_afCoordinates[0] / a_other,
		m_afCoordinates[1] / a_other,
		m_afCoordinates[2] / a_other);
}

/// <summary>
/// Sets each instance of the vector 3 to its value divided by an inputted float
/// </summary>
/// <returns></returns>
void CVector3::operator/=(const float a_other)
{
	for (int i = 0; i < 3; i++)
	{
		m_afCoordinates[i] /= a_other;
	}
}

/// <summary>
/// Creates a new vector 3 with the values of the previous vector 3 added to the values of an inputted vector 3
/// </summary>
/// <returns> Vector 3 which has been added to another </returns>
const CVector3 CVector3::operator+(const CVector3 &a_other) const
{
	return CVector3(m_afCoordinates[0] + a_other.m_afCoordinates[0],
		m_afCoordinates[1] + a_other.m_afCoordinates[1],
		m_afCoordinates[2] + a_other.m_afCoordinates[2]);
}

/// <summary>
/// Sets each instance of the vector 3 to its value added to the values of an inputted vector 3
/// </summary>
/// <returns></returns>
void CVector3::operator+=(const CVector3 &a_other)
{
	for (int i = 0; i < 3; i++)
	{
		m_afCoordinates[i] += a_other.m_afCoordinates[i];
	}
}

/// <summary>
/// Creates a new vector 3 with the values of the previous vector 3 subtracted by the values of an inputted vector 3
/// </summary>
/// <returns> Vector 3 which has been subtracted by another </returns>
const CVector3 CVector3::operator-(const CVector3 &a_other) const
{
	return CVector3(m_afCoordinates[0] - a_other.m_afCoordinates[0],
		m_afCoordinates[1] - a_other.m_afCoordinates[1],
		m_afCoordinates[2] - a_other.m_afCoordinates[2]);
}

/// <summary>
/// Sets each instance of the vector 3 to its value subtracted by the values of an inputted vector 3
/// </summary>
/// <returns></returns>
void CVector3::operator-=(const CVector3 &a_other)
{
	for (int i = 0; i < 3; i++)
	{
		m_afCoordinates[i] -= a_other.m_afCoordinates[i];
	}
}

/// <summary>
/// Finds the magnitude of the vector 3
/// </summary>
/// <returns> The magnitude of the vector 3 </returns>
const float CVector3::magnitude() const
{
	float fAnswer = sqrt((m_afCoordinates[0] * m_afCoordinates[0]) +
		(m_afCoordinates[1] * m_afCoordinates[1]) +
		(m_afCoordinates[2] * m_afCoordinates[2]));
	return fAnswer;
}

/// <summary>
/// Finds the squared magnitude of the vector 3
/// </summary>
/// <returns> The squared magnitude of the vector 3 </returns>
const float CVector3::magnitudeSq() const
{
	float fAnswer = (m_afCoordinates[0] * m_afCoordinates[0]) +
		(m_afCoordinates[1] * m_afCoordinates[1]) +
		(m_afCoordinates[2] * m_afCoordinates[2]);
	return fAnswer;
}

/// <summary>
/// Finds the distance between the vector 3 and another in vector 3
/// </summary>
/// <returns> The distance between two vector 3 </returns>
const float CVector3::distance(const CVector3 &a_other) const
{
	float fDistance = sqrt(
		((m_afCoordinates[0] - a_other[0]) * (m_afCoordinates[0] - a_other[0])) +
		((m_afCoordinates[1] - a_other[1]) * (m_afCoordinates[1] - a_other[1])) +
		((m_afCoordinates[2] - a_other[2]) * (m_afCoordinates[2] - a_other[2])));
	return fDistance;
}

/// <summary>
/// Finds the squared distance between the vector 3 and an inputted vector 3
/// </summary>
/// <returns> The squared distance between two vector 3 </returns>
const float CVector3::distanceSq(const CVector3 &a_other) const
{
	float fDistance =
		((m_afCoordinates[0] - a_other[0]) * (m_afCoordinates[0] - a_other[0])) +
		((m_afCoordinates[1] - a_other[1]) * (m_afCoordinates[1] - a_other[1])) +
		((m_afCoordinates[2] - a_other[2]) * (m_afCoordinates[2] - a_other[2]));
	return fDistance;
}

/// <summary>
/// Finds the dot product of the vector 3 and an inputted vector 3
/// </summary>
/// <returns> The dot product of two vector 3 </returns>
const float CVector3::dotProduct(const CVector3 &a_other) const
{
	float fDot = ((m_afCoordinates[0] * a_other[0]) +
		(m_afCoordinates[1] * a_other[1]) +
		(m_afCoordinates[2] * a_other[2]));
	return fDot;
}

/// <summary>
/// Finds the cross product of the vector 3 and an inputted vector 3
/// </summary>
/// <returns> Vector 3 which is the cross product of the two vector 3 </returns>
const CVector3 CVector3::crossProduct(const CVector3 &a_other) const
{
	float afNewVector3[3] = {
		(m_afCoordinates[1] * a_other[2]) - (a_other[1] * m_afCoordinates[2]),
		(m_afCoordinates[2] * a_other[0]) - (a_other[2] * m_afCoordinates[0]),
		(m_afCoordinates[0] * a_other[1]) - (a_other[0] * m_afCoordinates[1])
	};
	return CVector3(afNewVector3[0], afNewVector3[1], afNewVector3[2]);
}

/// <summary>
/// Normalises the vector 3 by setting each instance of the vector to be divided by the magnitude
/// </summary>
/// <returns></returns> 
void CVector3::normalise()
{
	float fMagnitude = sqrt((m_afCoordinates[0] * m_afCoordinates[0]) +
		(m_afCoordinates[1] * m_afCoordinates[1]) +
		(m_afCoordinates[2] * m_afCoordinates[2]));

	for (int i = 0; i < 3; i++)
	{
		m_afCoordinates[i] /= fMagnitude;
	}
}

/// <summary>
/// Creates a new vector 3 which is normalised
/// </summary>
/// <returns> Vector 3 which has been normalised </returns> 
const CVector3 CVector3::normalised() const
{
	float fMagnitude = sqrt((m_afCoordinates[0] * m_afCoordinates[0]) +
		(m_afCoordinates[1] * m_afCoordinates[1]) +
		(m_afCoordinates[2] * m_afCoordinates[2]));

	return CVector3(m_afCoordinates[0] / fMagnitude,
		m_afCoordinates[1] / fMagnitude,
		m_afCoordinates[2] / fMagnitude);
}

/// <summary>
/// Sets each instance of the vector 3 to be the value of an inputted float
/// </summary>
/// <returns></returns> 
CVector3::CVector3(float a_x, float a_y, float a_z)
{
	m_afCoordinates[0] = a_x;
	m_afCoordinates[1] = a_y;
	m_afCoordinates[2] = a_z;
}

CVector3::CVector3(CVector2 a_other)
{
}

/// <summary>
/// Finds the address of the pointer to this vector 3
/// </summary>
/// <returns> The address of the pointer </returns> 
const float* CVector3::GetPointer() const
{
	return (float*)this;
}

CVector3::CVector3()
{
}


CVector3::~CVector3()
{
}

