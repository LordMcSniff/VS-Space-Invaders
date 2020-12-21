#ifndef GAME_PLAYER
#define GAME_PLAYER

//#include "GLFW/glfw3.h"

//#include <iostream>
//#include <string>
//using namespace std;

#include "../Entity.h"
//#include "../Engine/Physics/Rigidbody.h"
//#include "../Engine/Math/Vector3.h"

class Player : Entity
{
public:
	Player();
	~Player();

	void Update();
	void Render();

	void shoot();

private:
	Sprite PlayerShip;
};
#endif