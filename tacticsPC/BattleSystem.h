#pragma once
#include "Unit.h"
#include "BattleMap.h"
//Container class that holds instances of battles within a battle state. Once a battle is done, the battle state shuts down the system.
/*Flow:
State loads party
State loads enemies
State loads system
System loads map
System loads graphics
System initiates battle
System loops
System ends battle
State ends system
State Unloads
State goes to World state, cutscene state, or Game over state.
*/
class BattleSystem
{
public:
	

	BattleSystem();
	BattleSystem(int w, int h);
	void LoadDebug();
	void LoadParty();
	void LoadMap();
	void loadEnemies();

	void DragUnit(Unit * unit, int x, int y);


	//Messaged functions
	void MoveUnit(Unit * unit, int x, int y);	//causes the unit to travel to point
	void MoveUnitNoAnimation(Unit * unit, int x, int y);//causes the unit to travel to the point instantly if it is pathable
	void TeleportUnit(Unit * unit, int x, int y);//instantly teleports a unit.
	//Iterates turn counter for each unit until a units threshhold surpasses 1000
	void SelectNextUnit(int threshhold = 1000);

	//Casts a spell at the target point. Attack has spell id 0. 
	void CastSpell(Unit * caster, int spellid, int x, int y);

	//functions that happen every tick or every draw frame.
	
	void Update();
	void Draw();
	void DrawPrint();
	
	//Unit whos turn it presently is
	Unit *ActiveUnit;
	vector<Unit*> units;
	
	//The map
	Grid grid;
};
