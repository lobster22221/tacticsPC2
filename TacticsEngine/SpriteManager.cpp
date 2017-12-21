#include "SpriteManager.h"
#include <fstream>
#include "Debug.h"




SpriteManager::SpriteManager(TextureManager * tm)
{
	this->texturesRef = tm;
}

SpriteManager::~SpriteManager()
{
}

//Trek through the index file and create new sprites
void SpriteManager::LoadSprites(string indexFile)
{
	std::ifstream fileStream;
	fileStream.open(indexFile);
	//standard file reading code
	if (fileStream.is_open())
	{
		Debug::Log(indexFile + " Loaded\n");
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

			//A sprite sheed is composed of a sprite that gets assigned a texture.
			//The sprite is a new object, but the texture is loaded from the texture manager
			string spriteID;
			string TextureID;
			tmp >> spriteID >> TextureID;
			SpriteSheet * ssheet = new SpriteSheet();
			sf::Texture * tex = this->texturesRef->GetTexture(TextureID);
			ssheet->Sprite.setTexture(*tex);
			
			this->sprites[spriteID] = ssheet;
		}

	}
	else
	{
		Debug::ThrowError(ErrorCodes::FILE_NOT_FOUND, indexFile);
	}
}

SpriteSheet * SpriteManager::GeSprite(string key)
{
	return sprites[key];
}
