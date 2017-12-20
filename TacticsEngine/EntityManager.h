#pragma once
#include <vector>
#include <map>
#include "Component_Base.h"
#include <queue>

using	namespace std;
#define  ObjectHandle unsigned int
namespace ECS
{
	class System_Base;

	enum SystemType
	{
		system_Transform,
		system_Animation,
	};




	class EntityManager
	{
	private:

		
		struct SystemContainer
		{
			bool Update;
			bool Draw;
			System_Base * system;
		};

	public:
		EntityManager();
		~EntityManager();

		ObjectHandle RegisterEntity();
		void DeRegisterEntity(ObjectHandle);
		
		template <class T>
		void RegisterSystem(ECS::SystemType type, bool Tickable, bool Drawable)
		{
			SystemContainer * syscon = new SystemContainer();
			syscon->Update = Tickable;
			syscon->Draw = Drawable;
			syscon->system = new T();
			Systems[type] = syscon;
		}

		void DeregisterSystem(SystemType system)
		{
			SystemContainer * container = Systems[system];
			Systems.erase(system);
			delete container->system;
			container->system = NULL;
			delete container;
		}

		void AddComponent(ObjectHandle entity, SystemType system);
		void RemoveComponent(ObjectHandle entity, SystemType system);

		void Update();
		void Draw();

	private:


		//Entity registration
		int HandleCounter;
		queue<ObjectHandle> availibleHandles;
		vector<ObjectHandle> entities;

		//System registration
		map<SystemType, SystemContainer*> Systems;
		
	};

}
