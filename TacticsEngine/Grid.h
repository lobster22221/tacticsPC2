#pragma once
#include "Tile.h"
#include <vector>
using namespace std;
class Grid
{
public:
	Grid(int width, int height);
	Grid(string file);
	~Grid() {}

	void Load(string file);
	int getWidth() { return width; }
	int getHeight() { return height; }
	Tile * GetNode(int x, int y);
	Tile * GetNode(int index);

	void Print();

	bool FindPath(int startX, int startY, int endX, int endY, vector<Tile*> path);
	
	vector<Tile *>FindRadius(int x, int y, int radius);
	int getIndex(int x, int y);

	//Because the map is loaded in this class, we have to store the tileset data here.
	//In the future, it might be better to seperate the tileset and the map. Oh well
	string tileSetName;
private:

	
	void CreateFlat();
	int width;
	int height;
	vector<Tile*> nodes;
};

