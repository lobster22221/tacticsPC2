#pragma once
#include <SFML\Graphics.hpp>
#include <string>
#include <fstream>
using namespace std;
namespace System
{
	class SystemWindow
	{
	public:
		SystemWindow(string windowFile);
		~SystemWindow();

		void LoadParameters(string windowFile);
		void SetParameters(int width, int height, string caption, bool fullScreen);
		void Create();
		void Draw(sf::Drawable& d);
		sf::RenderWindow * GetWindow() { return &GameWindow; };
		int GetWidth();
		int GetHeight();
	private:
		bool setUp;

		int width, height;
		bool fullScreen;
		string caption;
sf::RenderWindow GameWindow;
		sf::Uint32 style;
	};

}
