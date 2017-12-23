#pragma once
#include "SpriteManager.h"

class TileSet
{
public:
	TileSet(string SpriteID, int tileWidth, int tileHeight, SpriteManager * spriteRef, sf::RenderWindow * window);
	~TileSet();

	void Draw(int id, int x, int y);

	vector<sf::IntRect> tileFrames;
	SpriteSheet * tileSprites;

	sf::RenderWindow * Window;
};

