#pragma once
#include <map>
#include <string>
#include <vector>
using namespace std;
class Item
{
public:
	vector<string> get_slots_used();
	int get_slots_count(string alot);

private:
	vector<string> slots_used;
	map<string, int> slots_count;
};