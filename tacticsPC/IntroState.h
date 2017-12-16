#pragma once
#include <TacticsEngine/BaseState.h>
#include <TacticsEngine\FontManager.h>
#include <TacticsEngine\Gui_Controller.h>
class IntroState :
	public BaseState
{
public:
	IntroState(System::SharedContext * context, System::StateManager * stateManager);
	~IntroState();

	void Initiate();

	//Called once per tick
	void Tick();

	//Called every time the engine updates
	void Update();

	//Helper function made for updating animations
	void Animate();

	//Draw to the scren
	void Draw();

	//Loop through Messages, called by Update
	void HandleMessages();

	//remove state specific resources
	void Destroy();

private:
	Render::TextLine * write;
	sf::Font * font;

};

