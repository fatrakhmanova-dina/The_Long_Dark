#pragma once
#include "tile.h"
#include <iostream>
#include <fstream>

using namespace sf;

class Tilemap
{
public:
	Tilemap();

	std::vector<std::vector<Tile*>> getMap();

	//void LoadMap();

	void ChangeTileTerrain(int x, int y, Tile::terrainType terrain);

	Vector2f getMapBounds();

protected:
	std::vector<std::vector<Tile*>> map;

	Vector2f m_bounds;
};