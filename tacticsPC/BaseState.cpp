#include "BaseState.h"
#include "Gui_Controller.h"
BaseState::BaseState(System::SharedContext * Context, System::StateManager * manager) : stateManager(manager), transparent(false), transcendent(false)
{
	this->context = Context;
	guiController = new GUI::Gui_Controller(Context);
}
