#include "GUI_Element.h"

GUI::GUI_Element::GUI_Element()
{
}

void GUI::GUI_Element::Draw(sf::RenderWindow * win)
{
	win->draw(this->Default_Style.panel);
	this->label->SetPosition(this->Default_Style.panel.getPosition().x, this->Default_Style.panel.getPosition().y);
	this->label->Draw(win);
}
