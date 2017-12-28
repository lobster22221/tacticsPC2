#include "ItemManager.h"
#include <iostream>
#include "Item.h"
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
	if (doc.LoadFile(file.c_str()))
	{
		cout << doc.ErrorName() << endl;
		return;
	}
cout << doc.ErrorName() << endl;
	//first child is <Items>
	//tinyxml2::XMLElement * root = doc.FirstChildElement();
	tinyxml2::XMLElement * itemEl = doc.RootElement()->FirstChildElement();
	while (itemEl != nullptr)
	{
		LoadItem(itemEl);
		itemEl = itemEl->NextSiblingElement();

	}
}

Item * ItemManager::LoadItem(tinyxml2::XMLElement *itemNode)
{
	Item * item = new Item();
	string id = itemNode->Attribute("id");
	item->id = id;
	//first property
	tinyxml2::XMLElement * Iproperty = itemNode->FirstChildElement();	

	while (Iproperty != nullptr)
	{
		string propertyName = Iproperty->Value();
		

		if (propertyName == "name")
		{
			item->name = Iproperty->GetText();
		}
		if (propertyName == "description")
		{
			item->description = Iproperty->GetText();
		}
		if (propertyName == "Slots")
		{
			tinyxml2::XMLElement * Islot = Iproperty->FirstChildElement();
			while (Islot != nullptr)
			{
				string slotname = Islot->Attribute("id");
				int slotCount = Islot->IntText();
				item->slots_count[slotname] = slotCount;
				item->slots_used.push_back(slotname);
				Islot = Islot->NextSiblingElement();
			}
		}
		Iproperty = Iproperty->NextSiblingElement();
	}
	item->print();
	return item;
}
