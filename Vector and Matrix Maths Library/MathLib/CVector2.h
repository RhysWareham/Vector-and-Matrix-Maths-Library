////////////////////////////////////////////////////////////
// File: <CVector2.h>
// Author: <Rhys Wareham>
// Date Created: <05/02/2019>
// Brief: <Header file for a Vector 2 maths library>
////////////////////////////////////////////////////////////

#ifndef __CVECTOR2_H__
#define __CVECTOR2_H__

class CVector2
{
public:
#pragma region Overloaded Operators
	const float operator[](const int a_i) const;

	const CVector2 operator*(const float a_other) const;
	void operator*=(const float a_other);

	const CVector2 operator*(const CVector2 &a_other) const;
	void operator*=(const CVector2 &a_other);

	const CVector2 operator/(const CVector2 &a_other) const;
	void operator/=(const CVector2 &a_other);

	const CVector2 operator/(const float a_other) const;
	void operator/=(const float a_other);

	const CVector2 operator+(const CVector2 &a_other) const;
	void operator+=(const CVector2 &a_other);

	const CVector2 operator-(const CVector2 &a_other) const;
	void operator-=(const CVector2 &a_other);
#pragma endregion

#pragma region Public Functions
	const float magnitude() const;
	const float magnitudeSq() const;

	const float distance(const CVector2 &a_other) const;
	const float distanceSq(const CVector2 &a_other) const;

	const CVector2 crossProduct() const;
	const float dotProduct(const CVector2 &a_other) const;

	void normalise();
	const CVector2 normalised() const;

	const float* GetPointer() const;
#pragma endregion

#pragma region Constructors/Destructors
	CVector2(float a_x, float a_y);
	CVector2();
	~CVector2();
#pragma endregion

private:
	float m_afCoordinates[2];
};

#endif // __CVECTOR2_H__