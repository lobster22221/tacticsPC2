#pragma once
#include <string>
#include "Item.h"
#include "thirdParty\TinyXML\tinyxml2.h"
using namespace std;
class ItemManager
{
public:
	ItemManager();
	~ItemManager();

	void LoadItems(string file);
	void LoadItem(tinyxml2::XMLElement* itemNode);
private:
	
};

