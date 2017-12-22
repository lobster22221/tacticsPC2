#pragma once
#include "thirdParty\PathFinder\Dijkstra.h"
class Tile :
	public DijkstraNode
{
public:
	Tile(int x, int y);
	~Tile();

	int x, y;
	//height Not used for storage, but purely for gameplay. 
	int z;

	//How is the tile rendered
	int tileSpriteID;


	//used for determining move costs and other gameplay factors
	bool walkable;
	bool water;
	int otherMoveCost;
};

