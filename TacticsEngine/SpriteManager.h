#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include <map>
#include "SpriteSheet.h"
#include "TextureManager.h"
using namespace std;
class SpriteManager
{
public:
	SpriteManager(TextureManager * tm);
	~SpriteManager();

	
	void LoadSprites(string filename);
	SpriteSheet * GeSprite(string key);


private:
	map<string, SpriteSheet *> sprites;
	TextureManager * texturesRef;
};

