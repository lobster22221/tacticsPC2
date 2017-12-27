#pragma once
#include <string>
#include <iostream>
#include "PlayerParty.h"
using namespace std;
class PlayerContext
{
public:
	PlayerContext();
	~PlayerContext();

	PlayerParty * GetParty();

	void AddGold(int amount);
	void SetGold(int total);
	//-1 for no cap.
	//If the new cap is less than the current cap and is not -1, nothing happens
	void SetGoldCap(int newCap);
	//GetInventory

	//GetFlags

private:
	PlayerParty * Party;

	int goldMax;
	int gold;
};

