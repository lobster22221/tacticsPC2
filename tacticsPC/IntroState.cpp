#include "IntroState.h"
#include <TacticsEngine\StateManager.h>
IntroState::IntroState(System::SharedContext * context, System::StateManager * stateManager) : BaseState(context, stateManager) {}
IntroState::~IntroState()
{
}

void IntroState::Initiate()
{
	guiController->LoadGUI("assets/gui/menuGUI.xml");


	write = this->context->GetFontManager()->CreateText("Hkello");
	int z = 5;
}

void IntroState::Tick()
{
}

void IntroState::Update()
{
	HandleMessages();
}

void IntroState::Animate()
{
}

void IntroState::Draw()
{
	sf::RenderWindow * window = stateManager->GetContext()->GetWindow()->GetWindow();
	write->Draw(window);
	this->guiController->Draw(window);

}

void IntroState::HandleMessages()
{
	guiController->HandleMessages();
}

void IntroState::Destroy()
{
}