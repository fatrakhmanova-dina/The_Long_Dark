#include "engine.h"

void Engine::input()
{
    //Event variable
    Event event;

    while (m_Window.pollEvent(event))
    {
        //Close the window if it is need
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            m_Window.close();
        }
        //Allow player to move using WASD
        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            pPlayer->moveUp();
        }
        else
        {
            pPlayer->stopUp();
        }

        if (Keyboard::isKeyPressed(Keyboard::S))
        {
            pPlayer->moveDown();
        }
        else
        {
            pPlayer->stopDown();
        }

        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            pPlayer->moveLeft();
        }
        else
        {
            pPlayer->stopLeft();
        }

        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            pPlayer->moveRight();
        }
        else
        {
            pPlayer->stopRight();
        }
    }
}