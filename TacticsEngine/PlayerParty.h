/**
** Wrapper class for an array, containing units owned by the player.
** Allows limited amount of "limited" units.
**/

#pragma once
#include <vector>
#include "Unit.h"
using namespace std;
class PlayerParty
{
public:
	PlayerParty();
	PlayerParty(int genericCap);
	~PlayerParty();

	//Adds a unit to the party. If the unit is unique, it is always added.
	//If the unit is generic, it is added if the cap has not been reached.
	//if the generic cap is -1, the unit is always added
	//returns false if the unit was not added
	bool Add(Unit* unit);

	//Removes the unit from the party
	//if index is below 0 or more than the number of units, this function does nothing
	void Remove(int index);
	//returns the unit in position index
	Unit * Get(int index);

	int GetGenericSize();
	int GetUniqueSize();
	int GetSize();
private:
	vector<Unit*> units;
	int GenericCap;
	int GenericCount;
};

