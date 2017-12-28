#pragma once
#include <map>
#include <string>
#include <vector>
class ItemManager;
using namespace std;
class Item
{
public:
	friend ItemManager;

	string name;

	//Used to allow two items to have the same name(for upgradable items, etc). Not meant to be displayed in game 
	string id;
	string description;


	vector<string> get_slots_used();
	int get_slots_count(string alot);

	void print();

protected:
	vector<string> slots_used;
	map<string, int> slots_count;
};