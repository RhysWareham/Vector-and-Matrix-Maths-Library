#pragma once

class ACVector2
{
public:
#pragma region Overloaded Operators
	const float operator[](const int a_i) const;

	const ACVector2 operator*(const float a_other) const;
	void operator*=(const float a_other);

	const ACVector2 operator*(const ACVector2 &a_other) const;
	void operator*=(const ACVector2 &a_other);

	const ACVector2 operator/(const ACVector2 &a_other) const;
	void operator/=(const ACVector2 &a_other);

	const ACVector2 operator/(const float a_other) const;
	void operator/=(const float a_other);

	const ACVector2 operator+(const ACVector2 &a_other) const;
	void operator+=(const ACVector2 &a_other);

	const ACVector2 operator-(const ACVector2 &a_other) const;
	void operator-=(const ACVector2 &a_other);
#pragma endregion

#pragma region Public Functions
	const float magnitude() const;
	const float magnitudeSq() const;

	const float distance(const ACVector2 &a_other) const;
	const float distanceSq(const ACVector2 &a_other) const;

	const ACVector2 crossProduct() const;
	const float dotProduct(const ACVector2 &a_other) const;

	void normalise();
	const ACVector2 normalised() const;

	const float* GetPointer() const;
#pragma endregion

#pragma region Constructors/Destructors
	ACVector2(float a_x, float a_y);
	ACVector2();
	~ACVector2();
#pragma endregion

private:
	float m_coordinates[2];
};

