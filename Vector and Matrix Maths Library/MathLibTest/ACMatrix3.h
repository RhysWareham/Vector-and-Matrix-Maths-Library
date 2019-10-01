#pragma once

class ACVector3;

class ACMatrix3
{
public:
	static const ACMatrix3 Identity();

#pragma region Getters and Setters
	const ACVector3 GetRow(const int a_irowNumber) const;
	void SetRow(const int a_irowNumber, const ACVector3 &a_rowValues);
#pragma endregion

#pragma region Rotations
	const ACMatrix3 RotateX(const float a_ftheta) const;
	const ACMatrix3 RotateY(const float a_ftheta) const;
	const ACMatrix3 RotateZ(const float a_ftheta) const;
#pragma endregion

#pragma region overloaded operators
	const ACMatrix3 operator+(const ACMatrix3 &a_other) const;
	void operator+=(const ACMatrix3 &a_other);

	const ACMatrix3 operator-(const ACMatrix3 &a_other) const;
	void operator-=(const ACMatrix3 &a_other);

	const ACMatrix3 operator*(const ACMatrix3 &a_other) const;
	void operator*=(const ACMatrix3 &a_other);

	const ACMatrix3 operator*(const float &a_other) const;
	void operator*=(const float &a_other);

	const bool operator==(const ACMatrix3 &a_other) const;
	const bool operator!=(const ACMatrix3 &a_other) const;

	const float operator[](const int i) const;
#pragma endregion

#pragma region Constructors/Destructors
	ACMatrix3();

	ACMatrix3(const float a_fm11, const float a_fm12, const float a_fm13,
		const float a_fm21, const float a_fm22, const float a_fm23,
		const float a_fm31, const float a_fm32, const float a_fm33);

	ACMatrix3(const float *a_fpm33Values);

	~ACMatrix3();
#pragma endregion

private:
	static const int cols = 3;
	static const int rows = 3;
	float m_matrixValues[9];
};

