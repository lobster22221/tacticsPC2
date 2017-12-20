#pragma once
#include "Component_Base.h"
#include <map>
#include <queue>
using namespace std;
#define coordinate pair<int, int> 
namespace ECS
{
	class Component_Transform:
		public Component_Base
	{
	public:
		Component_Transform();
		~Component_Transform();

		void Tick();

	private:
		bool movePaused;
		//location in the world
		int positionX;
		int positionY;

		//When updated, move towards these coordinates
		queue<coordinate> CoordinateGoals;

		//Velocity to move at
		int XSpeed;
		int YSpeed;
	};

}