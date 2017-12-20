#include "System_Base.h"
namespace ECS
{


	System_Base::System_Base()
	{
	}


	System_Base::~System_Base()
	{
	}
	void System_Base::deregister(ObjectHandle handle)
	{
		Component_Base* comp = this->entityMapping[handle];
		delete this->entityMapping[handle];
		this->entityMapping[handle] = nullptr;
		delete comp;
		comp = nullptr;
	}
}