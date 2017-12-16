#pragma once
#include "MessageHandler.h"
#include "GUI_Element.h"
#include "thirdParty\TinyXML\tinyxml2.h"
#include "SystemWindow.h"
#include "SharedContext.h"
namespace GUI
{
	class GUI_Element_Factory
	{
		GUI_Element_Factory(StyleFactory * styleTemplate);
		GUI_Element_Factory();
		//Modifies factory
		void SetSize(sf::Vector2f size);
		void SetPosition(sf::Vector2f position);
		void SetToTemplate(StyleFactory * newTemplate);
	private:
		GUIStyle NormalStyle;
		GUIStyle HoverStyle;
		GUIStyle ClickedStyle;
		StyleFactory * styleCreator;


		//Standardize Size and position among styles		
		GUI_Element * CreateGuiElement()
		{
			GUI_Element * element = new GUI_Element();
			element->Click_Style = ClickedStyle;
			element->Default_Style = NormalStyle;
			element->Hover_Style = HoverStyle;
			return element;
		}
	};


	class Gui_Controller :
		public System::Listener
	{
	public:
		
		Gui_Controller(System::SharedContext * context);
		~Gui_Controller();

		void Draw(sf::RenderWindow * win);
		void HandleMessages();


		void Subscribe(GameEvent eventType);

		Render::TextLine *LoadLabel(tinyxml2::XMLElement * n);

		sf::Vector2f LoadPosition(tinyxml2::XMLElement * n);

		sf::Color LoadColor(tinyxml2::XMLElement * n);
		
		sf::Vector2f LoadSize(tinyxml2::XMLElement * n);

		void LoadElement(tinyxml2::XMLElement * n);
		void LoadNode(tinyxml2::XMLElement * n);		
		void LoadGUI(string guiFile);

		GUI_Element_Factory * GetElementCreator();
		StyleFactory * GetStyleFactory();


		map<string, GUI_Element*> ElementMap;
		vector<GUI_Element *> GUI_Drawables;
		System::SharedContext * context;
	};


};
