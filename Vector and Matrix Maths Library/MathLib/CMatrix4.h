////////////////////////////////////////////////////////////
// File: <CMatrix4.h>
// Author: <Rhys Wareham>
// Date Created: <09/04/2019>
// Brief: <Header file for a 4x4 Matrix maths library>
////////////////////////////////////////////////////////////

#ifndef __CMATRIX4_H__
#define __CMATRIX4_H__

class CVector4;

class CMatrix4
{
public:
	static const CMatrix4 Identity();

#pragma region Getters and Setters
	const CVector4 GetRow(const int a_irowNumber) const;
	void SetRow(const int a_irowNumber, const CVector4 &a_rowValues);
#pragma endregion

#pragma region Rotations
	const CMatrix4 RotateX(const float a_ftheta) const;
	const CMatrix4 RotateY(const float a_ftheta) const;
	const CMatrix4 RotateZ(const float a_ftheta) const;
#pragma endregion

#pragma region overloaded operators
	const CMatrix4 operator+(const CMatrix4 &a_other) const;
	void operator+=(const CMatrix4 &a_other);

	const CMatrix4 operator-(const CMatrix4 &a_other) const;
	void operator-=(const CMatrix4 &a_other);

	const CMatrix4 operator*(const CMatrix4 &a_other) const;
	void operator*=(const CMatrix4 &a_other);

	friend const CVector4 operator*(const CVector4& a_lhs, const CMatrix4& a_rhs);

	const CMatrix4 operator*(const float &a_other) const;
	void operator*=(const float &a_other);

	const bool operator==(const CMatrix4 &a_other) const;
	const bool operator!=(const CMatrix4 &a_other) const;

	const float operator[](const int i) const;
#pragma endregion

#pragma region Constructors/Destructors
	CMatrix4();

	CMatrix4(const float a_fm11, const float a_fm12, const float a_fm13, const float a_fm14,
		const float a_fm21, const float a_fm22, const float a_fm23, const float a_fm24,
		const float a_fm31, const float a_fm32, const float a_fm33, const float a_fm34,
		const float a_fm41, const float a_fm42, const float a_fm43, const float a_fm44);

	CMatrix4(const float *a_fpm44Values);

	~CMatrix4();
#pragma endregion

private:
	static const int scm_iCols = 4;
	static const int scm_iRows = 4;
	float m_afMatrixValues[16];
};

#endif // __CMATRIX4_H__