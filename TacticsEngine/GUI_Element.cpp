#include "GUI_Element.h"

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
