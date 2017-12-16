#include "Unit.h"

 Unit::Unit()
{
	
}

bool Unit::Activate()
{
	if (unitState != UnitState::Dead)
	{
		unitState = UnitState::Active;
		return true;
	}
	return false;
}

bool Unit::Deactivate()
{
	if (unitState != UnitState::Dead)
	{
		unitState = UnitState::Idle;
		return true;
	}
	return false;
}

bool Unit::Kill()
{
	unitState = UnitState::Dead;
	return true;
}

bool Unit::Move(Direction::Direction d)
{
	if (unitState != UnitState::Dead)
	{
		unitState = UnitState::Moving;
		return true;
	}
	return false;
}

Unit::~Unit()
{
}

