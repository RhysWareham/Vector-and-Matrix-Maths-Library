#pragma once

class ACVector2;
class ACMatrix3;

class ACVector3
{
public:
#pragma region Overloaded Operators
	const float operator[](const int a_i) const;

	const ACVector3 operator*(const float a_other) const;
	void operator*=(const float a_other);

	const ACVector3 operator*(const ACVector3 &a_other) const;
	void operator*=(const ACVector3 &a_other);

	const ACVector3 operator/(const ACVector3 &a_other) const;
	void operator/=(const ACVector3 &a_other);

	const ACVector3 operator/(const float a_other) const;
	void operator/=(const float a_other);

	const ACVector3 operator*(const ACMatrix3 &a_other) const;

	const ACVector3 operator+(const ACVector3 &a_other) const;
	void operator+=(const ACVector3 &a_other);

	const ACVector3 operator-(const ACVector3 &a_other) const;
	void operator-=(const ACVector3 &a_other);
#pragma endregion

#pragma region Public Functions
	const float magnitude() const;
	const float magnitudeSq() const;

	const float distance(const ACVector3 &a_other) const;
	const float distanceSq(const ACVector3 &a_other) const;

	const float dotProduct(const ACVector3 &a_other) const;
	const ACVector3 crossProduct(const ACVector3 &a_rv3a) const;

	void normalise();
	const ACVector3 normalised() const;

	const float* GetPointer() const;
#pragma endregion

#pragma region Constructors/Destructors
	ACVector3(float a_x, float a_y, float a_z);
	ACVector3(ACVector2 other);
	ACVector3();
	~ACVector3();
#pragma endregion
private:
	float m_coordinates[3];
};

