#pragma once
#include <string>
#include <SFML\Graphics.hpp>
using namespace std;
class Frame
{
public:
	Frame();
	~Frame();

	string spriteID;
	sf::IntRect frame;
};

