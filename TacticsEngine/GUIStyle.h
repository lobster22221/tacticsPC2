#pragma once
#include <SFML\Graphics.hpp>
namespace GUI
{
	class GUI_Element;

	class GUIStyle
	{
		friend GUI_Element;
	public:
		GUIStyle() {}
		GUIStyle(sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Texture * texture)
		{
			SetSize(size);
			SetPosition(position);
			SetColor(color);
			SetTexture(texture);

		}
		~GUIStyle();

		void SetSize(sf::Vector2f size);
		void SetPosition(sf::Vector2f position);
		void SetColor(sf::Color color);
		void SetTexture(sf::Texture * texture);
		void clearTexture();

	protected:
		sf::RectangleShape panel;
		sf::Vector2f size;
		sf::Vector2f position;
		sf::Color color;
		sf::Texture * texture;
	};

	class StyleFactory
	{
	public:
		StyleFactory()
		{
			size.x = size.y = 100;
			position.x = position.y = 0;
			color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
			texture = NULL;
		}
		sf::Vector2f size;
		sf::Vector2f position;
		sf::Color color;
		sf::Texture * texture;

		GUIStyle Create()
		{
			return GUIStyle(size, position, color, texture);
		}
	};
}