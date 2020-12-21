#ifndef GAME_ENGINE_TEXTURES
#define GAME_ENGINE_TEXTURES

#include "GLFW/glfw3.h"
#include "soil.h"

#include <iostream>
#include <string>
using namespace std;

class Texture 
{
public:
	Texture();
	Texture(int _id);
	Texture(string path);

	int GetID();
	int GetWidth();
	int GetHeight();

private:
	bool GetDimensions();

	int id;
	int width;
	int height;
};

#endif