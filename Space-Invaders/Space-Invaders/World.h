#ifndef GAME_WORLD
#define GAME_WORLD

//#include "GLFW/glfw3.h"

//#include <iostream>
//#include <string>
//using namespace std;

#include "Entity.h"
//#include "../Engine/Physics/Rigidbody.h"
//#include "../Engine/Math/Vector3.h"

class World
{
public:
	World();
	~World();

	void Update();
	void Render();

	void addObject(Entity* Object);
	int removeObject(Entity* Object);

private:
	int objects;
	Entity* ObjectList[256*2];
};
#endif