#include "Component_Transform.h"

ECS::Component_Transform::Component_Transform()
{
}

ECS::Component_Transform::~Component_Transform()
{
}

void ECS::Component_Transform::Tick()
{

	//if movement is disabled, we don't do anything
	if (movePaused)
	{
		return;
	}
	//check if we even are moving
	if (this->CoordinateGoals.empty())
	{
		return;
	}
	int goalX = CoordinateGoals.front().first;
	int goalY = CoordinateGoals.front().second;
	//Deal with X position
	if (positionX < goalX)
	{
		positionX += XSpeed;
		//correct over positioning
		if (positionX > goalX)
		{
			positionX = goalX;
		}
	}
	//Decrement X
	else if (positionX > goalX)
	{
		positionX -= XSpeed;
		//correct over positioning
		if (positionX < goalX)
		{
			positionX = goalX;
		}
	}
	//Deal with Y position
	if (positionY < goalY)
	{
		positionY += YSpeed;
		//correct over positioning
		if (positionY > goalY)
		{
			positionY = goalY;
		}
	}
	//decrement position
	else if (positionY > goalY)
	{
		positionY -= YSpeed;
		//correct over positioning
		if (positionY < goalY)
		{
			positionY = goalY;
		}
	}




}
