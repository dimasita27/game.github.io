#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <vector>
#include "map.h"



using namespace sf;
int X, Y, dir=0, a = 2000, b = 2000, c, d,P,T,rAnD;
bool gamewin=false, moveBest = false, movePlayer = false, isMove = true;



void hunterUpdate()
{
	if ((Keyboard::isKeyPressed(Keyboard::D)) && Map[a + 1][b] != 'b' && Map[a + 1][b] != 'p' && Map[a + 1][b] != '0' && Map[a + 1][b] != 't')
	{
		Map[a + 1][b] = 'p'; Map[a][b] = ' '; isMove = false; movePlayer = false;



	}
	if ((Keyboard::isKeyPressed(Keyboard::A)) && Map[a - 1][b] != 'b' && Map[a - 1][b] != 'p' && Map[a - 1][b] != '0' && Map[a - 1][b] != 't')
	{
		Map[a - 1][b] = 'p'; Map[a][b] = ' '; isMove = false; movePlayer = false;

	}
	if ((Keyboard::isKeyPressed(Keyboard::S)) && Map[a][b + 1] != 'b' && Map[a][b + 1] != 'p' && Map[a][b + 1] != '0' && Map[a][b + 1] != 't')
	{
		Map[a][b + 1] = 'p'; Map[a][b] = ' '; isMove = false; movePlayer = false;

	}
	if ((Keyboard::isKeyPressed(Keyboard::W)) && Map[a][b - 1] != 'b' && Map[a][b - 1] != 'p' && Map[a][b - 1] != '0' && Map[a][b - 1] != 't')
	{
		Map[a][b - 1] = 'p'; Map[a][b] = ' '; isMove = false; movePlayer = false;

	}
}
void bestUpdate( int lvl)
{
	while (!isMove) {

		if ((Map[X + 1][Y] == 'p' || Map[X + 1][Y] == '0') &&
			(Map[X - 1][Y] == 'p' || Map[X - 1][Y] == '0') &&
			(Map[X][Y + 1] == 'p' || Map[X][Y + 1] == '0') &&
			(Map[X][Y - 1] == 'p' || Map[X][Y - 1] == '0')) {

			 isMove = true;
		}
		
		rAnD = rand() % 4;
		switch (rAnD) {
		case 0: {
			if (Map[X + 1][Y] == 't') { gamewin = true; }
			if (Map[X + 1][Y] != 'p' && Map[X + 1][Y] != '0')
			{
				Map[X + 1][Y] = 'b'; Map[X][Y] = ' '; dir = 0; isMove = true; break;
			}
			gamewin = false;
		}
		case 1: {
			if (Map[X - 1][Y] == 't') { gamewin = true; }
			if (Map[X - 1][Y] != 'p' && Map[X - 1][Y] != '0')
			{
				Map[X - 1][Y] = 'b'; Map[X][Y] = ' '; dir = 1; isMove = true; break;
			}
			gamewin = false;
		}
		case 2: {
			if (Map[X][Y + 1] == 't') { gamewin = true; }
			if (Map[X][Y + 1] != 'p' && Map[X][Y + 1] != '0')
			{
				Map[X][Y + 1] = 'b'; Map[X][Y] = ' '; dir = 2; isMove = true; break;
			}
			gamewin = false;
		}
		case 3: {
			if (Map[X][Y - 1] == 't') { gamewin = true; }
			if (Map[X][Y - 1] != 'p' && Map[X][Y - 1] != '0')
			{
				Map[X][Y - 1] = 'b'; Map[X][Y] = ' '; dir = 3; isMove = true; break;
			}
			gamewin = false;
		}
		}

	}
}


