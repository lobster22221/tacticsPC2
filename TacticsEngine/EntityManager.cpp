#include "EntityManager.h"
#include "System_Transform.h"
ECS::EntityManager::EntityManager()
{
	this->RegisterSystem<System_Transform>(SystemType::system_Transform, true, false);
}

ECS::EntityManager::~EntityManager()
{
}

ObjectHandle ECS::EntityManager::RegisterEntity()
{
	ObjectHandle newhandle;
	//no empty slots, create a new one
	if (availibleHandles.empty())
	{
		newhandle = HandleCounter;
		HandleCounter++;
	}
	else
	{
		newhandle = availibleHandles.front();
		availibleHandles.pop();
	}

	this->entities.push_back(newhandle);
	return newhandle;
}

void ECS::EntityManager::DeRegisterEntity(ObjectHandle entity)
{
	for (int i = 0; i < entities.size(); i++)
	{
		if (entities[i] == entity)
		{
			entities.erase(entities.begin() + i);
			availibleHandles.push(entity);
		}

	}
}

void ECS::EntityManager::AddComponent(ObjectHandle entity, SystemType sys)
{
	Systems[sys]->system->Register(entity);
}

void ECS::EntityManager::RemoveComponent(ObjectHandle entity, SystemType system)
{
}

void ECS::EntityManager::Update()
{
	
	for (auto const& x : this->Systems)
	{
		if (x.second->Update)
		{
			x.second->system->Tick();
		}
	}

}

void ECS::EntityManager::Draw()
{
	for (auto const& x : this->Systems)
	{
		if (x.second->Update)
		{
			x.second->system->Draw();
		}
	}
}
