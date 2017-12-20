#pragma once
#include <string>
#include <vector>
#include <map>
#include <SFML\Graphics.hpp>
using namespace std;
class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	void LoadTextures(string indexFile);

	void LoadTexture(string filename);
	sf::Texture * GetTexture(string key);


private:
	map<string, sf::Texture *> textures;
};

