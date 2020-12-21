#ifndef GAME_ENGINE_PHYSICS_RIGIDBODY
#define GAME_ENGINE_PHYSICS_RIGIDBODY

#include "GLFW/glfw3.h"

//#include <iostream>
#include <string>
using namespace std;

#include "../Graphics/Sprite.h" // also includes Vector3

class Rigidbody
{
public:
	Rigidbody();
	Rigidbody(Sprite* _sprite);
	Rigidbody(string imagePath);
	Rigidbody(string imagePath, Vector3 _Pos);
	Rigidbody(string imagePath, float _xPos, float _yPos);

	void Initalize(float _friction, float _mass);

	void Update();
	void Render(Vector3 colour);

	void AddForce(Vector3 force);

	Vector3 GetVel();

	Sprite* sprite;
private:

	static float gravity;

	float mass;
	float friction;
	Vector3 acc;
	Vector3 vel;
};

#endif