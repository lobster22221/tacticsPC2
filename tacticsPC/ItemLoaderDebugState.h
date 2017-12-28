#pragma once
#include "TacticsEngine\BaseState.h"
#include <TacticsEngine\ItemManager.h>
class ItemLoaderDebugState :
	public BaseState
{
public:
	

	ItemLoaderDebugState(System::SharedContext * context, System::StateManager * stateManager);
	~ItemLoaderDebugState();

	void Initiate();

	//Called once per tick
	void Tick();

	//Called every time the engine updates
	void Update();

	//Helper function made for updating animations
	void Animate();

	//Draw to the scren
	void Draw();

	//Loop through Messages, called by Update
	void HandleMessages();

	//remove state specific resources
	void Destroy();

private:
	ItemManager * im;
};

