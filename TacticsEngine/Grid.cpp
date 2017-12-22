#include "Grid.h"
#include "thirdParty\PathFinder\PathFinder.h"
#include "thirdParty/PathFinder/Dijkstra.h"
Grid::Grid(int w, int h)
{
	width = w;
	height = h;
	CreateFlat();
}

Tile * Grid::GetNode(int x, int y)
{
	//bounds checking is done in the other nodes function
	return GetNode(getIndex(x,y));
}

Tile * Grid::GetNode(int index)
{//bounds checking
	if(index < 0 || index >= width*height)
	{
		return nullptr;
	}
	return nodes[index];
}

void Grid::Print()
{
}

bool Grid::FindPath(int startX, int startY, int endX, int endY, vector<Tile*> path)
{
	PathFinder<Tile> pather;
	
	Tile st = *this->GetNode(startX, startY);
	Tile et = *this->GetNode(endX, endY);
	pather.setStart(st);
	pather.setGoal(et);
	bool success = pather.findPath<Dijkstra>(path);
	return success;
		
}

vector<Tile*> Grid::FindRadius(int sx, int sy, int radius)
{
	vector<Tile*> radiusTiles;
	for (int x = -radius; x < radius; x++)
	{
		for (int y = -radius; y < radius; y++)
		{
			//if manhattan distance <= radius
			//then it is in the radius
			int distX = abs(x - sx);
			int distY = abs(y - sy);
			if(distX + distY < radius)
			{
				
				radiusTiles.push_back(this->GetNode(x, y));
			}
		}
	}
	return radiusTiles;
	
}

int Grid::getIndex(int x, int y)
{
	return width * y + x;
}

void Grid::CreateFlat()
{

	for (int x = 0; x < width; x++)
	{		
		for (int y = 0; y < height; y++)
		{
			Tile * tile =   new Tile(x, y);
			nodes.push_back(tile);
		}
	}
	//connect tiles. Since The nodes are not initialized at first, the loop must be repeated
	//This might be optimized later
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			Tile * tile = nodes[getIndex(x, y)];
			
			//Add children
			Tile * north = GetNode(x, y - 1);
			Tile * south = GetNode(x, y + 1);
			Tile * west = GetNode(x - 1, y);
			Tile * east = GetNode(x + 1, y);

			if (north != nullptr)
			{
				tile->addChild(north, 1);
			}
			if (south != nullptr)
			{
				tile->addChild(south, 1);
			}
			if (west != nullptr)
			{
				tile->addChild(west, 1);
			}
			if (east != nullptr)
			{
				tile->addChild(east, 1);
			}
		}
	}
}
