////////////////////////////////////////////////////////////
// File: <CVector3.h>
// Author: <Rhys Wareham>
// Date Created: <05/02/2019>
// Brief: <Header file for a Vector 3 maths library>
////////////////////////////////////////////////////////////

#ifndef __CVECTOR3_H__
#define __CVECTOR3_H__

class CVector2;
class CMatrix3;

class CVector3
{
public:
#pragma region Overloaded Operators
	const float operator[](const int a_i) const;

	const CVector3 operator*(const float a_other) const;
	void operator*=(const float a_other);

	const CVector3 operator*(const CVector3 &a_other) const;
	void operator*=(const CVector3 &a_other);

	const CVector3 operator/(const CVector3 &a_other) const;
	void operator/=(const CVector3 &a_other);

	const CVector3 operator/(const float a_other) const;
	void operator/=(const float a_other);

	//const CVector3 operator*(const CMatrix3 &a_other) const;

	const CVector3 operator+(const CVector3 &a_other) const;
	void operator+=(const CVector3 &a_other);

	const CVector3 operator-(const CVector3 &a_other) const;
	void operator-=(const CVector3 &a_other);
#pragma endregion

#pragma region Public Functions
	const float magnitude() const;
	const float magnitudeSq() const;

	const float distance(const CVector3 &a_other) const;
	const float distanceSq(const CVector3 &a_other) const;

	const float dotProduct(const CVector3 &a_other) const;
	const CVector3 crossProduct(const CVector3 &a_rv3a) const;

	void normalise();
	const CVector3 normalised() const;

	const float* GetPointer() const;
#pragma endregion

#pragma region Constructors/Destructors
	CVector3(float a_x, float a_y, float a_z);
	CVector3(CVector2 other);
	CVector3();
	~CVector3();
#pragma endregion
private:
	float m_afCoordinates[3];
};

#endif // __CVECTOR3_H__