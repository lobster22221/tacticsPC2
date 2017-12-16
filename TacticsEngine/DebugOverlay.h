#pragma once
#include <SFML\Graphics.hpp>

//Overlay displaying debug information.
//Displays
//	loaded data
//	Console Messages
//	

class DebugOverlay
{
public:
	DebugOverlay(int width, int height, sf::RenderWindow * win);
	~DebugOverlay();

	void Refresh();
	void Draw();
	sf::RectangleShape background;

	sf::RenderWindow * window;
	bool visible;
};

