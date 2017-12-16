#include "IntroState.h"
#include <TacticsEngine\Engine.h>

int main()
{
	System::Engine *engine = new System::Engine("assets/master.dat");
	engine->RegisterState<IntroState>(0);

	engine->Initiate();
	while (!engine->end)
	{
		engine->Update();
		
	}
	engine->Shutdown();

}