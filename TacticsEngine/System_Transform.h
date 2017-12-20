#pragma once
#include "System_Base.h"
namespace ECS
{
	class System_Transform :
		public System_Base
	{
	public:
		System_Transform();
		~System_Transform();

		void Tick();
		void Draw();

		void Register(ObjectHandle);
	};
}

