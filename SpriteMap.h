
#include <SFML/Graphics.hpp>
#pragma once
using namespace sf;

class SpriteMap
{
	private:
		Sprite* waterSprite;
		Sprite* woodSprite;
		Sprite* beachSprite;
		Sprite* cloudSprite;
	public:

		SpriteMap(Sprite* waterSprite, Sprite* woodSprite, Sprite* beachSprite, Sprite * cloudSprite);

		void drawWaterSprite(int xPosition, int yPosition, RenderWindow& window);

		void drawWoodSprite(int xPosition, int yPosition, RenderWindow& window);

		void drawBeachSprite(int xPosition, int yPosition, RenderWindow& window);

		void drawCloudSprite(int xPosition, int yPosition, RenderWindow& window);

		~SpriteMap();

};


	





