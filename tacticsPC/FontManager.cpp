#include "FontManager.h"
#include <fstream>
#include <string>
#include <sstream>
#include "Debug.h"
#include "TextLine.h"
using namespace std;
using namespace Render;

Render::FontManager::FontManager()
{
}

Render::FontManager::~FontManager()
{
}

void Render::FontManager::Initiate(string fontFile)
{
	std::ifstream fileStream;
	fileStream.open(fontFile);
	if (fileStream.is_open())
	{
		Debug::Log(fontFile + " Loaded\n");
		string line;
		while (getline(fileStream, line))
		{
			if (line[0] == '|')
			{
				continue;
			}
			if (line.empty())
			{
				continue;
			}
			stringstream tmp(line);
			string key;
			string filename;
			tmp >> key >> filename;
			LoadFont(key, filename);
		}

	}
	else
	{
		Debug::ThrowError(ErrorCodes::FILE_NOT_FOUND, fontFile);
	}

}

void Render::FontManager::LoadFont(string key, string font)
{
	
	if (fonts.count(key) == 0)
	{
		sf::Font *f = new sf::Font();

		f->loadFromFile(font);
		this->fonts[key] = f;
		defaultFont = f;
	}
}

Render::TextLine * Render::FontManager::CreateText(string message)
{
	TextLine * t = new TextLine(defaultFont, message);
	return t;
}
