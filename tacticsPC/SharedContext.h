#pragma once
#include <map>
#include <string>
#include "SystemWindow.h"
#include "FontManager.h"
#include "MessageHandler.h"
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
		
		SystemWindow * GetWindow();
		Render::FontManager *GetFontManager();
		System::MessageHandler * GetMessenger() { return MessageManager; }
	private:
		void LoadMasterFile(string file);
		map<string, string> FileSources;	//Tells the engine where to load files
		SystemWindow * Window;

		//systems
		Render::FontManager * fontManager;
		MessageHandler * MessageManager;

	};
}

