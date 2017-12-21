#pragma once
#include <map>
#include <string>
#include "SystemWindow.h"
#include "FontManager.h"
#include "MessageHandler.h"
#include "TextureManager.h"
#include "SpriteManager.h"
#include "AnimationManager.h"
using namespace std;
namespace System
{
	class SharedContext
	{
	public:
		SharedContext();
		~SharedContext();

		void Initiate(string masterFile);
		
		//Initialize systems
		void CreateSystemWindow();
		void CreateFontManager();
		void CreateGraphics();

		SystemWindow * GetWindow();
		Render::FontManager *GetFontManager();
		TextureManager * GetTextures();
		SpriteManager * GetSprites();
		AnimationManager * GetAnimations();
		System::MessageHandler * GetMessenger() { return MessageManager; }

		//set to true to exit
		bool end = false;
	private:
		void LoadMasterFile(string file);
		map<string, string> FileSources;	//Tells the engine where to load files
		SystemWindow * Window;

		//systems
		Render::FontManager * fontManager;
		MessageHandler * MessageManager;

		//ResourceLoaders
		TextureManager * Textures;
		SpriteManager * Sprites;
		AnimationManager * Animations;
	};
}

