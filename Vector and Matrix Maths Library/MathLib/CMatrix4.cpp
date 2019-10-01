#include "CMatrix4.h"
#include "CVector4.h"

#include <cmath>

/// <summary>
/// Creates an identity matrix
/// </summary>
/// <returns> Matrix 4 </returns> 
const CMatrix4 CMatrix4::Identity()
{
	CMatrix4 mIdentityMatrix4x4;
	for (int i = 0; i < 4; i++)
	{
		mIdentityMatrix4x4.m_afMatrixValues[i * 5] = 1.0f;
	}
	return mIdentityMatrix4x4;
}

/// <summary>
/// Finds the values of a specific row
/// </summary>
/// <returns> Vector 4 </returns>
const CVector4 CMatrix4::GetRow(const int a_irowNumber) const
{
	float fFirstValue = m_afMatrixValues[a_irowNumber * 4];
	float fSecondValue = m_afMatrixValues[a_irowNumber * 4 + 1];
	float fThirdValue = m_afMatrixValues[a_irowNumber * 4 + 2];
	float fFourthValue = m_afMatrixValues[a_irowNumber * 4 + 3];
	return CVector4(fFirstValue, fSecondValue, fThirdValue, fFourthValue);
}

/// <summary>
/// Sets the values of a specific row to an inputted Vector 4
/// </summary>
/// <returns></returns>
void CMatrix4::SetRow(const int a_irowNumber, const CVector4 &a_rowValues)
{
	for (int i = 0; i < 4; i++)
	{
		m_afMatrixValues[(a_irowNumber * 4) + i] = a_rowValues[i];
	}
}

/// <summary>
/// Creates a new Matrix 4 which holds the value of the previous matrix 4 rotated by an inputted float on the X axis
/// </summary>
/// <returns> Matrix 4 which has been rotated </returns>
const CMatrix4 CMatrix4::RotateX(const float a_ftheta) const
{
	CMatrix4 mRotatedMatrix = CMatrix4();
	mRotatedMatrix = { 1.0f,			0,					0,				0,
						0,		(cos(a_ftheta)),	-(sin(a_ftheta)),		0,
						0,		(sin(a_ftheta)),	(cos(a_ftheta)),		0,
						0,				0,					0,				1.0f
	};

	CMatrix4 mNewMatrix = CMatrix4();

	for (int i = 0; i < 16; i++)
	{
		mNewMatrix.m_afMatrixValues[i] = m_afMatrixValues[i];
	}

	CMatrix4 mMultipliedMatrix = mNewMatrix * mRotatedMatrix;

	return mMultipliedMatrix;
}

/// <summary>
/// Creates a new Matrix 4 which holds the value of the previous matrix 4 rotated by an inputted float on the Y axis
/// </summary>
/// <returns> Matrix 4 which has been rotated </returns>
const CMatrix4 CMatrix4::RotateY(const float a_ftheta) const
{
	CMatrix4 mRotatedMatrix = CMatrix4();
	mRotatedMatrix = { (cos(a_ftheta)),		0,		(sin(a_ftheta)),	0,
						0,					1.0f,		0,				0,
					-(sin(a_ftheta)),		0,		(cos(a_ftheta)),	0,
						0,					0,			0,				1.0f
	};

	CMatrix4 mNewMatrix = CMatrix4();

	for (int i = 0; i < 16; i++)
	{
		mNewMatrix.m_afMatrixValues[i] = m_afMatrixValues[i];
	}

	CMatrix4 mMultipliedMatrix = mNewMatrix * mRotatedMatrix;

	return mMultipliedMatrix;
}

/// <summary>
/// Creates a new Matrix 4 which holds the value of the previous matrix 4 rotated by an inputted float on the Z axis
/// </summary>
/// <returns> Matrix 4 which has been rotated </returns>
const CMatrix4 CMatrix4::RotateZ(const float a_ftheta) const
{
	CMatrix4 mRotatedMatrix = CMatrix4();
	mRotatedMatrix = { (cos(a_ftheta)),		-(sin(a_ftheta)),		0,		0,
					(sin(a_ftheta)),		(cos(a_ftheta)),		0,		0,
							0,						0,				1.0f,	0,
							0,						0,				0,		1.0f
	};

	CMatrix4 mNewMatrix = CMatrix4();

	for (int i = 0; i < 16; i++)
	{
		mNewMatrix.m_afMatrixValues[i] = m_afMatrixValues[i];
	}

	CMatrix4 mMultipliedMatrix = mNewMatrix * mRotatedMatrix;

	return mMultipliedMatrix;
}

