#include "TileSet.h"





TileSet::TileSet(string SpriteID, int tileWidth, int tileHeight, SpriteManager * spriteRef, sf::RenderWindow * window)
{
	this->Window = window;
	this->tileSprites = spriteRef->GeSprite(SpriteID);
	sf::Vector2u textureDim = tileSprites->Sprite.getTexture()->getSize();
	int w = textureDim.x / tileWidth;
	int h = textureDim.y / tileHeight;

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			sf::IntRect r;
			r.top = i * tileHeight;
			r.left = j * tileWidth;
			r.width = tileWidth;
			r.height = tileHeight;
			tileFrames.push_back(r);
		}
	}
}

TileSet::~TileSet()
{
}

void TileSet::Draw(int id, int x, int y)
{
	this->tileSprites->Sprite.setPosition(sf::Vector2f(x, y));
	tileSprites->Sprite.setTextureRect(tileFrames[id]);
	this->Window->draw(tileSprites->Sprite);
}
