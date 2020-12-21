
#include "Engine/Engine.h"

#include <iostream>
using namespace std;


#include "Engine/IO/Mouse.h"
#include "Engine/IO/Keyboard.h"
#include "Engine/Graphics/Sprite.h"
#include "Space-Invaders/Entities/Player.h"

int main()
{
    cout << "Startup!" << endl;

    Engine engine;
    engine.Initialize("Space-Invaders v0.1.0-by LordMcSniff");

    Sprite testSprite = Sprite("Assets/images/Ship.png",0,0);

    Sprite Background = Sprite("Assets/Images/Galaxy.png");
    Background.ScaleTo(Vector3(Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT, 0));

    Player player1 = Player();


    while (true)
    {

        testSprite.SetPos((float)Mouse::GetMouseX(), (float)Mouse::GetMouseY());




        //Updating
        engine.Update();


        testSprite.Update();
        //Update 'subclasses'
        player1.Update();
        //End Updating


        //Rendering
        engine.BeginRender();
        Background.Render();

        testSprite.Render();
        player1.Render();
        
        engine.EndRender();
        //End Rendering



        //Print FPS ---------------------------------------------------------------------------------------
        Engine::GetDelta_T();
        cout << "FPS: " << 1/ Engine::GetDelta_T() << "\r";
        //End Print FPS -----------------------------------------------------------------------------------
    }


    return 0;
}