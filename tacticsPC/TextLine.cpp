#include "TextLine.h"
#include <SFML\Graphics.hpp>


Render::TextLine::TextLine()
{
	line = sf::Text();
}

Render::TextLine::TextLine(sf::Font *font, string text)
{
	line = sf::Text(text,*font);
}


Render::TextLine::~TextLine()
{
}

void Render::TextLine::SetFont(sf::Font* font)
{
	line.setFont(*font);
}

void Render::TextLine::SetText(string text)
{
	line.setString(text);
}

void Render::TextLine::SetColor(sf::Color color)
{
	this->line.setFillColor(color);
}

void Render::TextLine::Draw(sf::RenderWindow* window)
{
	string s = line.getString();
	const sf::Font *  font = line.getFont();
	window->draw(line);
}

void Render::TextLine::SetPosition(int x, int y)
{
	line.setPosition(sf::Vector2f(x, y));
}