/// <summary>
/// Creates a new matrix 4 with the values of the previous matrix 4 added to the values of an inputted matrix 4
/// </summary>
/// <returns> Matrix 4 which has been added to another </returns>
const CMatrix4 CMatrix4::operator+(const CMatrix4 & a_other) const
{
	float afNewMatrix4x4[16];

	for (int i = 0; i < 16; i++)
	{
		afNewMatrix4x4[i] = m_afMatrixValues[i] + a_other[i];
	}
	return CMatrix4(afNewMatrix4x4);
}

/// <summary>
/// Sets each instance of the matrix 4 to its value added to the values of an inputted matrix 4
/// </summary>
/// <returns></returns>
void CMatrix4::operator+=(const CMatrix4 & a_other)
{
	for (int i = 0; i < 16; i++)
	{
		m_afMatrixValues[i] += a_other[i];
	}
}

/// <summary>
/// Creates a new matrix 4 with the values of the previous matrix 4 subtracted by the values of an inputted matrix 4
/// </summary>
/// <returns> matrix 4 which has been subtracted by another </returns>
const CMatrix4 CMatrix4::operator-(const CMatrix4 & a_other) const
{
	float afNewMatrix4x4[16];

	for (int i = 0; i < 16; i++)
	{
		afNewMatrix4x4[i] = m_afMatrixValues[i] - a_other[i];
	}
	return CMatrix4(afNewMatrix4x4);
}

/// <summary>
/// Sets each instance of the matrix 4 to its value added to the values of an inputted matrix 4
/// </summary>
/// <returns></returns>
void CMatrix4::operator-=(const CMatrix4 & a_other)
{
	for (int i = 0; i < 16; i++)
	{
		m_afMatrixValues[i] -= a_other[i];
	}
}

/// <summary>
/// Creates a new matrix 4 with the values of the previous matrix 4 multiplied by the values of an inputted matrix 4
/// </summary>
/// <returns> matrix 4 which has been multiplied by another </returns>
const CMatrix4 CMatrix4::operator*(const CMatrix4 &a_other) const
{
	float afNewMatrix4x4[16];

	int x = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			afNewMatrix4x4[x] = ((m_afMatrixValues[i * 4] * a_other[j]) + (m_afMatrixValues[(i * 4) + 1] * a_other[j + 4]) + (m_afMatrixValues[(i * 4) + 2] * a_other[j + 8]) + (m_afMatrixValues[(i * 4) + 3] * a_other[j + 12]));
			x++;
		}
	}
	return CMatrix4(afNewMatrix4x4);
}

/// <summary>
/// Creates a new vector 4 with the values of the previous vector 4 multiplied by the values of an inputted matrix 4
/// </summary>
/// <returns> matrix 4 which has been multiplied by another </returns>
const CVector4 operator*(const CVector4& a_lhs, const CMatrix4& a_rhs)
{
	return CVector4(
		a_lhs[0] * a_rhs[0] + a_lhs[1] * a_rhs[4] + a_lhs[2] * a_rhs[8] + a_lhs[3] * a_rhs[12],
		a_lhs[0] * a_rhs[1] + a_lhs[1] * a_rhs[5] + a_lhs[2] * a_rhs[9] + a_lhs[3] * a_rhs[13],
		a_lhs[0] * a_rhs[2] + a_lhs[1] * a_rhs[6] + a_lhs[2] * a_rhs[10] + a_lhs[3] * a_rhs[14],
		a_lhs[0] * a_rhs[3] + a_lhs[1] * a_rhs[7] + a_lhs[2] * a_rhs[11] + a_lhs[3] * a_rhs[15]);
}

