#ifndef GAME_ENGINE_IO_MOUSE
#define GAME_ENGINE_IO_MOUSE

#include "GLFW/glfw3.h"

//#include <iostream>
//#include <string>
//using namespace std;

class Mouse
{
public:
	//Mouse();

	static void MousePosCallback(GLFWwindow* window, double _x, double _y);
	static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	static void MouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

	static double GetMouseX();
	static double GetMouseY();


	static bool ScrolledUp();
	static bool ScrolledDown();

	static bool ButtonIsPressed(int button);
	static bool ButtonPressed(int button);
	static bool ButtonReleased(int button);


private:
	static double x;
	static double y;


	static bool ScrollUp;
	static bool ScrollDown;

	static bool buttons[];
	static bool buttonsDown[];
	static bool buttonsUp[];
	
};

#endif