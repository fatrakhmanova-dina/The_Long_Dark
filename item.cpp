#pragma once

#include "player.h"
#include "item.h"
#include <iostream>
#include <SFML/Graphics.hpp>


Item::Item(int w = 0, string t = " ", Vector2f position)
{
    weight = w;
    type = t;
    m_Position = position;


	// load all correct textures
	//m_TextureUp.loadFromFile("graphics/player/up.png");
	//m_TextureDown.loadFromFile("graphics/player/down.png");
	//m_TextureLeft.loadFromFile("graphics/player/left.png");
	//m_TextureRight.loadFromFile("graphics/player/right.png");

	// create rect to navigate through the spriresheet
	rectSourceSprite = sf::IntRect(0, 0, 64, 64);

	m_Sprite.setTexture(m_TextureRight);
	m_Sprite = Sprite(m_TextureRight, rectSourceSprite);

	m_Sprite.setOrigin(32, 32);
	m_Sprite.setPosition(m_Position);
}
int Item::getWeight()
{
    return weight;
}

string Item::getType()
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

Food::Food(int w, string t, int fv, int wv)
{
    weight = w;
    type = t;
    food_value = fv;
    water_value = wv;
}

int Food::getFood_val()
{
    return this->food_value;
}
int Food::getWater_val()
{
    return this->water_value;
}
