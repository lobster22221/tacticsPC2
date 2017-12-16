#pragma once;
#include "Debug.h"
#include "Engine.h"
#include "Gui_Controller.h"

using namespace std;
using namespace System;

int main()
{
	




	Debug::Initiate("ErrorEnum.dat");
	Engine * GameEngine = new Engine("master.dat");

	GameEngine->Initiate();

	while (!GameEngine->end)
	{
		GameEngine->Update();
		GameEngine->HandleMessages();
	}

	GameEngine->Shutdown();
	
	delete GameEngine;
	GameEngine = nullptr;
}