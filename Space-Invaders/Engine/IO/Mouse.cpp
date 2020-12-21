#include "Mouse.h"

double Mouse::x = 0;
double Mouse::y = 0;


bool Mouse::ScrollUp = false;
bool Mouse::ScrollDown = false;

bool Mouse::buttons[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsUp[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonsDown[GLFW_MOUSE_BUTTON_LAST] = { 0 };

void Mouse::MousePosCallback(GLFWwindow* window, double _x, double _y)
{
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	x = _x;
	y = height - _y;
}
void Mouse::MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (button < 0)
		return;

	if (action != GLFW_RELEASE && buttons[button] == false)
	{
		buttonsDown[button] = true;
		buttonsUp[button] = false;
	}
	if (action == GLFW_RELEASE && buttons[button] == true)
	{
		buttonsDown[button] = false;
		buttonsUp[button] = true;
	}

	buttons[button] = action != GLFW_RELEASE;
}
//###################################### Own Code ######################################
void Mouse::MouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	if (yoffset > 0)
	{
		ScrollUp = true;
		ScrollDown = false;
	}
	if (yoffset < 0)
	{
		ScrollUp = false;
		ScrollDown = true;
	}
}

bool Mouse::ScrolledUp()
{
	bool temp = ScrollUp;
	ScrollUp = false;
	return temp;
}
bool Mouse::ScrolledDown()
{
	bool temp = ScrollDown;
	ScrollDown = false;
	return temp;
}
//#################################### End own Code ####################################

double Mouse::GetMouseX()
{
	return x;
}
double Mouse::GetMouseY() 
{
	return y;
}

bool Mouse::ButtonIsPressed(int button)
{
	return buttons[button];
}
bool Mouse::ButtonPressed(int button)
{
	bool temp = buttonsDown[button];
	buttonsDown[button] = false;
	return temp;
}
bool Mouse::ButtonReleased(int button)
{
	bool temp = buttonsUp[button];
	buttonsUp[button] = false;
	return temp;
}