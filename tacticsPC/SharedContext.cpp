#include "SharedContext.h"
#include <fstream>
#include <sstream>
#include "Debug.h"
using namespace std;
namespace System
{

	SharedContext::SharedContext()
	{
		
	}


	SharedContext::~SharedContext()
	{
	}

	void SharedContext::Initiate(string masterFile)
	{
		LoadMasterFile(masterFile);
		CreateSystemWindow();
		CreateFontManager();
		this->MessageManager = new System::MessageHandler(Window);
		
	}

	void SharedContext::CreateSystemWindow()
	{
		string WindowFile = this->FileSources["WindowDefinition"];
		this->Window = new SystemWindow(WindowFile);
		
		Window->Create();
	}

	void SharedContext::CreateFontManager()
	{
		
		string FontFile = this->FileSources["FontSource"];		
		fontManager = new Render::FontManager();
		fontManager->Initiate(FontFile);
	}

	SystemWindow * SharedContext::GetWindow()
	{
		return Window;
	}

	Render::FontManager * SharedContext::GetFontManager()
	{
		return fontManager;
	}


	//populate resource sources
	void SharedContext::LoadMasterFile(string sharedFile)
	{
		std::ifstream fileStream;
		fileStream.open(sharedFile);

		if (fileStream.is_open())
		{
			Debug::Log(sharedFile + " Loaded\n");
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
				string context;
				string filename;
				tmp >> context >> filename;
				FileSources[context] = filename;
			}

		}
		else
		{
			Debug::ThrowError(ErrorCodes::FILE_NOT_FOUND, sharedFile);
		}
	}

};
		

