#pragma once
#include "BaseState.h"
#include "IntroState.h"
#include "TraversableStack.h"
#include <map>
#include <unordered_map>
#include <functional>
#include "SharedContext.h"
using	namespace std;
namespace System
{
	namespace StateType
	{
		enum states
		{
			None,
			Intro,
			MainMenu,
			LoadMenu,
			Cutscene,
			Battle,
			Pause,
			WorldMap,
			GameOver
		};
	}
	using StateContainer = std::vector<std::pair<StateType::states, BaseState*>>;
	// Type container.
	using TypeContainer = std::vector<StateType::states>;
	// State factory.
	using StateFactory = std::unordered_map<StateType::states, std::function<BaseState*(void)>>;

	class StateManager
	{
	public:
		StateManager(SharedContext* l_shared);
		~StateManager();

		//Adds a state on the top of the stack
		void LoadState(StateType::states State);
		//Unload Top State
		void UnloadState();
		//Erase the stack and load a new state
		void ForceState(StateType::states State);
		//Add a new state to the list of states availible
		template<class T>
		void RegisterState(StateType::states state)
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

