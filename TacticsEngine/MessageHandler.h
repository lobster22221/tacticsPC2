#pragma once
#include <SFML/Window.hpp>
#include "SystemWindow.h"
#include "Command.h"
#include <vector>
#include <map>
#include <queue>
using namespace std;

namespace System
{
	//virtual class that 
	class Listener
	{

	public:
		virtual void HandleMessages() = 0;
		

		void Notify(EventMessage message)
		{
			messages.push(message);
		}

	protected:
		virtual ~Listener() {};
		queue<EventMessage> messages;
	};

#define subscribers vector<Listener*>
#define EventMappings map<int, subscribers>
	class MessageHandler
	{
	public:
		
		MessageHandler(System::SystemWindow * win);
		~MessageHandler();

		void Update();
		void Dispatch(EventMessage eventDispatch);
		void Subscribe(int eventType, Listener * listener);

		sf::RenderWindow * window;


		EventMappings ToNotify;

	};


}
