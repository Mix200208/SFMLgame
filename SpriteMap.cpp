#include "SpriteMap.h"
#include <SFML/Graphics.hpp>


using namespace sf;


SpriteMap::SpriteMap(Sprite* waterSprite, Sprite* woodSprite, Sprite* beachSprite, Sprite* cloudSprite) {
	this->waterSprite = waterSprite;
	this->woodSprite = woodSprite;
	this->beachSprite = beachSprite;
	this->cloudSprite = cloudSprite;
};

void SpriteMap::drawWaterSprite(int xPosition, int yPosition, RenderWindow& window) {
	waterSprite->setTextureRect(IntRect(0, 0, 42, 42));
	waterSprite->setPosition(xPosition, yPosition);
	window.draw(*waterSprite);
}

void SpriteMap::drawWoodSprite(int xPosition, int yPosition, RenderWindow& window) {
	woodSprite->setTextureRect(IntRect(0, 0, 42, 42));
	woodSprite->setPosition(xPosition, yPosition);
	window.draw(*woodSprite);
}

void SpriteMap::drawBeachSprite(int xPosition, int yPosition, RenderWindow& window) {
	beachSprite->setTextureRect(IntRect(0, 0, 42, 42));
	beachSprite->setPosition(xPosition, yPosition);
	window.draw(*beachSprite);
}

void SpriteMap::drawCloudSprite(int xPosition, int yPosition, RenderWindow& window) {
	cloudSprite->setTextureRect(IntRect(0, 0, 42, 42));
	cloudSprite->setPosition(xPosition, yPosition);
	window.draw(*cloudSprite);
}

SpriteMap:: ~SpriteMap() {
	delete woodSprite, waterSprite, beachSprite,cloudSprite;
}



