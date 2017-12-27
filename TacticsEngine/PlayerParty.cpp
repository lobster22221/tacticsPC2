#include "PlayerParty.h"



PlayerParty::PlayerParty()
{
	GenericCap = -1;
	GenericCount = 0;
}

PlayerParty::PlayerParty(int genericCap)
{
	this->GenericCap = genericCap;
	GenericCount = 0;
}


PlayerParty::~PlayerParty()
{
}

bool PlayerParty::Add(Unit * unit)
{
	if (unit->isUnique)
	{
		units.push_back(unit);
	}
	else
	{
		if (this->GenericCount < GenericCap || GenericCap == -1)
		{
			units.push_back(unit);
			GenericCount++;
		}
		else
		{
			return false;
		}
	}

	return true;
}

void PlayerParty::Remove(int index)
{
	Unit * u = Get(index);
	if (u == nullptr)
	{
		return;
	}
	if(!u->isUnique)
	{
		GenericCount--;
	}
	units.erase(units.begin() + index);
}

Unit * PlayerParty::Get(int index)
{
	if (index < 0 || index >= units.size())
		return nullptr;
	return units[index];
}

int PlayerParty::GetGenericSize()
{
	return GenericCount;
}

int PlayerParty::GetUniqueSize()
{
	return (units.size() - GenericCount);
}

int PlayerParty::GetSize()
{
	return units.size();
}
