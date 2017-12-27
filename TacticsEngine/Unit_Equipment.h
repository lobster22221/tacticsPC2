#pragma once
#include <string>
#include <map>
#include <vector>
#include "Item.h"
using namespace std;


class Unit_Equipment
{
public:
	Unit_Equipment(unsigned int equipmentslots, vector<string> gameSlots, map<string, int> slotsToUse);
	~Unit_Equipment();

	bool EquipUnit(Item * item, int slots);
	void Unequip(int slot);
private:
	vector<Item *> Equipment;


	//slots that equiped items are using,
	//If an item requires a slot and the availible slots is 0, it cannot be equiped
	map<string, int> Availible_Slots;
	
};

