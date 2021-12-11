#include "GameText.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#pragma once
using namespace sf;

GameText::GameText(std::string nameFont, std::string text, int size_character, sf::Color color,sf::Text::Style style)
{
	this->font.loadFromFile(nameFont);
	this->text.setFont(this->font);
	this->text.setCharacterSize(size_character);
	this->text.setString(text);
	this->text.setStyle(style);
	this->text.setFillColor(color);

}


void GameText::setPosition(int xCoordynate, int yCoordynate)
{
	this->text.setPosition(xCoordynate,yCoordynate);
}

void GameText::drawText(RenderWindow& window)
{
	window.draw(this->text);
}

void GameText::setText(std::string text)
{
	this->text.setString(text);
}


