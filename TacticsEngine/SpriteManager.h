#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include <map>
using namespace std;
class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();

	void LoadSprite(string indexFile);

	void LoadSprites(string filename);
	sf::Sprite * GeSprite(string key);


private:
	map<string, sf::Texture *> textures;
};

