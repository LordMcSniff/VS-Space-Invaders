#include "Engine.h"
#include "IO/Mouse.h"
#include "IO/Keyboard.h"

int Engine::SCREEN_WIDTH = 1536;    //1024
int Engine::SCREEN_HEIGHT = 864;    //768
GLFWwindow* Engine::window = NULL;
float Engine::delta_t = 0;
float Engine::LastFrame = 0;

Engine::Engine(/* args */)
{
}

Engine::~Engine()
{
}

bool Engine::Initialize(const char* windowTitle)
{
    if (!glfwInit())
    {
        cout << "Error initializing GLFW" << endl;
        return false;
    }

    window = glfwCreateWindow(SCREEN_WIDTH,SCREEN_HEIGHT,windowTitle, NULL,NULL);
    if (window == NULL)
    {
        cout << "Error creating window" << endl;
        return false;
    }

    //GLFW Setup
    glfwMakeContextCurrent(window);
    int buff_width, buff_height;
    glfwGetFramebufferSize(window, &buff_width, &buff_height);
    glfwSwapInterval(1);
    
    //add Input
        glfwSetCursorPosCallback(window, Mouse::MousePosCallback);
        glfwSetScrollCallback(window, Mouse::MouseScrollCallback);
        glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallback);
        glfwSetKeyCallback(window, Keyboard::KeyCallback);
    //End add Input

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    int xPos = (mode->width - SCREEN_WIDTH)/2;
    int yPos = (mode->height - SCREEN_HEIGHT)/2;
    glfwSetWindowPos(window, xPos, yPos);

    //GL Setup
    //Viewport
    glViewport(0,0, buff_width,buff_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, buff_width, 0, buff_height, -10, 10);
    glDepthRange(-10, 10);
    glMatrixMode(GL_MODELVIEW);

    //Alpha Blending
    glEnable(GL_ALPHA_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    LastFrame = (float)glfwGetTime();

    return true;
}

void Engine::Update()
{
    float now = (float)glfwGetTime();
    delta_t = (now - LastFrame);
    LastFrame = now;
    glfwPollEvents();
}

void Engine::BeginRender()
{
    glClearColor(0.25, 0, 0.5, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::EndRender()
{
    //actually draw
    glfwSwapBuffers(window);
}

float Engine::GetDelta_T()
{
    return delta_t;
}