#pragma once

#include "player.h"
#include "item.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int Item::getWeight()
{
    return weight;
}

int Item::getType()
{
    return type;
}

FloatRect Item::getPosition()
{
    return m_Sprite.getGlobalBounds();
}

Sprite Item::getSprite()
{
    return m_Sprite;
}

Vector2f Item::getCenter()
{
    return m_Position;
}

Item::Item(int Type, Vector2f position)
{
    m_Position = position;

    if (Type == 4)
    {
        weight = 20;
        m_Texture.loadFromFile("axe.png");
        food_value = 0;
        water_value = 0;
    }
    else if (Type == 5)
    {
        weight = 5;
        m_Texture.loadFromFile("can.png");
        food_value = 20000;
        water_value = 10000;
    }
    else if (Type == 6)
    {
        weight = 5;
        m_Texture.loadFromFile("soda.png");
        food_value = 10000;
        water_value = 20000;
    }
    else if (Type == 7)
    {
        weight = 10;
        m_Texture.loadFromFile("meat.png");
        food_value = 30000;
        water_value = 0;
    }

    type = Type;
    rectSourceSprite = sf::IntRect(0, 0, 32, 32);

    m_Sprite.setTexture(m_Texture);
    m_Sprite = Sprite(m_Texture, rectSourceSprite);

    m_Sprite.setOrigin(16, 16);
    m_Sprite.setPosition(m_Position);
}

int Item::getFood_val()
{
    return this->food_value;
}
int Item::getWater_val()
{
    return this->water_value;
}