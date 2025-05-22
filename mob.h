#pragma once

#include "mob.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;

class Mob
{
protected:
    int Health;
    int maxHealth;
    int speed;
    Vector2f m_Position;

    float goal_PositionX;
    float goal_PositionY;
    float moveTime;

    Sprite m_Sprite;

    //Mob texture
    Texture m_TextureUp;
    Texture m_TextureDown;
    Texture m_TextureLeft;
    Texture m_TextureRight;

    IntRect rectSourceSprite;

    //Random number used to determine which direction to go
    int randnum;

public:
    Mob() {}
    void Movement(float elapsedTime, float totalTime, Vector2f mapBounds);
    virtual void MoveAgainstPlayer(float elapsedTime, float totalTime, Vector2f pPosition) = 0;
    //Function to get variables
    FloatRect getPosition();

    Sprite getSprite();

    //Function to get center of object
    Vector2f getCenter();
    virtual bool IsHostile() = 0;
    void ReduceHealth(int r);
    bool IsAlive();
    int getHealth();
};

class Wolf :public Mob
{
public:
    void MoveAgainstPlayer(float elapsedTime, float totalTime, Vector2f pPosition) override;
    Wolf(Vector2f position);
    bool IsHostile() override;

};


class Deer :public Mob
{
public:
    void MoveAgainstPlayer(float elapsedTime, float totalTime, Vector2f pPosition) override;
    Deer(Vector2f position);
    bool IsHostile() override;
};
