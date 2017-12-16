#include "StateManager.h"
#include <queue>
namespace System
{

	StateManager::StateManager(SharedContext * l_shared)
		: context(l_shared)
	{
		
	}

	StateManager::~StateManager()
	{
	}

	void StateManager::LoadState(int State)
	{
		BaseState * state = RegisteredStates[State]();
		state->Initiate();
		stateStack.Push(state);
	}

	void StateManager::UnloadState()
	{
		BaseState * state = stateStack.Top();
		stateStack.Pop();
		state->Destroy();
		delete state;
	}

	void StateManager::ForceState(int State)
	{
		while (!stateStack.Empty())
		{
			UnloadState();
		}

		LoadState(State);
	}
	void StateManager::Initiate()
	{
	}
	void StateManager::Tick()
	{
		bool final = false;
		stateStack.ResetPosition();
		while (!final)
		{
			BaseState * current = stateStack.GetCurrent();
			current->Tick();
			//if the current state is transcendant nothing below it will update
			//if the current state is the last in the stack, then we are done
			if (!current->isTranscendent() || stateStack.isAtBottom())
			{
				final = true;
			}
			else
			{
				//everything is clear, update the next state
				stateStack.Descend();
			}
		}
	}
	void StateManager::Update()
	{
		bool final = false;
		stateStack.ResetPosition();
		while (!final)
		{
			BaseState * current = stateStack.GetCurrent();
			current->Update();
			//if the current state is transcendant nothing below it will update
			//if the current state is the last in the stack, then we are done
			if (!current->isTranscendent() || stateStack.isAtBottom())
			{
				final = true;
			}
			else
			{
				//everything is clear, update the next state
				stateStack.Descend();
			}
		}
	}
	void StateManager::Draw()
	{
		if (stateStack.Empty())
		{
			return;
		}
		//Draw from the lowest visible state.
		//Start from the highest visible state, and descend until a state is found that is not transparent
		//At that point draw each state and ascend to the next
		//Speed of ~O(2n), N is likely going to be really small. At most ~3 states should be loaded, and less
		//than that will likely be visible
		bool final = false;
		
		//descend to non transparent 
		stateStack.ResetPosition();
		while (stateStack.GetCurrent()->isTransparent())
		{
			if (!stateStack.isAtBottom())
			{
				stateStack.Descend();
			}
			else
			{
				break;
			}
		}
		//Ascend to top;
		do 
		{
			stateStack.GetCurrent()->Draw();
			if(!stateStack.isAtTop())
			stateStack.Ascend();
		} while (!stateStack.isAtTop());
	}
};
