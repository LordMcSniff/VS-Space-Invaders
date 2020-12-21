#ifndef GAME_ENGINE
#define GAME_ENGINE


#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")

#include <iostream>
using namespace std;


class Engine
{
private:
    static float delta_t;
    static float LastFrame;

    static GLFWwindow* window;
public:
    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;
    static float GetDelta_T();

    Engine(/* args */);
    ~Engine();

    bool Initialize(const char* windowTitle);

    void Update();
    void BeginRender();
    void EndRender();
};

#endif
