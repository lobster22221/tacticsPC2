#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include "SystemWindow.h"
using namespace std;
namespace Render
{
	class TextLine
	{
	public:
		TextLine();

		TextLine(sf::Font * font, string text);
		
		~TextLine();

		void SetFont(sf::Font* font);
		void SetText(string text);
		void SetColor(sf::Color color);

		void setPosition(int x, int y, int w, int h);
		void Draw(sf::RenderWindow * window);

		
		
		
		void SetPosition(int x, int y);
		sf::Text line;
	};
}

