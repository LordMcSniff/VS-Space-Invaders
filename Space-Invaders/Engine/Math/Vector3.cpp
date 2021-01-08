#include "Vector3.h"
#include <cmath>

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}
Vector3::Vector3(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
}
Vector3::Vector3(float _x)
{
	x = _x;
	y = _x;
	z = _x;
}
Vector3::Vector3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

float Vector3::GetMag()
{
	return pow(x*x + y*y,0.5);
}
void Vector3::normalize()
{
	float m = GetMag();
	if (x != 0)
	{
		x = x / m;
	}
	if (x != 0)
	{
		y = y / m;
	}
	if (x != 0)
	{
		z = z / m;
	}
}

Vector3& Vector3::operator=(const Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;

	return *this;
}
Vector3 Vector3::operator+(const Vector3& other)
{
	Vector3 ret;

	ret.x = other.x + x;
	ret.y = other.y + y;
	ret.z = other.z + z;

	return ret;
}
Vector3 Vector3::operator-(const Vector3& other)
{
	Vector3 ret;

	ret.x = other.x - x;
	ret.y = other.y - y;
	ret.z = other.z - z;

	return ret;
}
Vector3 Vector3::operator*(const Vector3& other)
{
	Vector3 ret;

	ret.x = other.x * x;
	ret.y = other.y * y;
	ret.z = other.z * z;

	return ret;
}
Vector3 Vector3::operator*(float _x)
{
	Vector3 ret;

	ret.x = _x * x;
	ret.y = _x * y;
	ret.z = _x * z;

	return ret;
}
Vector3 Vector3::operator/(const Vector3& other)
{
	Vector3 ret;

	ret.x = other.x / x;
	ret.y = other.y / y;
	ret.z = other.z / z;

	return ret;
}
Vector3 Vector3::operator/(float _x)
{
	Vector3 ret;

	ret.x = _x / x;
	ret.y = _x / y;
	ret.z = _x / z;

	return ret;
}

Vector3& Vector3::operator+=(const Vector3& other)
{
	x = other.x + x;
	y = other.y + y;
	z = other.z + z;

	return *this;
}
Vector3& Vector3::operator-=(const Vector3& other)
{
	x = other.x - x;
	y = other.y - y;
	z = other.z - z;

	return *this;
}


bool Vector3::operator<(const Vector3& other)
{
	if (other.x < x && other.y < y && other.z < z)
	{
		return true;
	}
	return false;
}
bool Vector3::operator>(const Vector3& other)
{
	if (other.x > x && other.y > y && other.z > z)
	{
		return true;
	}
	return false;
}

bool Vector3::operator==(const Vector3& other)
{
	return (x == other.x && y == other.y && z == other.z);
}
bool Vector3::operator!=(const Vector3& other)
{
	return !operator==(other);
}