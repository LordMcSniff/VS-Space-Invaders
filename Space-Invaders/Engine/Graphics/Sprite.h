#ifndef GAME_ENGINE_SPRITE
#define GAME_ENGINE_SPRITE

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "../Math/Vector3.h"

#include <iostream>
#include <string>
using namespace std;

class Sprite
{
public:
	Sprite();
	Sprite(string imagePath);
	Sprite(string imagePath, Vector3 _Pos);
	Sprite(string imagePath, float _xPos, float _yPos);

	void Update();
	void Render();

	//Rotation
	float GetRotation();
	void SetRotation(float _rot);
	void Rotate(float delta_rot);

	//Scale
	Vector3 GetSize();

	Vector3 GetScale();
	Vector3 GetScaleByPixel();
	void Scale(float S);
	void Scale(Vector3 S);
	void Scale(float xS, float yS);
	void SetScale(float S);
	void SetScale(Vector3 S);
	void SetScale(float xS, float yS);
	void ScaleTo(Vector3 Dimensions);
	void ScaleTo(float width, float height);

	//Location
	Vector3 GetPos();

	void SetPos(Vector3 _Pos);
	void SetPos(float _xPos, float _yPos);

	void MoveBy(Vector3 delta_Pos);
	void MoveBy(float delta_xPos, float delta_yPos);

	float GetX();
	void SetX(float _xPos);
	float GetY();
	void SetY(float _yPos);

private:

	Texture texture;
	Vector3 Pos;
	float rot;
	Vector3 scale;
	Vector3 size;
};

#endif