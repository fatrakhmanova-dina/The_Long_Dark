#include "tile.h"
//Constructor
Tile::Tile(Vector2f position, terrainType terrain)
{
	m_terrainType = terrain; // assign the type of terrain from the parameter

	m_Sprite.setPosition(position); // position from parameter

	// check correct terrain type and set it's texture accordingly
	ChangeType(terrain);

	m_Sprite.setTexture(m_Texture); // assign the texture to the sprite
	m_Sprite.setOrigin(128, 128); // set origin to center

	m_Sprite.setScale(.5, .5);
}

Tile::terrainType Tile::getTerrainType()
{
	return m_terrainType;
}

//change the terrains type
void Tile::ChangeType(Tile::terrainType terrain)
{
	m_terrainType = terrain;

	// check current terrain type and assign a texture depending on type
	switch (m_terrainType)
	{
	case Tile::terrainType::SNOW:
		m_Texture.loadFromFile(SNOWPATH);
		break;
	default:
		break;
	}
}

Sprite Tile::getSprite()
{
	return m_Sprite;
}