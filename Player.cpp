#include "Player.h"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

Player::Player(std::string imageName)
{
	this->playerSprite = new Sprite();
	this->playerImage.loadFromFile(imageName);
	this->playerTexture.loadFromImage(this->playerImage);
	this->playerSprite->setTexture(this->playerTexture);

}

void Player::movePlayer(int xCoordinate, int yCoordinate)
{
	this->playerSprite->setPosition(xCoordinate, yCoordinate);

}

void Player::checkObject(std::string object, int &currentIndex )
{
	if (object=="s") {
			currentIndex -= 1;
			std::cout << "s" << std::endl;
	}

	if (object == "c") {
		currentIndex += 3;
		std::cout << "c" << std::endl;
	}

	
}

void Player::drawPlayer( RenderWindow& window, int height, int  width)
{
	playerSprite->setTextureRect(IntRect(0, 0, height, width));
	
	window.draw(*playerSprite);

}

Sprite* Player::getSprite()
{
	return this->playerSprite;
}




