#pragma once
#include <TacticsEngine\Grid.h>
class TileMapDebugState
{
public:
	TileMapDebugState();
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

