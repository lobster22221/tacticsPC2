#include "Gui_Controller.h"
#include <iostream>
#include <SFML/System.hpp>
#include "TextLine.h"

using namespace std;
GUI::GUI_Element_Factory::GUI_Element_Factory(StyleFactory * styleTemplate)
{
	styleCreator = styleTemplate;
	SetToTemplate(styleCreator);
	
}

GUI::GUI_Element_Factory::GUI_Element_Factory():GUI_Element_Factory(new StyleFactory())
{
	//Cals previous constructor
}

void GUI::GUI_Element_Factory::SetSize(sf::Vector2f size)
{
	NormalStyle.SetSize(size);
	HoverStyle.SetSize(size);
	ClickedStyle.SetSize(size);
}

void GUI::GUI_Element_Factory::SetPosition(sf::Vector2f position)
{
	NormalStyle.SetPosition(position);

	HoverStyle.SetPosition(position);

	ClickedStyle.SetPosition(position);
}

void GUI::GUI_Element_Factory::SetToTemplate(StyleFactory * newTemplate)
{
	styleCreator = newTemplate;
	NormalStyle = styleCreator->Create();
	HoverStyle = styleCreator->Create();
	ClickedStyle = styleCreator->Create();
}


GUI::Gui_Controller::Gui_Controller(System::SharedContext * context )
{
	this->context = context;
}

GUI::Gui_Controller::~Gui_Controller()
{
}

void GUI::Gui_Controller::Draw(sf::RenderWindow * win)
{
	for each(GUI::GUI_Element* drawable in GUI_Drawables)
	{
		drawable->Draw(win);
	}
}

void GUI::Gui_Controller::HandleMessages()
{
}

void GUI::Gui_Controller::Subscribe(GameEvent eventType)
{
}
Render::TextLine * GUI::Gui_Controller::LoadLabel(tinyxml2::XMLElement * n)
{
	
	sf::Color color;
	string textMessage = "";
	tinyxml2::XMLElement * Node = n->FirstChildElement();
	while (Node != nullptr)
	{
		string type;
		const char * ctype = Node->Value();
		type = ctype;
		
		if (type == "color")
		{
			color = LoadColor(Node);
		}

		if (type == "text")
		{
			cout << "Text: " << Node->GetText() << endl;
			textMessage = Node->GetText();
		}
		Node = Node->NextSiblingElement();
	}
	Render::TextLine *tl = context->GetFontManager()->CreateText(textMessage);
	tl->SetColor(color);
	return tl;
}
sf::Vector2f GUI::Gui_Controller::LoadPosition(tinyxml2::XMLElement * n)
{
	string s;
	int x, y;
	const char * xyt = n->Attribute("x");
	s = xyt;
	x = stoi(s);

	xyt = n->Attribute("y");
	s = xyt;
	y = stoi(s);

	cout << "X: " << x << ", Y: " << y << endl;
	return sf::Vector2f(x, y);
}

sf::Color GUI::Gui_Controller::LoadColor(tinyxml2::XMLElement * n)
{
	string s;
	int r, g, b, a;

	//get red
	const char * rgbat = n->Attribute("red");
	s = rgbat;
	r = stoi(s);

	//get green
	rgbat = n->Attribute("green");
	s = rgbat;
	g = stoi(s);

	//get blue
	rgbat = n->Attribute("blue");
	s = rgbat;
	b = stoi(s);

	//get alpha
	rgbat = n->Attribute("alpha");
	s = rgbat;
	a = stoi(s);
	cout << "Red: " << r << ", Green: " << g << ", Blue: " << b << ", Alpha: " << a << endl;
	return sf::Color(r, g, b, a);
}

sf::Vector2f GUI::Gui_Controller::LoadSize(tinyxml2::XMLElement * n)
{
	string s;
	int w, h;
	const char * wt = n->Attribute("width");
	s = wt;
	w = stoi(s);
	const char * ht = n->Attribute("height");
	s = ht;
	h = stoi(s);
	cout << "Width: " << w << ", height: " << h << endl;
	return sf::Vector2f(w, h);
}
void GUI::Gui_Controller::LoadElement(tinyxml2::XMLElement * n)
{
	GUI_Element * element = new GUI_Element();
	
	cout << "Create Button\n";
	const char * t = n->Attribute("id");
	string id = t;
	cout << "id: " << id << endl;
	element->guiID = id;
	tinyxml2::XMLElement *children = n->FirstChildElement();
	while (children != NULL)
	{
		cout << children->Value()<< ": ";
		
		const char * t = children->Value();
		string s = t;
		if (s == "size")
		{
			element->Default_Style.SetSize(LoadSize(children));
		}
		if (s == "color")
		{
			element->Default_Style.SetColor(LoadColor(children));
		}
		if (s == "position")
		{
			element->Default_Style.SetPosition(LoadPosition(children));
		}
		if (s == "label")
		{
			element->label = LoadLabel(children);
		}
		
		children = children->NextSiblingElement();
	}cout << endl << endl;
	this->ElementMap[id] = element;
	GUI_Drawables.push_back(element);
}

void GUI::Gui_Controller::LoadNode(tinyxml2::XMLElement * n)
{
	tinyxml2::XMLElement * Node = n->FirstChildElement();
	while (Node!=nullptr)
	{
		const char * t = Node->Attribute("type");
		if(t != NULL)
		{
			string s = t;
			//cout << s << endl;
			if (s == "Button")
			{
				LoadElement(Node);
			}
		}
		LoadNode(Node);
		Node = Node->NextSiblingElement();
	}

}

void GUI::Gui_Controller::LoadGUI(string guiFile)
{
	FILE file;
	
	tinyxml2::XMLDocument doc;
	if (!doc.LoadFile(guiFile.c_str()))
	{
		cout << doc.ErrorName() << endl;
		
	}

	//first child is <GUI>
	//tinyxml2::XMLElement * root = doc.FirstChildElement();
	//cout << root->Value() << "\n";
	//Gui is composed of a set of nodes, mostly menuse
	LoadNode(doc.RootElement());

}
