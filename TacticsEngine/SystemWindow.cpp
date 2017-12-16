#include "SystemWindow.h"
#include <iostream>
#include "Debug.h"
using namespace std;
namespace System
{

	SystemWindow::SystemWindow(string windowFile)
	{
		//Cannot create window until parameters are set
		setUp = false;

		//Load paramters from the file
		LoadParameters(windowFile);
	}


	SystemWindow::~SystemWindow()
	{
	}

	void SystemWindow::LoadParameters(string windowFile)
	{
		std::ifstream fileStream;
		fileStream.open(windowFile);
		string delimiter = "|";
		if (fileStream.is_open())
		{
			Debug::Log(windowFile + " Loaded\n");
			string line;
			bool line1 = true;
			while (getline(fileStream, line))
			{
				if(line[0] == '|' || line.empty())
				{
					continue;
				}
				stringstream tmp(line);
				if (line1)
				{
					try
					{
						int fsBool;
						tmp >> width >> height >> fsBool;
						fullScreen = (fsBool == 1);
						line1 = false;
					}
					catch (exception e)
					{
						Debug::ThrowError(ErrorCodes::FILE_READ_ERROR);
					}
					
				}
				else
				{
					this->caption += line;
					setUp = true;
				}

			}
		}
		else
		{
			Debug::ThrowError(ErrorCodes::FILE_NOT_FOUND, windowFile);
		}
	}

	void SystemWindow::SetParameters(int width, int height, string caption, bool fullScreen)
	{
		this->width = width;
		this->height = height;
		this->caption = caption;
		this->fullScreen = fullScreen;
		
		setUp = true;

	}

	void SystemWindow::Create()
	{
		if (!setUp)
		{
			Debug::ThrowError(ErrorCodes::WINDOW_NO_CREATION, "Window parameters have not been set");
		}
		sf::Uint32 style = sf::Style::Default;
		if (fullScreen) { style = sf::Style::Fullscreen; }
		GameWindow.create(sf::VideoMode(width,height, 32), caption, style);
	}

	void SystemWindow::Draw(sf::Drawable& d)
	{
		GameWindow.draw(d);
	}

	int SystemWindow::GetWidth()
	{
		return width;
	}

	int SystemWindow::GetHeight()
	{
		return height;
	}

};