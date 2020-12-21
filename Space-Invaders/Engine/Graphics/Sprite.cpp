#include "Sprite.h"

Sprite::Sprite()
{
	texture = Texture();
	Pos = Vector3(0);
	rot = 0;
	scale = Vector3(1);
	size = Vector3(1);
}

Sprite::Sprite(string imagePath)
{
	texture = Texture(imagePath);
	Pos = Vector3(0);
	rot = 0;
	scale = Vector3(1);
	size = Vector3((float)texture.GetWidth(), (float)texture.GetHeight(), 1);
}

Sprite::Sprite(string imagePath, float _xPos, float _yPos)
{
	texture = Texture(imagePath);
	Pos = Vector3(_xPos, _yPos, 0);
	rot = 0;
	scale = Vector3(1);
	size = Vector3((float)texture.GetWidth(), (float)texture.GetHeight(), 1);
}

Sprite::Sprite(string imagePath, Vector3 _Pos)
{
	texture = Texture(imagePath);
	Pos = _Pos;
	rot = 0;
	scale = Vector3(1);
	size = Vector3((float)texture.GetWidth(), (float)texture.GetHeight(), 1);
}


void Sprite::Update()
{

}
void Sprite::Render()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture.GetID());
	glLoadIdentity();

	//TRANSLAT -> ROTATE -> SCALE
	glTranslatef(Pos.x, Pos.y, 0);
	//glTranslatef(Pos.x + (float)(texture.GetWidth()/2), Pos.y + (float)(texture.GetHeight()/2), 0);
	glRotatef(rot, 0, 0, 1);		// R; x axis = false; y axis = false; z axis = true
	glScalef(scale.x, scale.y, 1);
	//glTranslatef(Pos.x, Pos.y, 0);

	//Rendering
	glColor4f(1, 1, 1, 1);
	glBegin(GL_QUADS);
	{
		glTexCoord2f(0, 0);		glVertex2f(0, 0);
		glTexCoord2f(1, 0);		glVertex2f(size.x, 0);
		glTexCoord2f(1, 1);		glVertex2f(size.x, size.y);
		glTexCoord2f(0, 1);		glVertex2f(0, size.y);
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);
} 



Vector3 Sprite::GetSize()
{
	return size;
}

Vector3 Sprite::GetScale()
{
	return scale;
}
Vector3 Sprite::GetScaleByPixel()
{
	float w = scale.x * texture.GetWidth();
	float h = scale.y * texture.GetHeight();
	return Vector3(w, h, 1);
}

void Sprite::Scale(float S)
{
	scale = scale * S;
}
void Sprite::Scale(Vector3 S)
{
	scale = scale * S;
}
void Sprite::Scale(float xS, float yS)
{
	scale.x = scale.x * xS;
	scale.y = scale.y * yS;
}
void Sprite::SetScale(float S)
{
	scale = Vector3(S);
}
void Sprite::SetScale(Vector3 S)
{
	scale = S;
}
void Sprite::SetScale(float xS, float yS)
{
	scale.x = xS;
	scale.y = yS;
}
void Sprite::ScaleTo(Vector3 Dimensions)
{
	scale.x = Dimensions.x / texture.GetWidth();
	scale.y = Dimensions.y / texture.GetHeight();
}
void Sprite::ScaleTo(float width, float height)
{
	scale.x = width / texture.GetWidth();
	scale.y = height / texture.GetHeight();
}



float Sprite::GetRotation()
{
	return rot;
}
void Sprite::SetRotation(float _rot)
{
	rot = _rot;
}
void Sprite::Rotate(float delta_rot)
{
	rot -= delta_rot;
}



Vector3 Sprite::GetPos()
{
	return Pos;
}

void Sprite::SetPos(Vector3 _Pos)
{
	Pos = _Pos;
}
void Sprite::SetPos(float _xPos, float _yPos)
{
	Pos.x = _xPos;
	Pos.y = _yPos;
}


void Sprite::MoveBy(Vector3 delta_Pos)
{
	Pos += delta_Pos;
}
void Sprite::MoveBy(float delta_xPos, float delta_yPos)
{
	Pos += Vector3(delta_xPos, delta_yPos, 0);
}


float Sprite::GetX()
{
	return Pos.x;
}
void Sprite::SetX(float _xPos)
{
	Pos.x = _xPos;
}

float Sprite::GetY()
{
	return Pos.y;
}
void Sprite::SetY(float _yPos)
{
	Pos.y = _yPos;
}