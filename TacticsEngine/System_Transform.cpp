#include "System_Transform.h"
#include "Component_Transform.h"
namespace ECS
{

	System_Transform::System_Transform()
	{
	}


	System_Transform::~System_Transform()
	{
	}

	void System_Transform::Tick()
	{
	}

	void System_Transform::Draw()
	{
	}

	void System_Transform::Register(ObjectHandle Hentity)
	{
		this->entityMapping[Hentity] = new Component_Transform();
	}

}