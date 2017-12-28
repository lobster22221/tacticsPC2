#pragma once
#include "Mechanic enum.h"
class Unit;
class Tile;
class Grid;

struct CallMechanic
{
	Unit * Caster;
	int Power;
	int targetX;
	int targetY;

	Grid * map;
};

void Damage(Unit * Target, int Amount);
void Knockback(Unit * Caster, Unit * Target, int Power, Grid * grid);
void AlterTile(int x, int y, int newTileID, int newTileHeight, Grid*grid);
void Kill(Unit * Target);
void Revive(Unit * Target, int Power);


