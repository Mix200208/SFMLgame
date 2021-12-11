
#include <SFML/Graphics.hpp>
#include "map.h"
#include "SpriteMap.h"
#include "GameText.h"
#include "GameTextBuilder.h"
#include "SpriteObj.h"
#include "Player.h"
#include <vector>
#include <iostream>
using namespace sf;


std::vector<std::vector<int>> map;
std::vector<std::vector<char>> mapObj;


void pushmap() {
	for (int i = 1; i < 9; i++) {
		for (int l = 1; l < 9; l++) {
			map.push_back({ l*42,i*42 });
		}
	}

}



void pushMapObj() {

	for (int i = 0; i < HEIGHT_MAP; i++)
	{
		for (int j = 0; j < WIDTH_MAP; j++) {
			if ((TitlerMap[i][j] == ' ')) 
				mapObj.push_back({ ' ' });
			
			if ((TitlerMap[i][j] == 's')) 
				mapObj.push_back({ 's' });
				
			if ((TitlerMap[i][j] == 'c')) 
				mapObj.push_back({ 'c' });

			if ((TitlerMap[i][j] == 'f'))
				mapObj.push_back({ 'f' });
		}
	}
	
}



int step = 0;

int main()
{
	int current_i = 0;

	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(840, 420), "SFML");
	SpriteObj borderSprite = SpriteObj("iglooAlt.png");
	SpriteObj blueIceSprite = SpriteObj("iceBlock.png");
	SpriteObj whiteIceSprite = SpriteObj("tundraCenter.png");
	SpriteObj treeSprite = SpriteObj("pineSapling.png");
	SpriteObj finishSprite = SpriteObj("iglooDoor.png");
	Player frPl = Player("rabbit.png");

	GameTextBuilder builder;
	GameText textFactTitle = builder.textTitleFacts("Titel");
	GameText textFrPlayer = builder.textPlayer("Player 1");
	GameText textFrPlStatus = builder.textTitleFacts("Status - Wait");
	GameText textScPlStatus = builder.textTitleFacts("Status - Going");
	GameText textScPlayer = builder.textPlayer("Player 2");

	textFrPlStatus.setPosition(440,80);
	textScPlStatus.setPosition(440,180);
	textFrPlayer.setPosition(560, 20);
	textScPlayer.setPosition(560, 120);
	textFactTitle.setPosition(550, 270);
	

	frPl.movePlayer(42,42);

	window.setKeyRepeatEnabled(false);
	pushmap();
	pushMapObj();
	window.setKeyRepeatEnabled(false);

	// загружаем картинку

	


	bool gameFinish = false;


	while (window.isOpen())
	{
		// Обрабатываем события в цикле
		Event event;

		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
				
				if (event.type == Event::Closed)

					// тогда закрываем его
					window.close();

					else if (event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
						srand(time(0));
						step = 1 + rand() % 4;
						textFactTitle.setText(std::to_string(step));
						current_i += step;
						
						if (current_i < 63 && gameFinish == false) {

							
							frPl.movePlayer(map[current_i][0], map[current_i][1]);
							frPl.checkObject(mapObj[current_i][0], current_i);
							frPl.movePlayer(map[current_i][0], map[current_i][1]);


					
						}
						else if(current_i >= 63 && gameFinish == false) {
							frPl.movePlayer(map[63][0], map[63][1]);
							gameFinish = true;
							
						}
						else {
							window.close();
						}
					}
				
		}

		// Установка цвета фона - белый
		window.clear(Color::White);
		textFrPlStatus.drawText(window);
		textScPlStatus.drawText(window);
		textScPlayer.drawText(window);
		textFrPlayer.drawText(window);
		textFactTitle.drawText(window);
		for (int i = 0; i < HEIGHT_MAP; i++)
		{
			for (int j = 0; j < WIDTH_MAP; j++) {
				if ((TitlerMap[i][j] == '0')) {
					borderSprite.drawSpriteObj(i * 42, j * 42, window);
				}
				if ((TitlerMap[i][j] == ' ')) {
					blueIceSprite.drawSpriteObj(i * 42, j * 42, window);
				}

				if ((TitlerMap[i][j] == 's')) {

					whiteIceSprite.drawSpriteObj(i * 42, j * 42, window);

				}

				if ((TitlerMap[i][j] == 'c')) {
					blueIceSprite.drawSpriteObj(i * 42, j * 42, window);
					treeSprite.drawSpriteObj(i * 42, j * 42, window);
				}

				if ((TitlerMap[i][j] == 'f')) {
					finishSprite.drawSpriteObj(i * 42, j * 42, window);
				
					
				}


			}
		}
	
		frPl.drawPlayer(window, 32,42);
		window.display();
	}

	return 0;
}


