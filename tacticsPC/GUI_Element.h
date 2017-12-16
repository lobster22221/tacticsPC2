#pragma once
#include "GUIStyle.h"
#include <string>
#include "TextLine.h"
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

		bool Active = true;
		string guiID;
		Render::TextLine * label;
	};

}
