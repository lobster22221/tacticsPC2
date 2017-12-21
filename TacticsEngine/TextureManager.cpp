#include "TextureManager.h"
#include <fstream>
#include "Debug.h"
using namespace std;


TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

void TextureManager::LoadTextures(string indexFile)
{
	std::ifstream fileStream;
	fileStream.open(indexFile);
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
			string key;
			string filename;
			tmp >> key >> filename;
			
			sf::Texture * tex = new sf::Texture();
			tex->loadFromFile(filename);
			this->textures[key] = tex;
		}

	}
	else
	{
		Debug::ThrowError(ErrorCodes::FILE_NOT_FOUND, indexFile);
	}
}


sf::Texture * TextureManager::GetTexture(string key)
{
	return textures[key];
}
