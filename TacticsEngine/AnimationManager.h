#pragma once
#include <vector>
#include "Frame.h"
#include <SFML/Graphics.hpp>

#include "thirdParty\TinyXML\tinyxml2.h"
#include "SpriteManager.h"
using namespace std;
struct Animation
{
	
	void AddFrame(Frame f);
	int GetFrameIndex();
	Frame& GetFrame();
	void SetFrame(int f);
	//returns the new frame index
	int IncrementFrame();
	
	int size();
	//Also increments the frame
	void Draw(sf::RenderWindow * window, SpriteManager * sprites);
private:
	int currentFrame;
	vector<Frame> frames;
};
class AnimationManager
{
public:
	AnimationManager();
	~AnimationManager(); 

	
	void LoadAnimations(string indexFile);

	sf::Texture * GetTexture(string key);

	map<string, Animation> animations;

	void Print();
	


};

