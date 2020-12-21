#ifndef GAME_ENTITY
#define GAME_ENTITY

//#include "GLFW/glfw3.h"

//#include <iostream>
//#include <string>
//using namespace std;

#include "../Engine/Graphics/Sprite.h"
//#include "../Engine/Physics/Rigidbody.h"
//#include "../Engine/Math/Vector3.h"

class Entity
{
public:
	Entity();
	~Entity();

	void Update();
	void Render();

	void shoot();

private:
};
#endif