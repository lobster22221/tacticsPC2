#include "DebugOverlay.h"

DebugOverlay::DebugOverlay(int width, int height, sf::RenderWindow * win)
{
	this->window = win;
	this->background.setSize(sf::Vector2f(width, height));
	this->background.setFillColor(sf::Color(128, 128, 128, 200));
}

DebugOverlay::~DebugOverlay()
{
}

void DebugOverlay::Refresh()
{
}

void DebugOverlay::Draw()
{
	this->window->draw(background);
}
