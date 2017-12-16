#pragma once
//main controller for the game. 
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <string>

#include "Gui_Controller.h"
#include "SharedContext.h"
#include "StateManager.h"
#include "DebugOverlay.h"
#include "MessageHandler.h"

using namespace std;
namespace System
{
	class Engine: public Listener
	{
	public:

		Engine(string masterFile);
		~Engine();

		bool end = false;

		void Initiate();
		void Update();
		void Draw();
		void Shutdown();

		void HandleMessages();
		void Subscribe(GameEvent eventType);

		StateManager * GetStateManager();
		SharedContext * GetContext();
		
	private:
		string ReferenceFiles; //specifies where to look for various files.
		SharedContext * context; //Shared Resource passed to all states
		StateManager * StateController;	//Manages which state the game is rendering
		DebugOverlay * DebugInfo;
		
		
		sf::Clock TickClock;
		sf::Clock AnimationClock;
		float last_Tick = 0;
		
		float last_Draw = 0;
		int TickRate = 30;		//How many times a second input is checked
		//How many times a second animation is updated
		int AnimationRate = 20;		//How many times a second things are drawn to the screen;
		float TickAccumulator = 0;
		float FrameAccumulator = 0;
	};
}

