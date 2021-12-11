
#include <iostream>
#include <SFML/Graphics.hpp>
#pragma once
using namespace sf;

class GameText
{
	private:
		Font font;
		Text text;

	public:
		GameText(std::string nameFont, std::string text, int size_character, sf::Color color,sf::Text::Style style);
		void setPosition(int xCoordynate, int yCoordynate);
		void drawText(RenderWindow& window);
		void setText(std::string text);

};

