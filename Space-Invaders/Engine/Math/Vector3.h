#ifndef GAME_ENGINE_VECTOR3
#define GAME_ENGINE_VECTOR3

//#include "GLFW/glfw3.h"

//#include <iostream>
//#include <string>
//using namespace std;

class Vector3
{
public:
	Vector3();
	Vector3(const Vector3& other);
	Vector3(float _x);
	Vector3(float _x, float _y, float _z);

	float GetMag();
	void normalize();

	Vector3& operator=(const Vector3& other);
	Vector3 operator+(const Vector3& other);
	Vector3 operator-(const Vector3& other);
	Vector3 operator*(const Vector3& other);
	Vector3 operator*(float _x);
	Vector3 operator/(const Vector3& other);
	Vector3 operator/(float _x);

	Vector3& operator+=(const Vector3& other);
	Vector3& operator-=(const Vector3& other);


	bool operator<(const Vector3& other);
	bool operator>(const Vector3& other);

	bool operator==(const Vector3& other);
	bool operator!=(const Vector3& other);

	float x;
	float y;
	float z;

};

#endif