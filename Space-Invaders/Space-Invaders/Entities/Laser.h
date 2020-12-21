#ifndef GAME_PLAYER_LASER
#define GAME_PLAYER_LASER

//#include "GLFW/glfw3.h"

//#include <iostream>
//#include <string>
//using namespace std;

#include "../../Engine/Graphics/Sprite.h"
//#include "../Engine/Physics/Rigidbody.h"
//#include "../Engine/Math/Vector3.h"

class Laser
{
public:
	Laser(Vector3 _pos);
	~Laser();

	void Update();
	void Render();

	void onHit();

private:
	Sprite laser;
};
#endif