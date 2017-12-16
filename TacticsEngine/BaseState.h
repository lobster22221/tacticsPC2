#pragma once
namespace System
{
	class StateManager;
	class SharedContext;
}

namespace GUI
{
	class Gui_Controller;
}
class BaseState
{
public:
	friend class StateManager;
	
	BaseState(System::SharedContext * Context, System::StateManager * manager);
	virtual ~BaseState() {}
	//Called on creation
	virtual void Initiate() =0;

	//Called once per tick
	virtual void Tick() = 0;;

	//Called every time the engine updates
	virtual void Update() = 0;

	//Helper function made for updating animations
	virtual void Animate() = 0;

	//Draw to the scren
	virtual void Draw() = 0;

	//Loop through Messages, called by Update
	virtual void HandleMessages() = 0;

	//remove state specific resources
	virtual void Destroy() = 0;

	bool isTransparent() { return transparent; }
	bool isTranscendent() { return transcendent; }

protected:
	bool transparent;
	bool transcendent;
	System::StateManager * stateManager;
	GUI::Gui_Controller * guiController;
	System::SharedContext * context;
};

