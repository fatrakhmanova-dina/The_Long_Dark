#include "engine.h"
#include "player.h"
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
        if (Keyboard::isKeyPressed(Keyboard::E))
        {
            for (iter1 = Items.begin(); iter1 != Items.end(); ++iter1)
            {
                Vector2f distance;
                distance.x = 0;
                distance.y = 0;
                if ((*iter1)->getCenter().x < pPlayer->getCenter().x)
                {
                    distance.x = pPlayer->getCenter().x - (*iter1)->getCenter().x;
                }
                else
                {
                    distance.x = (*iter1)->getCenter().x - pPlayer->getCenter().x;
                }
                if ((*iter1)->getCenter().y < pPlayer->getCenter().y)
                {
                    distance.y = pPlayer->getCenter().y - (*iter1)->getCenter().y;
                }
                else
                {
                    distance.y = (*iter1)->getCenter().y - pPlayer->getCenter().y;
                }
                if (distance.x < 65 && distance.y < 65)
                {
                    if (pPlayer->getWeight() + (*iter1)->getWeight() <= pPlayer->getMaxWeight())
                    {
                        if ((*iter1)->getType() == 4 && pPlayer->getAxe() >= 1)
                            break;
                        else
                        {
                            pPlayer->PickUp(*iter1);
                            Items.erase(iter1);
                        }
                    }
                    break;
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::F))
        {
            for (iter = Mobs.begin(); iter != Mobs.end(); ++iter)
            {
                Vector2f distance;
                distance.x = 0;
                distance.y = 0;
                if ((*iter)->getCenter().x < pPlayer->getCenter().x)
                {
                    distance.x = pPlayer->getCenter().x - (*iter)->getCenter().x;
                }
                else
                {
                    distance.x = (*iter)->getCenter().x - pPlayer->getCenter().x;
                }
                if ((*iter)->getCenter().y < pPlayer->getCenter().y)
                {
                    distance.y = pPlayer->getCenter().y - (*iter)->getCenter().y;
                }
                else
                {
                    distance.y = (*iter)->getCenter().y - pPlayer->getCenter().y;
                }
                if (distance.x < 65 && distance.y < 65)
                {
                    if (pPlayer->getAxe() == 1)
                    {
                        (*iter)->ReduceHealth(300);
                    }
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Num5) && !num5Pressed)
        {
            pPlayer->Use(5);
            num5Pressed = true;
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Num5))
        {
            num5Pressed = false;
        }

        if (Keyboard::isKeyPressed(Keyboard::Num6) && !num6Pressed)
        {
            pPlayer->Use(6);
            num6Pressed = true;
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Num6))
        {
            num6Pressed = false;
        }

        if (Keyboard::isKeyPressed(Keyboard::Num7) && !num7Pressed)
        {
            pPlayer->Use(7);
            num7Pressed = true;
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Num7))
        {
            num7Pressed = false;
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