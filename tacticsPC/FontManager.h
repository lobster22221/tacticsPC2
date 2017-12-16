#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <map>
#include "TextLine.h"
using namespace std;

namespace Render
{
	class FontManager
	{
	public:
		FontManager();
		~FontManager();

		void Initiate(string fontFile);
		void LoadFont(string key, string font);

		TextLine * CreateText(string message);

		
	private:
		sf::Font * defaultFont;
		map<string, sf::Font*> fonts;
	};
};

