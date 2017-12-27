#include "ItemManager.h"
#include <iostream>
using namespace std;

ItemManager::ItemManager()
{
}


ItemManager::~ItemManager()
{
}

void ItemManager::LoadItems(string file)
{
	tinyxml2::XMLDocument doc;
	if (!doc.LoadFile(file.c_str()))
	{
		cout << doc.ErrorName() << endl;
	}

	//first child is <Items>
	//tinyxml2::XMLElement * root = doc.FirstChildElement();
	tinyxml2::XMLElement * itemEl = doc.RootElement()->FirstChildElement();
	while (itemEl != nullptr)
	{
		LoadItem(itemEl);
		itemEl = itemEl->NextSiblingElement();

	}
}

void ItemManager::LoadItem(tinyxml2::XMLElement *itemNode)
{
}
