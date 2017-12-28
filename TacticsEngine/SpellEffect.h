#pragma once
#include "Mechanic enum.h"
#include "Grid.h"
class Grid;
class SpellEffect
{
public:
	SpellEffect();
	~SpellEffect();

	void Apply(int x, int y, Grid * map);


	Mechanic ApplicationMechanic;
};

