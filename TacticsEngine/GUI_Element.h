#pragma once
#include "GUIStyle.h"
#include <string>
#include "TextLine.h"
#include "Command.h"
using namespace std;
namespace GUI
{
	enum GUI_TYPES
	{
		GUI_BUTTON,
		GUI_MENU,
	};
	enum GUIState
	{
		Default,
		Hover,
		Click,
		Disabled,
		Hover_Disabled,
		Click_Disabled
	};
	//interactable gui item
	class GUI_Element
	{
	public:
		GUI_Element();
		~GUI_Element();

		void Draw(sf::RenderWindow *win);

		GUIStyle Default_Style;
		GUIStyle Hover_Style;
		GUIStyle Click_Style;

		bool WasClicked(int x, int y)
		{
			if (Clickable)
			{				
				return this->Default_Style.panel.getGlobalBounds().contains(sf::Vector2f(x, y));
			}
			else
			{
				return false;
			}
		}

		EventMessage Click(int x, int y)
		{
			return OnClickMessage;

		}
		bool Active = true;
		string guiID;
		Render::TextLine * label;

		bool Clickable;
		EventMessage OnClickMessage;
		
	};

}
