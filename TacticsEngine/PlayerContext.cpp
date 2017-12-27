#include "PlayerContext.h"



PlayerContext::PlayerContext()
{
	Party = new PlayerParty();
	gold = 0;
	goldMax = 99999999;
}


PlayerContext::~PlayerContext()
{
}

PlayerParty * PlayerContext::GetParty()
{
	return Party;
}

void PlayerContext::AddGold(int amount)
{
	int total = amount + gold;
	SetGold(goldMax);
	
}

void PlayerContext::SetGold(int total)
{
	if (total < 0)
	{
		total = 0;
		return;
	}

	if (total > goldMax)
	{
		gold = goldMax;
	}
	if (goldMax == -1)
	{
		gold = total;
	}
}

void PlayerContext::SetGoldCap(int newCap)
{
	if (newCap == -1)
	{
		goldMax == -1;
		return;
	}

	if (goldMax == -1)
	{
		return;
	}
	if (newCap < goldMax)
	{
		return;
	}
	if (newCap > goldMax)
	{
		goldMax = newCap;
	}

	
}
