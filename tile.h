#pragma once
#ifndef TILE_H
#define TILE_H
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Tile
{
public:
	// create an enum for the terrain type of this tile
	enum class terrainType { SNOW };

	//Constructor with default values
	Tile(Vector2f position = Vector2f(0, 0), terrainType initialTerrain = terrainType::SNOW);

	terrainType getTerrainType(); // get current terrain type

	//Function to change the type of the tile.
	void ChangeType(Tile::terrainType terrain);

	FloatRect getPosition();
	Vector2f getCenter();
	Sprite getSprite();

protected:
	const std::string SNOWPATH = "graphics/snow.png";

	terrainType m_terrainType;
	Texture m_Texture; // store the texture of this object to be used by the sprite
	Sprite m_Sprite; // store the sprite of this object

	Vector2f m_Position;
	Vector2f m_Resolution;
};
#endif