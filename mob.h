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

	IntRect rectSourceSprite;

	//Random number used to determine which direction to go
	int randnum;

public:
    virtual bool IsHostile();
    void Movement(float elapsedTime, float totalTime, Vector2f mapBounds);
    virtual void MoveAgainstPlayer(float elapsedTime, float totalTime, Vector2f pPosition);
    //Function to get variables
	FloatRect getPosition();

	Sprite getSprite();

	//Function to get center of object
	Vector2f getCenter();



};

class Wolf:public Mob
{
public:
    bool IsHostile();
};

class Deer:public Mob
{
public:
    bool IsHostile();
};
