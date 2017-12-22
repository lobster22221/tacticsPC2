#pragma once
#include <TacticsEngine\Grid.h>
#include <TacticsEngine\FontManager.h>
#include <TacticsEngine\Gui_Controller.h>

#include <TacticsEngine/BaseState.h>
class TileMapDebugState:
	public BaseState
{
public:
	TileMapDebugState(System::SharedContext * context, System::StateManager * stateManager);
	~TileMapDebugState();

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
	Grid * grid;
};

