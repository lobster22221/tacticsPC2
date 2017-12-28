#pragma once
#include <vector>
#include <string>
#include "SpellEffect.h"
#include "Grid.h"
#include "MessageHandler.h"
using namespace std;

enum SpellTarget
{
	self = 1 << 0,
	allies = 1 << 1,
	enemies = 1 << 2,
	terrain = 1 << 3,
	units = 1 << 4
};

class Spell
{
public:
	Spell();
	~Spell();

	
	//returns a vector of tiles the caster can cast on.
	//if the spell is a target all spell, returns a vector with all occupied tiles
	vector<Tile*> FindValidTiles(int casterX, int casterY, Grid * Map);
	//Checks to see if coordinates are a valid location.
	//target z represents the height of the center of targeting.
	bool AttemptCastTile(int casterX, int casterY, int x, int y, int targetz, Grid * Map);
	void Cast(int casterX, int casterY, int x, int y, Grid * Map);


	string Name;
	string id;
	string description;
	int range;
	//How many tiles up and down the spell can target from center
	int verticalRadius = 3;

	//How above or below the center tile can be compared to the caster
	int verticalRange = 3;

	//How many tiles away from the center(manhattan distance) the spell effects.
	int radius;	

	void SetTarget(SpellTarget t);

	//The spell attemps to hit all units on the map. Only valid for target self spells
	bool TargetAll;
private:

	void CastAll(Grid * Map);
	void CastCaster(int casterX, int casterY,Grid * Map);
	void CastTerrain(int x, int y, Grid * Map);
	void CastAllies(int x, int y, Grid * Map);
	void CastEnemies(int x, int y, Grid * Map);
	void CastTarget(int x, int y, Grid * Map);
	SpellTarget Target;

	//Effects all units hit by the spell
	vector<SpellEffect*> Effects_All_Units;

	//Effects only the caster
	vector<SpellEffect*> Effects_Caster;

	//Effects the terrain
	vector<SpellEffect*> Effects_Terrain;

	//Effects only enemies
	vector<SpellEffect*> Effects_Enemies;

	//Effects only allies
	vector<SpellEffect*> Effects_Allies;
	
	//targets only the unit at the center of the radius.
	vector<SpellEffect*> Effects_Target;

};

