////////////////////////////////////////////////////////////
// File: <CVector4.h>
// Author: <Rhys Wareham>
// Date Created: <09/04/2019>
// Brief: <Header file for a Vector 4 maths library>
////////////////////////////////////////////////////////////

#ifndef __CVECTOR4_H__
#define __CVECTOR4_H__

class CVector2;
class CVector3;

class CVector4
{
public:
#pragma region Overloaded Operators
	const float operator[](const int a_i) const;

	const CVector4 operator*(const float a_other) const;
	void operator*=(const float a_other);

	const CVector4 operator*(const CVector4 &a_other) const;
	void operator*=(const CVector4 &a_other);

	const CVector4 operator/(const CVector4 &a_other) const;
	void operator/=(const CVector4 &a_other);

	const CVector4 operator/(const float a_other) const;
	void operator/=(const float a_other);

	const CVector4 operator+(const CVector4 &a_other) const;
	void operator+=(const CVector4 &a_other);

	const CVector4 operator-(const CVector4 &a_other) const;
	void operator-=(const CVector4 &a_other);
#pragma endregion

#pragma region Public Functions
	const float magnitude() const;
	const float magnitudeSq() const;

	const float distance(const CVector4 &a_other) const;
	const float distanceSq(const CVector4 &a_other) const;

	const float dotProduct(const CVector4 &a_other) const;
	//Vector4 does not have a cross product

	void normalise();
	const CVector4 normalised() const;

	const float* GetPointer() const;
#pragma endregion

#pragma region Constructors/Destructors
	CVector4(float a_x, float a_y, float a_z, float a_w);
	CVector4(CVector2 other);
	CVector4(CVector3 other);
	CVector4();
	~CVector4();
#pragma endregion
private:
	float m_afCoordinates[4];
};

#endif // __CVECTOR4_H__