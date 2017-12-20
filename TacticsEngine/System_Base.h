#pragma once
#include "EntityManager.h"
#include "Component_Base.h"
using namespace std;
namespace ECS
{
	class System_Base
	{
	public:
		System_Base();
		~System_Base();

		virtual void Tick() = 0;
		virtual void Draw() = 0;

		virtual void Register(ObjectHandle) = 0;
		void deregister(ObjectHandle);
	protected:
		map<ObjectHandle, Component_Base*> entityMapping;
	};

}
