#pragma once
#include "Grid.h"
#include "TileSet.h"
#include "SpriteManager.h"
using namespace std;

class TileMap
{
public:
	TileMap(int w, int h, string sprite, SpriteManager * sm, sf::RenderWindow * win);
	void Draw();
private:
	Grid * grid;
	TileSet * Tileset;
	SpriteManager * spriteManager;
	sf::RenderWindow * window;

};