int main()
{
	
	bool winOpen=true, resTart=false;
	std::cout << "Enter the number of hunters <= 10 = ";
	std::cin >> P;
	if (P > 10) {
		while (P > 10)
		{
			std::cout << "hunter <= 10 = ";
			std::cin >> P;
		}
	}
	std::cout << "Enter the number of traps <= 15 = ";
	std::cin >> T;
	if (T > 15) {
		while (T > 15)
		{
			std::cout << " trap < 15 ";
			std::cin >> T;
		}
	}
	while (winOpen) {
		resTart = false;
		gamewin = false;
			while (!resTart) {
				if (winOpen == false) break;
				srand(time(NULL));
				for (int i = 0; i < HEIGHT_MAP; i++)
				{
					for (int j = 0; j < WIDTH_MAP; j++)
					{
						if (i == 0 || j==0 || i==HEIGHT_MAP-1 || j==WIDTH_MAP-1 ) Map[i][j] = '0';
						else Map[i][j] = ' ';
					}
				}
				
				Sprite p[10];
				Image player;
				player.loadFromFile("C:\\GameTest\\NewGame\\Debug\\player.png");
				Texture playeR;
				playeR.loadFromImage(player);
				
				playerMap(P);
			
				trapMap(T);

				Font font,heLP;
				heLP.loadFromFile("C:\\GameTest\\NewGame\\Debug\\18429.ttf");
				font.loadFromFile("C:\\GameTest\\NewGame\\Debug\\18180.ttf");
				//font.loadFromFile("font.ttf");
				Text text("", font, 50),helP("",heLP,30);
				
				//text.setColor(Color::Red);
				Image best;
				best.loadFromFile("C:\\GameTest\\NewGame\\Debug\\best.png");
				Texture besT;
				besT.loadFromImage(best);
				Sprite map_besT;
				map_besT.setTexture(besT);
				for (int i = 0; i < P; i++) p[i].setTexture(playeR);
				
				bestMap();
				Image map_image;
				map_image.loadFromFile("C:\\GameTest\\NewGame\\Debug\\map.png");
				Texture map;
				map.loadFromImage(map_image);
				Sprite s_map;
				s_map.setTexture(map);
				

				///////////////////////////////
				RenderWindow window(VideoMode(768, 768), "SFML Works!");

			

				while (window.isOpen())
				{
					
					Vector2i pixelPos = Mouse::getPosition(window);
					Vector2f pos = window.mapPixelToCoords(pixelPos);
					
					
					Event event;
					while (window.pollEvent(event))
					{

						if (event.type == Event::Closed)
						{
							window.close();
							winOpen = false;
						}

						if (!gamewin) {
							if (event.type == Event::MouseButtonPressed)
								if (event.key.code == Mouse::Left)
									for (int i = 0; i < P; i++) {
										if (p[i].getGlobalBounds().contains(pos.x, pos.y))

										{
											a = (pos.x / 48);
											b = (pos.y / 48);
											c = a * 48;
											d = b * 48;

											movePlayer = true; 
										}
									}
						}
						for (int i = 0; i < P; i++) {
							if (p[i].getPosition().x == c && p[i].getPosition().y == d)
							{	
								p[i].setColor(Color::Red);
							}
							else p[i].setColor(Color::White);
						}

					}

					if (movePlayer && isMove)
					{
						hunterUpdate();
					}
					
					for (int i = 0; i < HEIGHT_MAP; i++)
					{
						for (int j = 0; j < WIDTH_MAP; j++)
						{
							if (Map[i][j] == 'b') { X = i; Y = j; }
						}
					}

					if (!isMove)
					{
						bestUpdate(2);
					}
					if (dir == 0) map_besT.setTextureRect(IntRect(143, 306, 41, 31));
					if (dir == 1) map_besT.setTextureRect(IntRect(146, 260, 41, 31));
					if (dir == 2) map_besT.setTextureRect(IntRect(155, 205, 30, 36));
					if (dir == 3) map_besT.setTextureRect(IntRect(155, 353, 30, 36));
				
					/////////////////
					window.clear();
					int k = 0;
					for (int i = 0; i < HEIGHT_MAP; i++)
					{
						for (int j = 0; j < WIDTH_MAP; j++)
						{

							
							if (Map[i][j] == 't') {
								s_map.setTextureRect(IntRect(329, 626, 32, 32));
								s_map.setPosition(i * 48, j * 48);
								window.draw(s_map);
							}
							else if (Map[i][j] == '0') {
								s_map.setTextureRect(IntRect(98, 263, 32, 32));
								s_map.setPosition(i * 48, j * 48);
								window.draw(s_map);
							}
							else if (Map[i][j] == 'p') {
								s_map.setTextureRect(IntRect(164, 429, 32, 32));
								s_map.setPosition(i * 48, j * 48);
								window.draw(s_map);
								p[k].setTextureRect(IntRect(17, 10, 32, 31));
								p[k].setPosition(i * 48, j * 48);
								window.draw(p[k]);

								k++;
							}
							else if (Map[i][j] == 'b') {
								s_map.setTextureRect(IntRect(164, 429, 32, 32));
								s_map.setPosition(i * 48, j * 48);
								window.draw(s_map);
								
								map_besT.setPosition(i * 48, j * 48);
								window.draw(map_besT);
							}
							else {
								s_map.setTextureRect(IntRect(164, 429, 32, 32));
								s_map.setPosition(i * 48, j * 48);
								window.draw(s_map);
							}
						}


					}
					
					text.setString("      You Win !!!\n Congratulations!");
					helP.setString("To start the game, press: enter \n To close the game, click: cross ");
					text.setPosition(125,300);
					if (Keyboard::isKeyPressed(Keyboard::Tab)) window.draw(helP);
					if (gamewin) window.draw(text);
					
					window.display();
					
					if (Keyboard::isKeyPressed(Keyboard::Enter)) {
						resTart = true; break;
					}

				}

				
			}
			
	}
	return 0;
}

