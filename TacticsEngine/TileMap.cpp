#include "TileMap.h"

TileMap::TileMap(int w, int h, string sprite, SpriteManager * sm, sf::RenderWindow * win)
{
	grid = new Grid("assets/maps/test1.map");
	this->Tileset = new TileSet(grid->tileSetName, 32, 32, sm, win);
}

void TileMap::Draw()
{
	for (int x = 0; x < this->grid->getWidth()-1; x++)
	{
		for (int y = 0; y < grid->getHeight()-1; y++)
		{
			int id = grid->getIndex(x, y);
			int tID = grid->GetNode(id)->tileSpriteID;
			this->Tileset->Draw(tID, x * 32, y * 32);

		}
	}
}
