#include "CVector3.h"
#include "CVector2.h"
#include "CVector4.h"
#include "CMatrix4.h"

#include <cmath>

/// <summary>
/// Finds the value of a specific instance of the vector 4
/// </summary>
/// <returns> Float </returns> 
const float CVector4::operator[](const int a_i) const
{
	float fCoordinate = m_afCoordinates[a_i];
	return fCoordinate;
}

/// <summary>
/// Creates a new vector 4 with the values of the previous vector 4 multiplied by an inputted float
/// </summary>
/// <returns> Vector 4 which has been multiplied </returns>
const CVector4 CVector4::operator*(const float a_other) const
{
	return CVector4(m_afCoordinates[0] * a_other,
		m_afCoordinates[1] * a_other,
		m_afCoordinates[2] * a_other,
		m_afCoordinates[3] * a_other);
}

/// <summary>
/// Sets each instance of the vector 4 to its value multiplied by an inputted float
/// </summary>
/// <returns></returns>
void CVector4::operator*=(const float a_other)
{
	for (int i = 0; i < 4; i++)
	{
		m_afCoordinates[i] *= a_other;
	}
}

/// <summary>
/// Creates a new vector 4 with the values of the previous vector 4 multiplied by the values of an inputted vector 4
/// </summary>
/// <returns> Vector 4 which has been multiplied </returns>
const CVector4 CVector4::operator*(const CVector4 & a_other) const
{
	return CVector4(m_afCoordinates[0] * a_other.m_afCoordinates[0],
		m_afCoordinates[1] * a_other.m_afCoordinates[1],
		m_afCoordinates[2] * a_other.m_afCoordinates[2],
		m_afCoordinates[3] * a_other.m_afCoordinates[3]);
}

/// <summary>
/// Sets each instance of the vector 4 to its value multiplied by the values of an inputted vector 4
/// </summary>
/// <returns></returns>
void CVector4::operator*=(const CVector4 & a_other)
{
	for (int i = 0; i < 4; i++)
	{
		m_afCoordinates[i] *= a_other.m_afCoordinates[i];
	}
}

/// <summary>
/// Creates a new vector 4 with the values of the previous vector 4 divided by the values of an inputted vector 4
/// </summary>
/// <returns> Vector 4 which has been divided </returns>
const CVector4 CVector4::operator/(const CVector4 & a_other) const
{
	return CVector4(m_afCoordinates[0] / a_other.m_afCoordinates[0],
		m_afCoordinates[1] / a_other.m_afCoordinates[1],
		m_afCoordinates[2] / a_other.m_afCoordinates[2],
		m_afCoordinates[3] / a_other.m_afCoordinates[3]);
}

/// <summary>
/// Sets each instance of the vector 4 to its value divided by the values of an inputted vector 4
/// </summary>
/// <returns></returns>
void CVector4::operator/=(const CVector4 & a_other)
{
	for (int i = 0; i < 4; i++)
	{
		m_afCoordinates[i] /= a_other.m_afCoordinates[i];
	}
}

/// <summary>
/// Creates a new vector 4 with the values of the previous vector 4 divided by an inputted float
/// </summary>
/// <returns> Vector 4 which has been divided </returns>
const CVector4 CVector4::operator/(const float a_other) const
{
	return CVector4(m_afCoordinates[0] / a_other,
		m_afCoordinates[1] / a_other,
		m_afCoordinates[2] / a_other,
		m_afCoordinates[3] / a_other);
}

/// <summary>
/// Sets each instance of the vector 4 to its value divided by an inputted float
/// </summary>
/// <returns></returns>
void CVector4::operator/=(const float a_other)
{
	for (int i = 0; i < 4; i++)
	{
		m_afCoordinates[i] /= a_other;
	}

}

/// <summary>
/// Creates a new vector 4 with the values of the previous vector 4 added to the values of an inputted vector 4
/// </summary>
/// <returns> Vector 4 which has been added to another </returns>
const CVector4 CVector4::operator+(const CVector4 &a_other) const
{
	return CVector4(m_afCoordinates[0] + a_other.m_afCoordinates[0],
		m_afCoordinates[1] + a_other.m_afCoordinates[1],
		m_afCoordinates[2] + a_other.m_afCoordinates[2],
		m_afCoordinates[3] + a_other.m_afCoordinates[3]);
}

/// <summary>
/// Sets each instance of the vector 4 to its value added to the values of an inputted vector 4
/// </summary>
/// <returns></returns>
void CVector4::operator+=(const CVector4 &a_other)
{
	for (int i = 0; i < 4; i++)
	{
		m_afCoordinates[i] += a_other.m_afCoordinates[i];
	}
}

/// <summary>
/// Creates a new vector 4 with the values of the previous vector 4 subtracted by the values of an inputted vector 4
/// </summary>
/// <returns> Vector 4 which has been subtracted by another </returns>
const CVector4 CVector4::operator-(const CVector4 &a_other) const
{
	return CVector4(m_afCoordinates[0] - a_other.m_afCoordinates[0],
		m_afCoordinates[1] - a_other.m_afCoordinates[1],
		m_afCoordinates[2] - a_other.m_afCoordinates[2],
		m_afCoordinates[3] - a_other.m_afCoordinates[3]);
}

