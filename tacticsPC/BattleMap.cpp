#include "BattleMap.h"
#include <iostream>
using namespace std;


Grid::Grid(int w, int h) :width(w), height(h)
{
	tiles = new Tile**[width];
	for (int i = 0; i < w; i++)
	{
		tiles[i] = new Tile*[height];
		for (int j = 0; j < height; j++)
		{
			tiles[i][j] = new Tile();
			tiles[i][j]->z = 0;
		}
	}

	
}

Tile * Grid::Get(int x, int y)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
	{

		return tiles[y][x];
	}
	else
	{
		return nullptr;
	}
}

Tile * Grid::Get(int i)
{
	int y = i % width;
	int x = i / height;
	
	return  Get(x, y);
}

void Grid::printID()
{

	int h = 0;
	for (int i = 0; i < width; i++)
	{
	
		for (int j = 0; j < height; j++)
		{
			cout << Get(h)->z << " ";
			h++;
		}
		cout << "\n";
	}
	
	
}
