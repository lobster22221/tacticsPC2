#pragma once
#include <string>
#include <vector>
#include "thirdParty\TinyXML\tinyxml2.h"
class Item;
using namespace std;
class ItemManager
{
public:
	ItemManager();
	~ItemManager();

	void LoadItems(string file);
	Item * LoadItem(tinyxml2::XMLElement* itemNode);
private:
	vector<Item *> items;
};

