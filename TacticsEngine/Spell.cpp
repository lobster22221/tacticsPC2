#include "Spell.h"



Spell::Spell()
{
}


Spell::~Spell()
{
}

vector<Tile*> Spell::FindValidTiles(int casterX, int casterY, Grid * Map)
{
	vector<Tile*> potentials = Map->FindRadius(casterX, casterY, radius);
	vector<Tile*> valid;
	int v = this->verticalRadius;
	for (int i = 0; i < potentials.size(); i++)
	{
		int pz = potentials[i]->z;
		int tz = Map->GetNode(casterX, casterY)->z;
		int abso = abs(pz-tz);
		if (abso < v)
		{
			valid.push_back(potentials[i]);
		}
	}
	return valid;
}

bool Spell::AttemptCastTile(int casterX, int casterY, int x, int y, int z, Grid * Map)
{
	Tile * t = Map->GetNode(x, y);
	Tile * casterTile = Map->GetNode(casterX, casterY);
	//if the tile doesn't exist
	if (t == nullptr)
	{
		return false;
	}	
	int tileHeight = t->z;
	int casterHeight = casterTile->z;
	//if the tile is too high or low to target
	if (abs(tileHeight - casterHeight) > verticalRange)
	{
		return false;
	}

	//The spell doesn't care if there is a unit on it
	if (Target & SpellTarget::terrain)
	{
		return true;
	}
	Unit * unitTarget = t->AttachedUnit;
	//if the spell is not terrain targeted and there is no unit, then the
	//targeting is invalid
	if (unitTarget == nullptr)
	{
		return false;
	}

	//There is a unit target, so the targetting is valid
	if (Target & SpellTarget::units)
	{
		return true;
	}

	UnitOwner casterOwner = casterTile->AttachedUnit->owner;

	if (unitTarget->owner == casterOwner && Target & SpellTarget::allies)
	{
		return true;
	}
	
	if ((!(unitTarget->owner == casterOwner)) && (Target & SpellTarget::enemies))
	{
		return true;
	}

	//same tile == same unit
	//caster height is probably unneccesary unles maps get 3d
	if (casterX == x && casterY == y &&  tileHeight == casterHeight && Target & SpellTarget::self)
	{
		return true;
	}

	//No criteria met
	return false;

}

void Spell::Cast(int casterX, int casterY, int x, int y, Grid * Map)
{
	//There is always a caster
	CastCaster(casterX, casterY, Map);
	Unit * targetUnit = Map->GetNode(x, y)->AttachedUnit;
	if (targetUnit != nullptr)
	{
		CastTarget(x, y, Map);
	}

	vector<Tile*> tiles = this->FindValidTiles(x, y, Map);
	for (int i = 0; i < tiles.size(); i++)
	{
		bool succ = AttemptCastTile(casterX, casterY, tiles[i]->x, tiles[i]->y, tiles[i]->z, Map);
		if (succ)
		{
			//Terrain
			CastTerrain(tiles[i]->x, tiles[i]->y, Map);

			//Start applying effects that effect non target units. This
			//Also applies to the targeted unit
			Unit * unit = tiles[i]->AttachedUnit;
			if (unit != nullptr)
			{
				UnitOwner casterAlliance = Map->GetNode(casterX, casterY)->AttachedUnit->owner;
				UnitOwner alliance = unit->owner;
				CastAll(Map);

				if (alliance == casterAlliance || alliance == UnitOwner::Neutral)
				{
					CastAllies(tiles[i]->x, tiles[i]->y, Map);
				}
				if (alliance != casterAlliance)
				{
					CastEnemies(tiles[i]->x, tiles[i]->y, Map);
				}
			}
		}
	}
}


void Spell::SetTarget(SpellTarget t)
{
	Target = t;
}

void Spell::CastAll(Grid * Map)
{
}

void Spell::CastCaster(int casterX, int casterY, Grid * Map)
{
}

void Spell::CastTerrain(int x, int y, Grid * Map)
{	
	for (int i = 0; i < Effects_Terrain.size(); i++)
	{
		Effects_Terrain[i]->Apply(x, y, Map);
	}
}

void Spell::CastAllies(int x, int y, Grid * Map)
{
}

void Spell::CastEnemies(int x, int y, Grid * Map)
{
}


void Spell::CastTarget(int x, int y, Grid * Map)
{
}
