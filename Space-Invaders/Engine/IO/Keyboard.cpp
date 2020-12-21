#include "Keyboard.h"


bool Keyboard::keys[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keysUp[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keysDown[GLFW_KEY_LAST] = { 0 };


void Keyboard::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key < 0)
		return;

	if (action == GLFW_RELEASE && keys[key] == true)
	{
		keysDown[key] = false;
		keysUp[key] = true;
	}
	if (action != GLFW_RELEASE && keys[key] == false)
	{
		keysDown[key] = true;
		keysUp[key] = false;
	}

	keys[key] = action != GLFW_RELEASE;
}



bool Keyboard::keyStatus(int key)
{
	return keys[key];
}

bool Keyboard::onKeyPress(int key)
{
	bool temp = keysDown[key];
	keysDown[key] = false;
	return temp;
}
bool Keyboard::onKeyRelease(int key)
{
	bool temp = keysUp[key];
	keysUp[key] = false;
	return temp;
}