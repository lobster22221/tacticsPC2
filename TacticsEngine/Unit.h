#pragma once
#include <string>
using namespace std;

enum UnitOwner
{
	Player,
	Enemy,
	Neutral
};

class Unit
{
public:
	Unit();
	~Unit();

	string id;
	bool isUnique;
	UnitOwner owner;
};

