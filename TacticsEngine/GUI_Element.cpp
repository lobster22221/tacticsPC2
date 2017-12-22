#include "GUI_Element.h"
#include "Command.h"
GUI::GUI_Element::GUI_Element()
{
}

void GUI::GUI_Element::Draw(sf::RenderWindow * win)
{
	win->draw(this->Default_Style.panel);

	int pX = this->Default_Style.panel.getPosition().x;
	int pY = this->Default_Style.panel.getPosition().y;
	int pW = this->Default_Style.panel.getSize().x;
	int pH = this->Default_Style.panel.getSize().y;

	int lx, ly, lw, lh;
	

	this->label->setPosition(pX,pY,pW,pH);
	this->label->Draw(win);
}

//event
void GUI::GUI_Element::LoadMessage(tinyxml2::XMLElement * eventNode)
{
	const char * t = eventNode->Attribute("id");
	string s = t;
	int eIDi = stoi(s);
	GameEvent eID = (GameEvent)eIDi;

	switch (eID)
	{
	case NONE:
		break;
	case EVENT_DEBUG:
		break;
	case WINDOW_CLOSED:
		break;
	case EVENT_CLICK_LEFT:
		break;
	case EVENT_LOAD_STATE:
	{
		tinyxml2::XMLElement *child = eventNode->FirstChildElement();
		string value;
		const char * ctype = child->GetText();
		value = ctype;
		LoadStateEvent * lse = new LoadStateEvent();
		lse->state = stoi(value);
		OnClickMessage.EventType = EVENT_LOAD_STATE;
		this->OnClickMessage.EventData = lse;
	}
		break;
	default:
		break;
	}
	//Message->Property
	
	

}
