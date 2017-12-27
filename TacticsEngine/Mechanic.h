#pragma once

class Unit;
class Tile;
class Grid;
void Damage(Unit * Target, int Amount);
void Knockback(Unit * Caster, Unit * Target, int Power, Grid * grid);
void AlterTile(int x, int y, int newTileID, int newTileHeight, Grid*grid);
void Kill(Unit * Target);
void Revive(Unit * Target, int Power);


