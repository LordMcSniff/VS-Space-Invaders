#include "Player.h"

#include "../../Engine/Engine.h"

#include "../../Engine/IO/Mouse.h"
#include "../../Engine/IO/Keyboard.h"

Player::Player()
{
	PlayerShip = Sprite("Assets/images/Ship.png",Vector3(Engine::SCREEN_WIDTH/2, 100,0));
}
Player::~Player()
{
}

void Player::Update()
{
    if (Mouse::ScrolledUp())
    {
        if (Keyboard::keyStatus(GLFW_KEY_LEFT_SHIFT))
        {
            //testSprite.Rotate(1);
        }
        else
        {
            //testSprite.Scale((float)(1 + 0.01));
        }
    }
    else if (Mouse::ScrolledDown())
    {
        if (Keyboard::keyStatus(GLFW_KEY_LEFT_SHIFT))
        {
            //testSprite.Rotate(-1);
        }
        else
        {
            //testSprite.Scale((float)(1 - 0.01));
        }
    }


    if (Keyboard::keyStatus(GLFW_KEY_W))
    {
        PlayerShip.MoveBy(0.0, 0.1);
    }
    if (Keyboard::keyStatus(GLFW_KEY_A))
    {
        PlayerShip.MoveBy(-0.1, 0.0);
    }
    if (Keyboard::keyStatus(GLFW_KEY_S))
    {
        PlayerShip.MoveBy(0.0, -0.1);
    }
    if (Keyboard::keyStatus(GLFW_KEY_D))
    {
        PlayerShip.MoveBy(0.1, 0.0);
    }

	PlayerShip.Update();
}

void Player::shoot()
{
}

void Player::Render()
{
	PlayerShip.Render();
}