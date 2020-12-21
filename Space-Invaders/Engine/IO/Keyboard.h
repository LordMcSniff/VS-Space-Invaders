#ifndef GAME_ENGINE_IO_KEYBOARD
#define GAME_ENGINE_IO_KEYBOARD

#include "GLFW/glfw3.h"

//#include <iostream>
//#include <string>
//using namespace std;

class Keyboard
{
public:
	//Keyboard();

	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	static bool onKeyPress(int button);
	static bool onKeyRelease(int button);
	static bool keyStatus(int button);

private:

	static bool keys[];
	static bool keysDown[];
	static bool keysUp[];

};

#endif