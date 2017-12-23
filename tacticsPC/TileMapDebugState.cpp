#include "TileMapDebugState.h"



TileMapDebugState::TileMapDebugState(System::SharedContext * context, System::StateManager * stateManager):BaseState(context, stateManager)
{
}


TileMapDebugState::~TileMapDebugState()
{
}

void TileMapDebugState::Initiate()
{
	this->tilemap = new TileMap(32, 32, "tileset", context->GetSprites(), context->GetWindow()->GetWindow());
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
	tilemap->Draw();
}

void TileMapDebugState::HandleMessages()
{
}

void TileMapDebugState::Destroy()
{
}