/// <summary>
/// Sets each instance of the vector 4 to its value subtracted by the values of an inputted vector 4
/// </summary>
/// <returns></returns>
void CVector4::operator-=(const CVector4 &a_other)
{
	for (int i = 0; i < 4; i++)
	{
		m_afCoordinates[i] -= a_other.m_afCoordinates[i];
	}
}

/// <summary>
/// Finds the magnitude of the vector 4
/// </summary>
/// <returns> The magnitude of the vector 4 </returns>
const float CVector4::magnitude() const
{
	float fAnswer = sqrt((m_afCoordinates[0] * m_afCoordinates[0]) +
		(m_afCoordinates[1] * m_afCoordinates[1]) +
		(m_afCoordinates[2] * m_afCoordinates[2]) +
		(m_afCoordinates[3] * m_afCoordinates[3]));
	return fAnswer;
}

/// <summary>
/// Finds the squared magnitude of the vector 4
/// </summary>
/// <returns> The squared magnitude of the vector 4 </returns>
const float CVector4::magnitudeSq() const
{
	float fAnswer = (m_afCoordinates[0] * m_afCoordinates[0]) +
		(m_afCoordinates[1] * m_afCoordinates[1]) +
		(m_afCoordinates[2] * m_afCoordinates[2]) +
		(m_afCoordinates[3] * m_afCoordinates[3]);
	return fAnswer;
}

/// <summary>
/// Finds the distance between the vector 4 and another in vector 4
/// </summary>
/// <returns> The distance between two vector 4 </returns>
const float CVector4::distance(const CVector4 &a_other) const
{
	float fDistance = sqrt(
		((m_afCoordinates[0] - a_other[0]) * (m_afCoordinates[0] - a_other[0])) +
		((m_afCoordinates[1] - a_other[1]) * (m_afCoordinates[1] - a_other[1])) +
		((m_afCoordinates[2] - a_other[2]) * (m_afCoordinates[2] - a_other[2])) +
		((m_afCoordinates[3] - a_other[3]) * (m_afCoordinates[3] - a_other[3])));
	return fDistance;
}

/// <summary>
/// Finds the squared distance between the vector 4 and an inputted vector 4
/// </summary>
/// <returns> The squared distance between two vector 4 </returns>
const float CVector4::distanceSq(const CVector4 &a_other) const
{
	float fDistance =
		((m_afCoordinates[0] - a_other[0]) * (m_afCoordinates[0] - a_other[0])) +
		((m_afCoordinates[1] - a_other[1]) * (m_afCoordinates[1] - a_other[1])) +
		((m_afCoordinates[2] - a_other[2]) * (m_afCoordinates[2] - a_other[2])) +
		((m_afCoordinates[3] - a_other[3]) * (m_afCoordinates[3] - a_other[3]));
	return fDistance;
}

/// <summary>
/// Finds the dot product of the vector 4 and an inputted vector 4
/// </summary>
/// <returns> The dot product of two vector 4 </returns>
const float CVector4::dotProduct(const CVector4 &a_other) const
{
	float fDot = ((m_afCoordinates[0] * a_other[0]) +
		(m_afCoordinates[1] * a_other[1]) +
		(m_afCoordinates[2] * a_other[2]) +
		(m_afCoordinates[3] * a_other[3]));
	return fDot;
}

/// <summary>
/// Normalises the vector 4 by setting each instance of the vector to be divided by the magnitude
/// </summary>
/// <returns></returns> 
void CVector4::normalise()
{
	float fMagnitude = sqrt((m_afCoordinates[0] * m_afCoordinates[0]) +
		(m_afCoordinates[1] * m_afCoordinates[1]) +
		(m_afCoordinates[2] * m_afCoordinates[2]) +
		(m_afCoordinates[3] * m_afCoordinates[3]));

	for (int i = 0; i < 4; i++)
	{
		m_afCoordinates[i] /= fMagnitude;
	}
	
}

/// <summary>
/// Creates a new vector 4 which is normalised
/// </summary>
/// <returns> Vector 4 which has been normalised </returns> 
const CVector4 CVector4::normalised() const
{
	float fMagnitude = sqrt((m_afCoordinates[0] * m_afCoordinates[0]) +
		(m_afCoordinates[1] * m_afCoordinates[1]) +
		(m_afCoordinates[2] * m_afCoordinates[2]) +
		(m_afCoordinates[3] * m_afCoordinates[3]));

	return CVector4(m_afCoordinates[0] / fMagnitude,
		m_afCoordinates[1] / fMagnitude,
		m_afCoordinates[2] / fMagnitude,
		m_afCoordinates[3] / fMagnitude);
}

/// <summary>
/// Sets each instance of the vector 4 to be the value of an inputted float
/// </summary>
/// <returns></returns> 
CVector4::CVector4(float a_x, float a_y, float a_z, float a_w)
{
	m_afCoordinates[0] = a_x;
	m_afCoordinates[1] = a_y;
	m_afCoordinates[2] = a_z;
	m_afCoordinates[3] = a_w;
}

CVector4::CVector4(CVector2 a_other)
{
}

CVector4::CVector4(CVector3 a_other)
{
}

/// <summary>
/// Finds the address of the pointer to this vector 4
/// </summary>
/// <returns> The address of the pointer </returns> 
const float* CVector4::GetPointer() const
{
	return (float*)this;
}

CVector4::CVector4()
{
}


CVector4::~CVector4()
{
}
