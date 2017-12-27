#pragma once
#include <vector>
#include <map>
#include <string>
using namespace std;
class DataManager
{
public:
	DataManager();
	~DataManager();
	
	void CreateUnit(string race, string job);
private:
	//Each item uses up certain tags. For example, a sword takes up 1 hand and 1 weapon slot.
	//A unit typically has a certain number of tags availible
	vector<string> EquipmentTags;
	//How many slots for each equipment tag a generic unit has. A unit with double sword will
	//Get a second weapon slot
	//Some monsters may have 3 hands and 3 weapon slots and 0 offhand slots
	map<string, int> defaultSlotSetup;
};

