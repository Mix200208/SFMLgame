
#include <SFML/Graphics.hpp>
#include "map.h"
#include "SpriteMap.h"
#include "GameText.h"
#include "GameTextBuilder.h"
#include "SpriteObj.h"
#include "Player.h"
#include <vector>
#include <map>
#include <iostream>
using namespace sf;


std::vector<std::vector<int>> map;





std::map <std::vector<int>, std::string> mapObCoord = { 
	{{126,42},"s"},{{210,42},"s" },{{294,42},"c"},{{336,42},"s"},
	{{84,84},"s"},{{126,84},"c"},{{252,84},"s"},
	{{126,126},"s"},{{336,126},"s"}, 
	{{210 ,168},"s"}, {{336 ,168},"s"},
	{{42 ,210},"s"},{{126 ,210},"c"},{{252 ,210},"c"},{{294 ,210},"s"},
	{{84 ,252},"s"},{ {168 ,252},"s"},{ {336 ,252},"s"},
	{ {210 ,294},"s"},{ {294 ,294},"s"},
	{{42 ,336},"s" } };




bool check(std::vector<int> vec) {

	bool check = false;
	for (auto it = mapObCoord.begin(); it != mapObCoord.end(); it++) {
		if (it->first == vec) {
			check = true;
		}
	}

	return check;

}



void pushmap() {
	for (int i = 1; i < 9; i++) {
		for (int l = 1; l < 9; l++) {
			map.push_back({ l*42,i*42 });
		}
	}

}






int step = 0;

int main()
{
	int current_iFrPlayer = 0;
	int current_iSCPlayer = 0;
	bool firstStep = true;
	bool frPlayerStep = true;


	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(840, 420), "SFML");
	SpriteObj borderSprite = SpriteObj("iglooAlt.png");
	SpriteObj blueIceSprite = SpriteObj("iceBlock.png");
	SpriteObj whiteIceSprite = SpriteObj("tundraCenter.png");
	SpriteObj treeSprite = SpriteObj("pineSapling.png");
	SpriteObj finishSprite = SpriteObj("iglooDoor.png");
	Player frPl = Player("rabbit.png");
	Player scPl = Player("penguin.png");

	GameTextBuilder builder;
	GameText textStepTitle = builder.textTitleFacts("Step : ");
	textStepTitle.setTextColor(Color::Black);
	GameText textFactTitle = builder.textTitleFacts("0");
	textFactTitle.setTextColor(Color::Black);
	GameText textFrPlayer = builder.textPlayer("Player 1");
	GameText textFrPlStatus = builder.textTitleFacts("Status - Going");
	GameText textScPlStatus = builder.textTitleFacts("Status - Wait");
	GameText textScPlayer = builder.textPlayer("Player 2");

	textFrPlStatus.setPosition(440,80);
	textScPlStatus.setPosition(440,180);
	textFrPlayer.setPosition(440, 20);
	textScPlayer.setPosition(440, 120);
	textStepTitle.setPosition(500, 280);
	textFactTitle.setPosition(680, 280);
	
	
	frPl.movePlayer(42,42);
	scPl.movePlayer(42, 0);
	window.setKeyRepeatEnabled(false);
	pushmap();
	
	window.setKeyRepeatEnabled(false);
	std::cout << check(map[2]) << std::endl;
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

				if (firstStep) {
					current_iFrPlayer += step;
					if (check(map[current_iFrPlayer])) {
						frPl.checkObject(mapObCoord[map[current_iFrPlayer]], current_iFrPlayer);
					}
					frPl.movePlayer(map[current_iFrPlayer][0], map[current_iFrPlayer][1]);
					scPl.movePlayer(42, 42);
					firstStep = false;
					frPlayerStep = false;
					textFrPlStatus.setText("Status - Wait");
					textScPlStatus.setText("Status - Going");
				}
				else {

					if (frPlayerStep) {

						current_iFrPlayer += step;

						if (current_iFrPlayer < 63 && gameFinish == false) {
							if (check(map[current_iFrPlayer])) {
								frPl.checkObject(mapObCoord[map[current_iFrPlayer]], current_iFrPlayer);
							}
							frPl.movePlayer(map[current_iFrPlayer][0], map[current_iFrPlayer][1]);
							frPlayerStep = false;

							textFrPlStatus.setText("Status - Wait");
							textScPlStatus.setText("Status - Going");

						}
						else if (current_iFrPlayer >= 63 && gameFinish == false) {
							frPl.movePlayer(map[63][0], map[63][1]);
							gameFinish = true;
							frPlayerStep = true;
							textFrPlStatus.setTextColor(Color::Green);
							textScPlStatus.setTextColor(Color::Red);
							textFrPlStatus.setText("Win game");
							textScPlStatus.setText("Lose Game");

						}
						else {
							window.close();
						}
					}
					else {

						current_iSCPlayer += step;

						if (current_iSCPlayer < 63 && gameFinish == false) {
							if (check(map[current_iSCPlayer])) {
								scPl.checkObject(mapObCoord[map[current_iSCPlayer]], current_iSCPlayer);
							}
							scPl.movePlayer(map[current_iSCPlayer][0], map[current_iSCPlayer][1]);

							frPlayerStep = true;
							textFrPlStatus.setText("Status - Going");
							textScPlStatus.setText("Status - Wait");
						}
						else if (current_iSCPlayer >= 63 && gameFinish == false) {
							scPl.movePlayer(map[63][0], map[63][1]);
							gameFinish = true;
							frPlayerStep = false;
							textFrPlStatus.setTextColor(Color::Red);
							textScPlStatus.setTextColor(Color::Green);
							textFrPlStatus.setText("Lose game");
							textScPlStatus.setText("Win Game");

						}
						else {
							window.close();
						}

					}
				}

			}
				
		}

		// Установка цвета фона - белый
		window.clear(Color::White);
		textFrPlStatus.drawText(window);
		textStepTitle.drawText(window);
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

				if ((TitlerMap[i][j] == 'l')) {
					blueIceSprite.drawSpriteObj(i * 42, j * 42, window);
					treeSprite.drawSpriteObj(i * 42, j * 42, window);
				}

				if ((TitlerMap[i][j] == 'f')) {
					finishSprite.drawSpriteObj(i * 42, j * 42, window);
				
					
				}


			}
		}
	
		frPl.drawPlayer(window, 32,42);
		scPl.drawPlayer(window, 42, 42);
		window.display();
	}

	return 0;
}


