#pragma once
#include "BaseState.h"
#include "TraversableStack.h"
#include <map>
#include <unordered_map>
#include <functional>
#include "SharedContext.h"
using	namespace std;
namespace System
{
	
	using StateContainer = std::vector<std::pair<int, BaseState*>>;
	// Type container.
	using TypeContainer = std::vector<int>;
	// State factory.
	using StateFactory = std::unordered_map<int, std::function<BaseState*(void)>>;

	class StateManager
	{
	public:
		StateManager(SharedContext* l_shared);
		~StateManager();

		//Adds a state on the top of the stack
		void LoadState(int State);
		//Unload Top State
		void UnloadState();
		//Erase the stack and load a new state
		void ForceState(int State);
		//Add a new state to the list of states availible
		template<class T>
		void RegisterState(int state)
		{
			RegisteredStates[state] = [this]() -> BaseState*
			{
				StateManager * stm = this;
				return new T(this->GetContext(),stm);
			};
		}

		//Manage current states
		void Initiate();
		//Called once per tick
		void Tick();
		//Called every time the engine updates
		void Update();

		//Update animations
		void Animate();
		//Draw to the scren
		void Draw();


		//Getters
		SharedContext * GetContext() { return this->context; }
	private:
		//Currently active states. The top state is the currently active state
		TraversableStack<BaseState*> stateStack;
		//states registered to be availible
		StateFactory RegisteredStates;
		SharedContext * context;
	};
};

