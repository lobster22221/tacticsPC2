#include "Tile.h"

Tile::Tile(int x, int y)
{
	this->x = x;
	this->y = y;
	this->z = 0;
	tileSpriteID = 0;
}

Tile::~Tile()
{
}
