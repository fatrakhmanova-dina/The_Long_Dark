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

    Vector2f m_Position;

	Sprite m_Sprite;

	Texture m_Texture;

	FloatRect rectSourceSprite;

public:
    virtual bool IsHostile();

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
