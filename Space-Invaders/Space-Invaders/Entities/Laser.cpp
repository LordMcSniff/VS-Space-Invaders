#include "Laser.h"

Laser::Laser(Vector3 _pos)
{
	laser = Sprite("Assets/images/Laser.png", _pos);
}
Laser::~Laser()
{
	
}

void Laser::onHit()
{
	delete this;
}

void Laser::Update()
{
	laser.MoveBy(Vector3(1, 0, 0));
}
void Laser::Render()
{
	laser.Render();
}