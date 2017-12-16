#include "MessageHandler.h"

namespace System
{
	MessageHandler::MessageHandler(System::SystemWindow * win)
	{
		this->window = win->GetWindow();
	}


	MessageHandler::~MessageHandler()
	{
	}

	void MessageHandler::Update()
	{
		sf::Event e;

		while (this->window->pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
			{
				EventMessage message;
				message.EventType = GameEvent::WINDOW_CLOSED;
				WindowEvent *we = new WindowEvent();
				we->closeWindow = true;
				message.EventData = we;
				Dispatch(message);
				break;
			}
			case sf::Event::KeyPressed:
			{
				if (e.key.code == sf::Keyboard::Tilde)
				{
					EventMessage message;
					message.EventType = GameEvent::EVENT_DEBUG;
					Dispatch(message);
				}
				break;
			}
			case sf::Event::MouseButtonPressed:
			{
				if (e.mouseButton.button == sf::Mouse::Left)
				{
					EventMessage message;
					int mouseX;
					int mouseY;
					mouseX = e.mouseButton.x;
					mouseY = e.mouseButton.y;
					LeftClickEvent * lce = new LeftClickEvent();
					lce->mouseX = mouseX;
					lce->mouseY = mouseY;
					message.EventData = lce;
					message.EventType = GameEvent::EVENT_CLICK_LEFT;
					Dispatch(message);
				}
				break;
			}
			default:
				break;
			}
		}
	}

	void MessageHandler::Dispatch(EventMessage eventDispatch)
	{
		subscribers s = this->ToNotify[eventDispatch.EventType];
		for each (Listener * l in s)
		{
			l->Notify(eventDispatch);
		}
	}

	void MessageHandler::Subscribe(int eventType, Listener * listener)
	{
		this->ToNotify[eventType].push_back(listener);
	}

}