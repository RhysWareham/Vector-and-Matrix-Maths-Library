#include "CMatrix3.h"
#include "CVector3.h"

#include <cmath>

/// <summary>
/// Creates an identity matrix
/// </summary>
/// <returns> Matrix 3 </returns> 
const CMatrix3 CMatrix3::Identity()
{
	CMatrix3 mIdentityMatrix3x3;
	for (int i = 0; i < 3; i++)
	{
		mIdentityMatrix3x3.m_afMatrixValues[i * 4] = 1.0f;
	}
	return mIdentityMatrix3x3;
}

/// <summary>
/// Finds the values of a specific row
/// </summary>
/// <returns> Vector 3 </returns>
const CVector3 CMatrix3::GetRow(const int a_irowNumber) const
{
	float fFirstValue = m_afMatrixValues[a_irowNumber * 3];
	float fSecondValue = m_afMatrixValues[a_irowNumber * 3 + 1];
	float fThirdValue = m_afMatrixValues[a_irowNumber * 3 + 2];
	return CVector3(fFirstValue, fSecondValue, fThirdValue);
}

/// <summary>
/// Sets the values of a specific row to an inputted Vector 3
/// </summary>
/// <returns></returns>
void CMatrix3::SetRow(const int a_irowNumber, const CVector3 &a_rowValues)
{
	for (int i = 0; i < 3; i++)
	{
		m_afMatrixValues[(a_irowNumber * 3) + i] = a_rowValues[i];
	}
}

/// <summary>
/// Creates a new Matrix 3 which holds the value of the previous matrix 3 rotated by an inputted float on the X axis
/// </summary>
/// <returns> Matrix 3 which has been rotated </returns>
const CMatrix3 CMatrix3::RotateX(const float a_ftheta) const
{
	CMatrix3 mRotatedMatrix = CMatrix3();
	mRotatedMatrix = { 1.0f,		 0,					0,
						0,		(cos(a_ftheta)),	-(sin(a_ftheta)),
						0,		(sin(a_ftheta)),	(cos(a_ftheta))
	};

	CMatrix3 mNewMatrix = CMatrix3();

	for (int i = 0; i < 9; i++)
	{
		mNewMatrix.m_afMatrixValues[i] = m_afMatrixValues[i];
	}

	CMatrix3 mMultipliedMatrix = mNewMatrix * mRotatedMatrix;

	return mMultipliedMatrix;
}

/// <summary>
/// Creates a new Matrix 3 which holds the value of the previous matrix 3 rotated by an inputted float on the Y axis
/// </summary>
/// <returns> Matrix 3 which has been rotated </returns>
const CMatrix3 CMatrix3::RotateY(const float a_ftheta) const
{
	CMatrix3 mRotatedMatrix = CMatrix3();
	mRotatedMatrix = { (cos(a_ftheta)),		0,		(sin(a_ftheta)),
							0,				1.0f,		0,
					-(sin(a_ftheta)),		0,		(cos(a_ftheta))
	};

	CMatrix3 mNewMatrix = CMatrix3();

	for (int i = 0; i < 9; i++)
	{
		mNewMatrix.m_afMatrixValues[i] = m_afMatrixValues[i];
	}

	CMatrix3 mMultipliedMatrix = mNewMatrix * mRotatedMatrix;

	return mMultipliedMatrix;
}

/// <summary>
/// Creates a new Matrix 3 which holds the value of the previous matrix 3 rotated by an inputted float on the Z axis
/// </summary>
/// <returns> Matrix 3 which has been rotated </returns>
const CMatrix3 CMatrix3::RotateZ(const float a_ftheta) const
{
	CMatrix3 mRotatedMatrix = CMatrix3();
	mRotatedMatrix = { (cos(a_ftheta)),		-(sin(a_ftheta)),		0,
						(sin(a_ftheta)),		(cos(a_ftheta)),	0,
							0,						0,				1.0f
	};

	CMatrix3 mNewMatrix = CMatrix3();

	for (int i = 0; i < 9; i++)
	{
		mNewMatrix.m_afMatrixValues[i] = m_afMatrixValues[i];
	}

	CMatrix3 mMultipliedMatrix = mNewMatrix * mRotatedMatrix;

	return mMultipliedMatrix;
}

/// <summary>
/// Creates a new matrix 3 with the values of the previous matrix 3 added to the values of an inputted matrix 3
/// </summary>
/// <returns> Matrix 3 which has been added to another </returns>
const CMatrix3 CMatrix3::operator+(const CMatrix3 & a_other) const
{
	float afNewMatrix3x3[9];

	for (int i = 0; i < 9; i++)
	{
		afNewMatrix3x3[i] = m_afMatrixValues[i] + a_other[i];
	}
	return CMatrix3(afNewMatrix3x3);
}

/// <summary>
/// Sets each instance of the matrix 3 to its value added to the values of an inputted matrix 3
/// </summary>
/// <returns></returns>
void CMatrix3::operator+=(const CMatrix3 & a_other)
{
	for (int i = 0; i < 9; i++)
	{
		m_afMatrixValues[i] += a_other[i];
	}
}

/// <summary>
/// Creates a new matrix 3 with the values of the previous matrix 3 subtracted by the values of an inputted matrix 3
/// </summary>
/// <returns> Matrix 3 which has been subtracted by another </returns>
const CMatrix3 CMatrix3::operator-(const CMatrix3 & a_other) const
{
	float afNewMatrix3x3[9];

	for (int i = 0; i < 9; i++)
	{
		afNewMatrix3x3[i] = m_afMatrixValues[i] - a_other[i];
	}
	return CMatrix3(afNewMatrix3x3);
}

