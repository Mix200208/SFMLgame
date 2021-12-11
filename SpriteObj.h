#include <SFML/Graphics.hpp>
#pragma once
using namespace sf;
class SpriteObj
{
	private:
	
		Sprite* objSprite;
		Texture objTexture;
		Image objImage;

	public:

		SpriteObj(std::string imageSprite);
		void drawSpriteObj(int xPosition, int yPosition, RenderWindow& window);
		~SpriteObj();


};

