#include "ItemLoaderDebugState.h"



ItemLoaderDebugState::ItemLoaderDebugState(System::SharedContext * context, System::StateManager * stateManager) :BaseState(context, stateManager)
{
}

ItemLoaderDebugState::~ItemLoaderDebugState()
{
}

void ItemLoaderDebugState::Initiate()
{
	im = new ItemManager();
	im->LoadItems("assets\\item\\Items.xml");
}

void ItemLoaderDebugState::Tick()
{
}

void ItemLoaderDebugState::Update()
{
}

void ItemLoaderDebugState::Animate()
{
}

void ItemLoaderDebugState::Draw()
{
}

void ItemLoaderDebugState::HandleMessages()
{
}

void ItemLoaderDebugState::Destroy()
{
}
