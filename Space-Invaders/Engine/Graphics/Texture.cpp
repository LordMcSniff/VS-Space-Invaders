#include "Texture.h"

Texture::Texture()
{
	id = -1;
}

Texture::Texture(int _id)
{
	id = _id;
	if (!GetDimensions())
	{
		cout << "Error loading image with ID: " << id << endl;
	}
}

Texture::Texture(string path)
{
	id = SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA | SOIL_FLAG_INVERT_Y);
	if (!GetDimensions())
	{
		cout << "Error loading image: " << path << endl;
	}
}

bool Texture::GetDimensions()
{
	if (id > 0)
	{
		int miplevel = 0;
		glBindTexture(GL_TEXTURE_2D, id);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_WIDTH, &width);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, miplevel, GL_TEXTURE_HEIGHT, &height);
		return true;
	}
	return false;
}


int Texture::GetHeight()
{
	return height;
}
int Texture::GetWidth()
{
	return width;
}
int Texture::GetID()
{
	return id;
}