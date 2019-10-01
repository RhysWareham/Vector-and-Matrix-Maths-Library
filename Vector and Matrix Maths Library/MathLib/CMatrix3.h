////////////////////////////////////////////////////////////
// File: <CMatrix3.h>
// Author: <Rhys Wareham>
// Date Created: <05/02/2019>
// Brief: <Header file for a 3x3 Matrix maths library>
////////////////////////////////////////////////////////////

#ifndef __CMATRIX3_H__
#define __CMATRIX3_H__

class CVector3;

class CMatrix3
{
public:
	static const CMatrix3 Identity();

#pragma region Getters and Setters
	const CVector3 GetRow(const int a_irowNumber) const;
	void SetRow(const int a_irowNumber, const CVector3 &a_rowValues);
#pragma endregion

#pragma region Rotations
	const CMatrix3 RotateX(const float a_ftheta) const;
	const CMatrix3 RotateY(const float a_ftheta) const;
	const CMatrix3 RotateZ(const float a_ftheta) const;
#pragma endregion

#pragma region overloaded operators
	const CMatrix3 operator+(const CMatrix3 &a_other) const;
	void operator+=(const CMatrix3 &a_other);

	const CMatrix3 operator-(const CMatrix3 &a_other) const;
	void operator-=(const CMatrix3 &a_other);

	const CMatrix3 operator*(const CMatrix3 &a_other) const;
	void operator*=(const CMatrix3 &a_other);

	friend const CVector3 operator*(const CVector3& a_lhs, const CMatrix3& a_rhs);

	const CMatrix3 operator*(const float &a_other) const;
	void operator*=(const float &a_other);

	const bool operator==(const CMatrix3 &a_other) const;
	const bool operator!=(const CMatrix3 &a_other) const;

	const float operator[](const int i) const;
#pragma endregion

#pragma region Constructors/Destructors
	CMatrix3();

	CMatrix3(const float a_fm11, const float a_fm12, const float a_fm13,
		const float a_fm21, const float a_fm22, const float a_fm23,
		const float a_fm31, const float a_fm32, const float a_fm33);

	CMatrix3(const float *a_fpm33Values);

	~CMatrix3();
#pragma endregion

private:
	static const int scm_iCols = 3;
	static const int scm_iRows = 3;
	float m_afMatrixValues[9];
};

#endif // __CMATRIX3_H__
