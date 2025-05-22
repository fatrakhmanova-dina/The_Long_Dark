#pragma once

#include "player.h"
#include "item.h"
#include <iostream>
#include <SFML/Graphics.hpp>

#include <iostream>
using namespace sf;

class Item
{
protected:
    int weight;
    int type;

    int food_value;
    int water_value;

    Vector2f m_Position;

    Sprite m_Sprite;

    Texture m_Texture;

    IntRect rectSourceSprite;

public:
    Item(int Type, Vector2f position = Vector2f(128, 128));

    int getWeight();

    int getType();

    FloatRect getPosition();

    Sprite getSprite();

    Vector2f getCenter();

    int getFood_val();
    int getWater_val();
};


