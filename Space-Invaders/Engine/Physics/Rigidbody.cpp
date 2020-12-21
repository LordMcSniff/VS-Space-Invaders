#include "Rigidbody.h"
#include "../Engine.h"

float Rigidbody::gravity = -9.81f;



Rigidbody::Rigidbody()
{
	*sprite = Sprite();
	friction = 0.0f;	// 0 full friction; 1 no friction
	mass = 1;
}
Rigidbody::Rigidbody(Sprite* _sprite)
{
	sprite = _sprite;

	friction = 0;	// 0 full friction; 1 no friction
	mass = 1;
}
Rigidbody::Rigidbody(string imagePath)
{
	*sprite = Sprite(imagePath);

	friction = 0;	// 0 full friction; 1 no friction
	mass = 1;
}
Rigidbody::Rigidbody(string imagePath, Vector3 _Pos)
{
	*sprite = Sprite(imagePath, _Pos);

	friction = 0;	// 0 full friction; 1 no friction
	mass = 1;
}
Rigidbody::Rigidbody(string imagePath, float _xPos, float _yPos)
{
	*sprite = Sprite(imagePath, _xPos, _yPos);

	friction = 0;	// 0 full friction; 1 no friction
	mass = 1;
}

void Rigidbody::Initalize(float _friction, float _mass)
{
	// Map the input 0 to 100 as 1 to 0
	//float inputScaleMax = 100;
	//friction = ((_friction * (-1)) + inputScaleMax)/ inputScaleMax;

	friction = _friction / 100;

	mass = _mass;
}

void Rigidbody::Update()
{
	//gravity
	AddForce(Vector3(0, gravity, 0) * mass);

	//friction
	Vector3 fr(vel);
	fr.normalize();
	fr = fr * -1;
	fr = fr * friction;
	AddForce(fr);

	//drag
	Vector3 drag(vel);
	drag.normalize();
	float d = 1.2041;//density of air at 20°C in >>>kg/m³<<<
	float D = 0.01;
	/*
	Drag Formula:
	
	d = [density]
	m = [magnitude of vel]
	A = [Surface Area (Facing in vel direction)]
	Cd = [Coeficient of drag]
	vu = [vel unit vector]
	Fd = -0.5 * d * m² * A * Cd * vu
	*/
	drag = drag * -0.5;
	drag = drag * d;
	drag = drag * vel.GetMag() * vel.GetMag();
	drag = drag * 1 * D;
	AddForce(drag);

	vel += acc * Engine::GetDelta_T();	//acc in m/s2 || vel in m/s || m/s2 * s = m/s
	sprite->MoveBy(vel * Engine::GetDelta_T() * 50); //vel in m/s || m = 1px || vel * 50 => 50px = 1m

	//Temporary##############################################################
	if (sprite->GetY() < 0)
	{
		vel.y = abs(vel.y);
		sprite->SetY(0);
	}
	else if (sprite->GetY() > Engine::SCREEN_HEIGHT)
	{
		vel.y = abs(vel.y) * -1;
		sprite->SetY(Engine::SCREEN_HEIGHT);
	}

	if (sprite->GetX() > Engine::SCREEN_WIDTH)
	{
		vel.x = abs(vel.x) * -1;
		sprite->SetX(Engine::SCREEN_WIDTH);
	}
	else if (sprite->GetX() < 0)
	{
		vel.x = abs(vel.x);
		sprite->SetX(0);
	}
	//End Temporary##############################################################

	acc = acc * 0;
	sprite->Update();
}

void Rigidbody::Render(Vector3 c)
{
	glLoadIdentity();

	//TRANSLAT -> ROTATE -> SCALE
	glTranslated(sprite->GetPos().x, sprite->GetPos().y, sprite->GetPos().z);
	glRotatef(sprite->GetRotation(), 0, 0, 1);
	glScalef(sprite->GetScale().x, sprite->GetScale().y, sprite->GetScale().z);


	glColor4f(c.x, c.y, c.z, 1);
	glBegin(GL_LINES);
	{
		glVertex2f(0, 0);
		glVertex2f(sprite->GetSize().x, 0);

		glVertex2f(sprite->GetSize().x, 0);
		glVertex2f(sprite->GetSize().x, sprite->GetSize().y);

		glVertex2f(sprite->GetSize().x, sprite->GetSize().y);
		glVertex2f(0, sprite->GetSize().y);

		glVertex2f(0, sprite->GetSize().y);
		glVertex2f(0, 0);
	}
	glEnd();
}

#include <iostream>
void Rigidbody::AddForce(Vector3 force)
{
	acc.x += force.x / mass;
	acc.y += force.y / mass;
	acc.z += force.z / mass;
}

Vector3 Rigidbody::GetVel()
{
	return vel;
}