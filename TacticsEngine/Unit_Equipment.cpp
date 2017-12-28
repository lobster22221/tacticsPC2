#include "Unit_Equipment.h"


Unit_Equipment::Unit_Equipment(unsigned int equipmentslots, vector<string> gameSlots, map<string, int> slotsToUse)
{
	for (int i = 0; i < equipmentslots; i++)
	{
		this->Equipment.push_back(nullptr);
	}


	//copy the slots
	for (int i = 0; i < gameSlots.size(); i++)
	{
		Availible_Slots[gameSlots[i]] = slotsToUse[gameSlots[i]];
	}

}

Unit_Equipment::~Unit_Equipment()
{
}

bool Unit_Equipment::EquipUnit(Item * item, int slots)
{
	//edge case
	if (slots > Equipment.size())
	{
		return false;
	}
	//We need to loop through each slot the item uses and check if we have enough availible
	bool conflict = false;
	for (int i = 0; i < item->get_slots_used().size(); i++)
	{
		//Which slot is being analyzed
		string slotToUse = item->get_slots_used()[i];

		//How many slots the item requires
		int slotsTaken = item->get_slots_count(slotToUse);

		//How many slots the unit has availible
		int slotsAvailible = this->Availible_Slots[slotToUse];

		int previousSlots = 0;
		//if an item is already equiped, we can factor in it's slots
		Item * previous = Equipment[slots];
		if (previous != nullptr)
		{
			previousSlots = Equipment[slots]->get_slots_count(slotToUse);
		}
		slotsAvailible += previousSlots;


		//if the item uses too many slots, we cannot equip the item
		if (slotsTaken > slotsAvailible)
		{
			conflict = true;
		}
	}
	//If we can't equip the item, we are done
	if (conflict)
	{
		return false;
	}
	//Remove the current item in the slot
	Unequip(slots);

	//We have to make sure there are no conflicts in EVERY slot, so subtracting slots for equiping unfortunately
	//requires another loop
	for (int i = 0; i < item->get_slots_used().size(); i++)
	{
		//Which slot is being used
		string slotToUse = item->get_slots_used()[i];

		//How many slots are being used
		int slotsTaken = item->get_slots_count(slotToUse);

		//Remove the slots
		this->Availible_Slots[slotToUse] -= slotsTaken;
	}

	//Actually Equip the item
	Equipment[slots] = item;
	//We did it. Holy shit this was a long function and I don't have testing implemented. I
	// am scared.
	//This function is basically a very complex setter
	return true;
}

void Unit_Equipment::Unequip(int slot)
{
	//Check for problems
	if (slot >= Equipment.size())
	{
		return;
	}
	//Check for problems
	if (Equipment[slot] == nullptr)
	{
		return;
	}

	//For each slot being used by the item, add the slot back to the unit
	vector<string> slots = Equipment[slot]->get_slots_used();
	for each (string usedSlot in slots)
	{
		Availible_Slots[usedSlot] += Availible_Slots[usedSlot];
	}

	//The item itself is managed elsewhere, so we don't want to delete it.
	Equipment[slot] = nullptr;
}
