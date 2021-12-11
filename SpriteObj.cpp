#include "SpriteObj.h"
#include <SFML/Graphics.hpp>
using namespace sf;
SpriteObj::SpriteObj(std::string imageSprite)
{
	this->objSprite = new Sprite();
	this->objImage.loadFromFile(imageSprite);
	this->objTexture.loadFromImage(objImage);
	this->objSprite->setTexture(objTexture);

}

void SpriteObj::drawSpriteObj(int xPosition, int yPosition, RenderWindow& window)
{
	objSprite->setTextureRect(IntRect(0, 0, 42, 42));
	objSprite->setPosition(xPosition, yPosition);
	window.draw(*objSprite);

}

SpriteObj::~SpriteObj()
{
	delete objSprite;
}
