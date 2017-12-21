#include "AnimationManager.h"
#include <iostream>
#include "Debug.h"
AnimationManager::AnimationManager()
{
}


AnimationManager::~AnimationManager()
{
}

void Animation::AddFrame(Frame f)
{
	if (GetFrameIndex() < 0)
	{
		SetFrame(0);
	}
	this->frames.push_back(f);
}

int Animation::GetFrameIndex()
{
	return currentFrame;
}

Frame& Animation::GetFrame()
{
	return frames[currentFrame];
}

void Animation::SetFrame(int f)
{
	currentFrame = f;
	if (currentFrame >= frames.size())
	{
		currentFrame = 0;
	}
	if (currentFrame < 0)
	{
		currentFrame = 0;
	}
}

int Animation::IncrementFrame()
{
	SetFrame(currentFrame + 1);
	return currentFrame;
}

int Animation::size()
{
	return frames.size();
}

void Animation::Draw(sf::RenderWindow * window, SpriteManager * sprites)
{
	sprites->GeSprite(frames[currentFrame].spriteID)->Sprite.setTextureRect(frames[currentFrame].frame);
	window->draw(sprites->GeSprite(frames[currentFrame].spriteID)->Sprite);
	IncrementFrame();
}

void AnimationManager::LoadAnimations(string indexFile)
{
	FILE file;
	tinyxml2::XMLDocument doc;
	if (!doc.LoadFile(indexFile.c_str()))
	{
		cout << doc.ErrorName() << endl;

	}
	//root->Animation
	tinyxml2::XMLElement * animationNode = doc.RootElement()->FirstChildElement();

	while (animationNode != nullptr)
	{
		//load animation
		const char * t = animationNode->Attribute("id");
		string animationID = "loadError";
		if (t == NULL)
		{
			Debug::ThrowError(ErrorCodes::FILE_READ_ERROR);
			return;
		}
		//cast to string
		animationID  = t;		
		Animation a;
		//root->animation->frame
		tinyxml2::XMLElement * frameNode = animationNode->FirstChildElement();
		while (frameNode != nullptr)
		{
			const char * cSpriteID = frameNode->Attribute("spriteID");
			const char * cX = frameNode->Attribute("x");
			const char * cY = frameNode->Attribute("y");
			const char * cW = frameNode->Attribute("width");
			const char * cH = frameNode->Attribute("height");

			string sid = cSpriteID;
			int x = stoi(cX);
			int y = stoi(cY);
			int w = stoi(cW);
			int h = stoi(cH);

			Frame frame;
			frame.frame = sf::IntRect(x, y, w, h);
			frame.spriteID = sid;
			a.AddFrame(frame);	
			frameNode = frameNode->NextSiblingElement();
		}		
			animations[animationID] = a;
			animationNode = animationNode->NextSiblingElement();
	}
	Print();
}

void AnimationManager::Print()
{
	for (auto &x : animations)
	{
		cout << "Animations: "
			<< x.first << x.second.GetFrame().spriteID << endl;
	}
}

