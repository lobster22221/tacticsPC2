#pragma once
#include <string>
using namespace std;
//container that moves around the battlefield. Holds information about an entity owned by a player or computer.
namespace UnitState
{
	enum UnitState
	{
		Active,
		Normal,
		Dead,
		Moving,
		Idle
	};
};
namespace Direction
{
	enum Direction
	{
		Up,
		Down,
		Left,
		Right
	};
}

namespace unitTeam
{
	enum unitTeam
	{
		None,
		User,
		Computer,
		Neutral
	};
}
class Unit
{
public:
	Unit();

	//set state. Returns false if unable to set state
	bool Activate();
	bool Deactivate();
	bool Kill();
	bool Move(Direction::Direction d);
	~Unit();

	//Determines animation
	UnitState::UnitState unitState = UnitState::Idle;
	//entity id
	string id;
	//who controls the unit
	unitTeam::unitTeam owner = unitTeam::None;

	//position
	int X = 0;
	int Y = 0;

	//BattleData
	int TurnCounter = 0;
	bool isActive;
};


