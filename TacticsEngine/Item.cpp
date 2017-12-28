#include "Item.h"
#include "Debug.h"
vector<string> Item::get_slots_used()
{
	return this->slots_used;
}

int Item::get_slots_count(string slot)
{
	return slots_count[slot];
}

void Item::print()
{
	Debug::Log("Item: {");
	Debug::Log("name: " + name + ": " + id);
	Debug::Log("Description: " + description);
	string s = "Slots: ";
	for (int i = 0; i < slots_used.size(); i++)
	{
		string t = slots_used[i] + ": " + std::to_string(slots_count[slots_used[i]])+" ";
		s += t;
	}
	Debug::Log(s + "}\n");
}
