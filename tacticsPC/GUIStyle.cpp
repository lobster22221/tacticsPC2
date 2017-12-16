#include "GUIStyle.h"

namespace GUI
{



	GUIStyle::~GUIStyle()
	{
	}

	void GUIStyle::SetSize(sf::Vector2f size)
	{
		panel.setSize(size);
	}

	void GUIStyle::SetPosition(sf::Vector2f position)
	{
		panel.setPosition(position);
	}

	void GUIStyle::SetColor(sf::Color color)
	{
		panel.setFillColor(color);
	}

	void GUIStyle::SetTexture(sf::Texture * texture)
	{
		panel.setTexture(texture);
	}

	void GUIStyle::clearTexture()
	{
		panel.setTexture(NULL);
	}

}