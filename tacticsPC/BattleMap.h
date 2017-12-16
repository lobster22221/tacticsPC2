#pragma once
#include <vector>
class Unit;
//a single tile in the map. Holds its height, its spriteID, and enviormental details such as water flow direction
struct Tile
{
	int z = 0;
	Unit * unit;
	bool walkable = true;
};


//Contains the grid that units base their movement on.
class Grid
{
public:
	Grid(int w, int h);
	
	Tile * Get(int x, int y);
	Tile * Get(int i);
	
	int getWidth() { return width; };
	int getHeight() { return height; }



	void printID();

private:
	const int width, height;
	Tile *** tiles;


};