/// <summary>
/// Sets each instance of the matrix 3 to its value added to the values of an inputted matrix 3
/// </summary>
/// <returns></returns>
void CMatrix3::operator-=(const CMatrix3 & a_other)
{
	for (int i = 0; i < 9; i++)
	{
		m_afMatrixValues[i] -= a_other[i];
	}
}

/// <summary>
/// Creates a new matrix 3 with the values of the previous matrix 3 multiplied by the values of an inputted matrix 3
/// </summary>
/// <returns> Matrix 3 which has been multiplied by another </returns>
const CMatrix3 CMatrix3::operator*(const CMatrix3 &a_other) const
{
	float afNewMatrix3x3[9]; 

	int x = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			afNewMatrix3x3[x] = ((m_afMatrixValues[i * 3] * a_other[j]) + (m_afMatrixValues[(i * 3) + 1] * a_other[j + 3]) + (m_afMatrixValues[(i * 3) + 2] * a_other[j + 6]));
			x++;
		}
	}
	return CMatrix3(afNewMatrix3x3);
}

/// <summary>
/// Returns a new vector 3 with the values of the previous vector 3 multiplied by the values of an inputted matrix 3
/// </summary>
/// <returns> Matrix 3 which has been multiplied by another </returns>
const CVector3 operator*(const CVector3& a_lhs, const CMatrix3& a_rhs)
{
	return CVector3(
		a_lhs[0] * a_rhs[0] + a_lhs[1] * a_rhs[3] + a_lhs[2] * a_rhs[6],
		a_lhs[0] * a_rhs[1] + a_lhs[1] * a_rhs[4] + a_lhs[2] * a_rhs[7],
		a_lhs[0] * a_rhs[2] + a_lhs[1] * a_rhs[5] + a_lhs[2] * a_rhs[8]);
}

/// <summary>
/// Sets each instance of the matrix 3 to its value multiplied by the values of an inputted matrix 3
/// </summary>
/// <returns></returns>
void CMatrix3::operator*=(const CMatrix3 &a_other)
{
	float afValueHolder[9];
	for (int i = 0; i < 9; i++)
	{
		afValueHolder[i] = m_afMatrixValues[i];
	}

	int x = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_afMatrixValues[x] = ((afValueHolder[i * 3] * a_other[j]) + (afValueHolder[(i * 3) + 1] * a_other[j + 3]) + (afValueHolder[(i * 3) + 2] * a_other[j + 6]));
			x++;
		}
	}
}

/// <summary>
/// Creates a new matrix 3 with the values of the previous matrix 3 multiplied by an inputted float
/// </summary>
/// <returns> Matrix 3 which has been multiplied by a float</returns>
const CMatrix3 CMatrix3::operator*(const float & a_other) const
{
	float afNewMatrix3x3[9];
	for (int i = 0; i < 9; i++)
	{
		afNewMatrix3x3[i] = { m_afMatrixValues[i] * a_other };
	}

	return CMatrix3(afNewMatrix3x3);
}

/// <summary>
/// Sets each instance of the matrix 3 to its value multiplied by an inputted float
/// </summary>
/// <returns></returns>
void CMatrix3::operator*=(const float & a_other)
{
	for (int i = 0; i < 9; i++)
	{
		m_afMatrixValues[i] = { m_afMatrixValues[i] * a_other };
	}
}

/// <summary>
/// Checks to see if the matrix 3 has the same values as an inputted matrix 3
/// </summary>
/// <returns> True or False </returns>
const bool CMatrix3::operator==(const CMatrix3& a_other) const
{
	int iCountValue = 0;
	for (int i = 0; i < 9; i++)
	{
		if (m_afMatrixValues[i] == a_other[i])
		{
			iCountValue++;
		}
	}

	if (iCountValue == 9)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// Checks to see if the matrix 3 has different values as an inputted matrix 3
/// </summary>
/// <returns> True or False </returns>
const bool CMatrix3::operator!=(const CMatrix3& a_other) const
{
	int iCountValue = 0;
	for (int i = 0; i < 9; i++)
	{
		if (m_afMatrixValues[i] == a_other[i])
		{
			iCountValue++;
		}
	}

	if (iCountValue < 9)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// <summary>
/// Finds the value of a specific instance of the matrix 3
/// </summary>
/// <returns> Float </returns> 
const float CMatrix3::operator[](const int i) const
{
	float fMatrices = m_afMatrixValues[i];
	return fMatrices;
}

/// <summary>
/// Sets each instance of the matrix 3 to 0
/// </summary>
/// <returns></returns> 
CMatrix3::CMatrix3()
{
	for (int i = 0; i < (scm_iCols*scm_iRows); i++)
	{
		m_afMatrixValues[i] = 0.0f;
	}
}

/// <summary>
/// Sets each instance of the matrix 3 to be the value of inputted floats
/// </summary>
/// <returns></returns> 
CMatrix3::CMatrix3(const float a_fm11, const float a_fm12, const float a_fm13,
	const float a_fm21, const float a_fm22, const float a_fm23,
	const float a_fm31, const float a_fm32, const float a_fm33)
{
	float afValues[9] = { a_fm11, a_fm12, a_fm13, a_fm21, a_fm22, a_fm23, a_fm31, a_fm32, a_fm33 };

	for (int i = 0; i < (scm_iCols*scm_iRows); i++)
	{
		m_afMatrixValues[i] = afValues[i];
	}
}

/// <summary>
/// Sets each instance of the matrix 3 to the values of inputted matrix 3
/// </summary>
/// <returns></returns> 
CMatrix3::CMatrix3(const float *a_fpm33Values)
{
	for (int i = 0; i < (scm_iCols*scm_iRows); i++)
	{
		m_afMatrixValues[i] = a_fpm33Values[i];
	}
}

CMatrix3::~CMatrix3()
{
}
