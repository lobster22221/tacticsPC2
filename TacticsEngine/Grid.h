#pragma once
#include "Tile.h"
#include <vector>
using namespace std;
class Grid
{
public:
	Grid(int width, int height);
	~Grid();

	Tile * GetNode(int x, int y);
	Tile * GetNode(int index);

	void Print();

	bool FindPath(int startX, int startY, int endX, int endY, vector<Tile*> path);
	
	vector<Tile *>FindRadius(int x, int y, int radius);
private:

	int getIndex(int x, int y);
	void CreateFlat();
	int width;
	int height;
	vector<Tile*> nodes;
};