/// <summary>
/// Sets each instance of the matrix 4 to its value multiplied by the values of an inputted matrix 4
/// </summary>
/// <returns></returns>
void CMatrix4::operator*=(const CMatrix4 &a_other)
{
	float afValueHolder[16];
	for (int i = 0; i < 16; i++)
	{
		afValueHolder[i] = m_afMatrixValues[i];
	}

	int x = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_afMatrixValues[x] = ((afValueHolder[i * 4] * a_other[j]) + (afValueHolder[(i * 4) + 1] * a_other[j + 4]) + (afValueHolder[(i * 4) + 2] * a_other[j + 8]) + (afValueHolder[(i * 4) + 3] * a_other[j + 12]));
			x++;
		}
	}
}

/// <summary>
/// Creates a new matrix 4 with the values of the previous matrix 4 multiplied by an inputted float
/// </summary>
/// <returns> matrix 4 which has been multiplied by a float</returns>
const CMatrix4 CMatrix4::operator*(const float & a_other) const
{
	float afNewMatrix4x4[16];
	for (int i = 0; i < 16; i++)
	{
		afNewMatrix4x4[i] = { m_afMatrixValues[i] * a_other };
	}

	return CMatrix4(afNewMatrix4x4);
}

/// <summary>
/// Sets each instance of the matrix 4 to its value multiplied by an inputted float
/// </summary>
/// <returns></returns>
void CMatrix4::operator*=(const float & a_other)
{
	for (int i = 0; i < 16; i++)
	{
		m_afMatrixValues[i] = { m_afMatrixValues[i] * a_other };
	}
}

/// <summary>
/// Checks to see if the matrix 4 has the same values as an inputted matrix 4
/// </summary>
/// <returns> True or False </returns>
const bool CMatrix4::operator==(const CMatrix4& a_other) const
{
	int iCountValue = 0;
	for (int i = 0; i < 16; i++)
	{
		if (m_afMatrixValues[i] == a_other[i])
		{
			iCountValue++;
		}
	}

	if (iCountValue == 16)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// Checks to see if the matrix 4 has different values as an inputted matrix 4
/// </summary>
/// <returns> True or False </returns>
const bool CMatrix4::operator!=(const CMatrix4& a_other) const
{
	int iCountValue = 0;
	for (int i = 0; i < 16; i++)
	{
		if (m_afMatrixValues[i] == a_other[i])
		{
			iCountValue++;
		}
	}

	if (iCountValue < 16)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// Finds the value of a specific instance of the matrix 4
/// </summary>
/// <returns> Float </returns> 
const float CMatrix4::operator[](const int i) const
{
	float fMatrices = m_afMatrixValues[i];
	return fMatrices;
}

/// <summary>
/// Sets each instance of the matrix 4 to 0
/// </summary>
/// <returns></returns> 
CMatrix4::CMatrix4()
{
	for (int i = 0; i < (scm_iCols*scm_iRows); i++)
	{
		m_afMatrixValues[i] = 0.0f;
	}
}

/// <summary>
/// Sets each instance of the matrix 4 to be the value of inputted floats
/// </summary>
/// <returns></returns> 
CMatrix4::CMatrix4(const float a_fm11, const float a_fm12, const float a_fm13, const float a_fm14,
	const float a_fm21, const float a_fm22, const float a_fm23, const float a_fm24,
	const float a_fm31, const float a_fm32, const float a_fm33, const float a_fm34,
	const float a_fm41, const float a_fm42, const float a_fm43, const float a_fm44)
{
	float afValues[16] = { a_fm11, a_fm12, a_fm13, a_fm14, a_fm21, a_fm22, a_fm23, a_fm24, a_fm31, a_fm32, a_fm33, a_fm34, a_fm41, a_fm42, a_fm43, a_fm44 };

	for (int i = 0; i < (scm_iCols*scm_iRows); i++)
	{
		m_afMatrixValues[i] = afValues[i];
	}
}

/// <summary>
/// Sets each instance of the matrix 4 to the values of inputted matrix 4
/// </summary>
/// <returns></returns> 
CMatrix4::CMatrix4(const float *a_fpm44Values)
{
	for (int i = 0; i < (scm_iCols*scm_iRows); i++)
	{
		m_afMatrixValues[i] = a_fpm44Values[i];
	}
}

CMatrix4::~CMatrix4()
{
}