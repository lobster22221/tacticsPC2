#include "TileMapDebugState.h"



TileMapDebugState::TileMapDebugState(System::SharedContext * context, System::StateManager * stateManager):BaseState(context, stateManager)
{
}


TileMapDebugState::~TileMapDebugState()
{
}

void TileMapDebugState::Initiate()
{
	grid = new Grid(32, 32);
	grid->Print();
}

void TileMapDebugState::Tick()
{
}

void TileMapDebugState::Update()
{
}

void TileMapDebugState::Animate()
{
}

void TileMapDebugState::Draw()
{
}

void TileMapDebugState::HandleMessages()
{
}

void TileMapDebugState::Destroy()
{
}
