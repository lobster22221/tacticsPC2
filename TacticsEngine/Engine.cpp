#include "Engine.h"
#include "Command.h"

namespace System
{

	Engine::Engine(string masterFile)
	{
		
		end = false;
		this->ReferenceFiles = masterFile;
		context = new SharedContext();
		context->Initiate(ReferenceFiles);
		StateController = new StateManager(context);
		DebugInfo = new DebugOverlay(this->context->GetWindow()->GetWidth(), 
			this->context->GetWindow()->GetHeight(), this->context->GetWindow()->GetWindow());
		
		
	}

	Engine::~Engine()
	{
	}

	void Engine::Initiate()
	{
		auto messenger = context->GetMessenger();
		messenger->Subscribe((int)GameEvent::EVENT_DEBUG, this);
		messenger->Subscribe((int)GameEvent::WINDOW_CLOSED, this);
		LoadState(0);
	}

	void Engine::Update()
	{
		context->GetMessenger()->Update();
		StateController->Update();
		TickAccumulator += TickClock.getElapsedTime().asSeconds();
		TickClock.restart();
		float rate = ((float)1 / (float)this->TickRate);
		while (TickAccumulator >= rate)
		{
			StateController->Tick();
			TickAccumulator -= rate;
		}

		FrameAccumulator += AnimationClock.getElapsedTime().asSeconds();
		AnimationClock.restart();
		rate = ((float)1 / (float)this->AnimationRate);
		while (FrameAccumulator >= rate)
		{
			Draw();
			FrameAccumulator -= rate;
		}
		

		HandleMessages();
		this->end = context->end;

	}

	void Engine::Draw()
	{
		context->GetWindow()->GetWindow()->clear();
		StateController->Draw();
		if (DebugInfo->visible)
		{
				this->DebugInfo->Draw();
		}	context->GetWindow()->GetWindow()->display();
	}

	void Engine::Shutdown()
	{
	}

	void Engine::HandleMessages()
	{
		while (messages.empty() == false)
		{
			EventMessage message = messages.front();
			messages.pop();
			switch (message.EventType)
			{
				case GameEvent::EVENT_DEBUG:
				{
					Debug::Log("Debug Toggled\n");
					DebugInfo->visible = !DebugInfo->visible;

					break;
				}
				case GameEvent::WINDOW_CLOSED:
				{
					exit(0);
					break;
				}
			}
		}
	}

	void Engine::LoadState(int state)
	{
		StateController->LoadState(state);
	}

	


	StateManager * Engine::GetStateManager()
	{
		return this->StateController;
	}

	SharedContext * Engine::GetContext()
	{
		return context;
	}


	

};