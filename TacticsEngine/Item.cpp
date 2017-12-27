#include "Item.h"

vector<string> Item::get_slots_used()
{
	return this->slots_used;
}

int Item::get_slots_count(string slot)
{
	return slots_count[slot];
}
