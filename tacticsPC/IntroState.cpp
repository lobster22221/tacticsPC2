#include "IntroState.h"
#include <SFML\Graphics.hpp>
#include "StateManager.h"
#include "Gui_Controller.h"
IntroState::IntroState(System::SharedContext * context, System::StateManager * stateManager) : BaseState(context, stateManager) {}
IntroState::~IntroState()
{
}

void IntroState::Initiate()
{
	
	
	this->guiController->LoadGUI("menuGUI.xml");
	
	
	write = this->context->GetFontManager()->CreateText("Hkello");
	int z = 5;
}

void IntroState::Tick()
{
}

void IntroState::Update()
{
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
}

void IntroState::Destroy()
{
}
