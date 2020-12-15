#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cstdlib>
#include <utility>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <ostream>
#include <sstream>
#include "Background.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "Mainmenu.h"
#include "Gameover.h"
#include "PauseMenu.h"
#include "Item.h"
#include "DropItem.h"


std::vector<std::pair<std::string, int>> vec;
bool sortbysecdesc(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b);


using namespace std;
int main()
{
	//window
	sf::RenderWindow window(sf::VideoMode(1000, 768), "OverWhelm!", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);
	sf::Clock clock,clock2,clock3;
	

	//variable
	float deltatime = 0.0f;
	float firerate = 0;
	float debounce = 0;
	int enemySpawnTimer = 0;
	int itemSpawnTimer = 0;
	int CountBulletEnemymini = 0;
	long long int score = 0;
	int blood = 6;
	int counter = 0;
	int iscollision = 0;
	int timeItem = 20;
	bool flag[10];
		for (size_t i = 0; i <= 9; i++)
		{
			flag[i] = true;
		}
	float CountTime = 0;
	int slide = 0;
	int Mainmenustate = 3; //0 = not display , 1,3 = display
	int GameOverstate = 1; //1 = not display , 0 = display
	int Pausemenustate = 0; //0 = not display , 1 = display
	int Howtoplaystate = 0; //0 = not displlay , 1= display
	int Soundstate = 1; //0 = not play , 1 = play
	int Namestate = 0; //0 = not display , 1 = display

	srand(time(NULL));

	sf::Font font;
	font.loadFromFile("font/fontscore.ttf");

//background
	sf::Texture bgTexture[2];
	bgTexture[0].loadFromFile("wallpaper/stage1.jpg");
	bgTexture[1].loadFromFile("wallpaper/stage1.jpg");
	vector<Background> backgrounds;
	backgrounds.push_back(Background(&bgTexture[0], -125.f));
	backgrounds.push_back(Background(&bgTexture[1], -125.f));
	Player player(sf::Vector2f(0.f, 400.f));


//main menu
	Mainmenu mainmenu(600,600);
	sf::Texture soundimage;
	soundimage.loadFromFile("mainmenu/sound.png");
	sf::Sprite sound(soundimage);
	sound.setPosition(940, 710);
	int positionsoundX = soundimage.getSize().x / 2;
	int positionsoundY = soundimage.getSize().y;


//pause menu
	PauseMenu pausemenu(sf::Vector2f(900.f, 0.f));


//sound
	//background started
	sf::Music level1;
	level1.openFromFile("sound/level1.WAV");
	level1.setLoop(true);
	level1.setVolume(25);
		
	//background
	sf::Music startmusic;
	startmusic.openFromFile("sound/start.WAV");
	startmusic.setLoop(true);
	startmusic.play();
	startmusic.setVolume(25);

	

//soundeffect player
	sf::SoundBuffer shootingeffect;
	shootingeffect.loadFromFile("sound/shot-1.WAV");
	sf::Sound soundbullet;
	soundbullet.setBuffer(shootingeffect);


//bullets
	//bulletPlayers
	sf::Texture bulletB;
	bulletB.loadFromFile("bullet/bulletBlue.png");
	Bullet Bulletblue(&bulletB);
	Bulletblue.Sprite_bullet.setScale(0.8, 0.8);
	vector<Bullet> bullets;


//bulletItems
	sf::Texture bulletR;
	bulletR.loadFromFile("bullet/bulletRed.png");
	Bullet Bulletred(&bulletR);
	Bulletred.Sprite_bullet.setScale(0.8, 0.8);

	sf::Texture bulletG;
	bulletG.loadFromFile("bullet/bulletGreen.png");
	Bullet Bulletgreen(&bulletG);
	Bulletgreen.Sprite_bullet.setScale(0.8, 0.8);

	sf::Texture bulletY;
	bulletY.loadFromFile("bullet/bulletYellow.png");
	Bullet Bulletyellow(&bulletY);
	Bulletyellow.Sprite_bullet.setScale(0.8, 0.8);


//friutsItem
	sf::Texture banana;
	banana.loadFromFile("item/banana.png");
	DropItem Fruititem1(&banana);
	vector<DropItem> Itembanana;
	sf::Texture cherry;
	cherry.loadFromFile("item/cherry.png");
	DropItem Fruititem2(&cherry);
	vector<DropItem> Itemcherry;
	sf::Texture grape;
	grape.loadFromFile("item/grape.png");
	DropItem Fruititem3(&grape);
	vector<DropItem> Itemgrape;
	sf::Texture watermelon;
	watermelon.loadFromFile("item/watermelon.png");
	DropItem Fruititem4(&watermelon);
	vector<DropItem> Itemwatermelon;


//enemies
	sf::Texture enemySmallOrange;
	enemySmallOrange.loadFromFile("enemy/mini1.png");
	Enemy Enemymini1(&enemySmallOrange);
	vector<Enemy> enemies1;

	sf::Texture enemySmallArmy;
	enemySmallArmy.loadFromFile("enemy/mini2.png");
	Enemy Enemymini2(&enemySmallArmy);
	vector<Enemy> enemies2;

	sf::Texture enemyMediumOrange;
	enemyMediumOrange.loadFromFile("enemy/medium1.png");
	Enemy Enemymedium1(&enemyMediumOrange);
	vector<Enemy> enemies3;

	sf::Texture enemyMediumPink;
	enemyMediumPink.loadFromFile("enemy/medium2.png");
	Enemy Enemymedium2(&enemyMediumPink);
	vector<Enemy> enemies4;
	
	sf::Texture enemyBigPurWhite;
	enemyBigPurWhite.loadFromFile("enemy/bigg.png");
	Enemy1 Enemybig1(enemyBigPurWhite, sf::Vector2i(1, 2));
	vector<Enemy1> enemies5;


//heart
	sf::Texture blood0;
	blood0.loadFromFile("blood/full.png");
	sf::Sprite bloodfull;
	bloodfull.setTexture(blood0);
	bloodfull.setPosition(60, 670);
	bloodfull.setScale(0.8, 0.8);
	sf::Texture blood1;
	blood1.loadFromFile("blood/1.png");
	sf::Sprite bloodHalfFirst;
	bloodHalfFirst.setTexture(blood1);
	bloodHalfFirst.setPosition(60, 670);
	bloodHalfFirst.setScale(0.8, 0.8);
	sf::Texture blood2;
	blood2.loadFromFile("blood/2.png");
	sf::Sprite bloodFirst;
	bloodFirst.setTexture(blood2);
	bloodFirst.setPosition(60, 670);
	bloodFirst.setScale(0.8, 0.8);
	sf::Texture blood3;
	blood3.loadFromFile("blood/3.png");
	sf::Sprite bloodHalfnd;
	bloodHalfnd.setTexture(blood3);
	bloodHalfnd.setPosition(60, 670);
	bloodHalfnd.setScale(0.8, 0.8);
	sf::Texture blood4;
	blood4.loadFromFile("blood/4.png");
	sf::Sprite bloodnd;
	bloodnd.setTexture(blood4);
	bloodnd.setPosition(60, 670);
	bloodnd.setScale(0.8, 0.8);
	sf::Texture blood5;
	blood5.loadFromFile("blood/5.png");
	sf::Sprite bloodHalfrd;
	bloodHalfrd.setTexture(blood5);
	bloodHalfrd.setPosition(60, 670);
	bloodHalfrd.setScale(0.8, 0.8);
	sf::Texture bloodrd;
	bloodrd.loadFromFile("blood/empty.png");
	sf::Sprite bloodempty;
	bloodempty.setTexture(bloodrd);
	bloodempty.setPosition(60, 670);
	bloodempty.setScale(0.8, 0.8);
	

//itemshoot
	sf::Texture itemGreen;
	itemGreen.loadFromFile("item/itemshootgreen.png");
	Item Itemshoot_G(itemGreen , sf::Vector2i( 1 , 7));
	vector<Item> Item1;
	sf::Texture itemYellow;
	itemYellow.loadFromFile("item/itemshootyellow.png");
	Item Itemshoot_Y(itemYellow, sf::Vector2i(1, 7));
	vector<Item> Item2;
	sf::Texture itemRed;
	itemRed.loadFromFile("item/itemshootred.png");
	Item Itemshoot_R(itemRed, sf::Vector2i(1, 7));
	vector<Item> Item3;

//name 
	sf::Text name;
	name.setFont(font);
	name.setString("Name : ");
	name.setFillColor(sf::Color::Black);
	name.setPosition(200,300);
	name.setCharacterSize(80);
	sf::String nameplayer;

//back
	sf::Text back;
	back.setFont(font);
	back.setString("back");
	back.setFillColor(sf::Color::Black);
	back.setPosition(120, 580);
	back.setCharacterSize(40);

//story
	sf::Text story;
	story.setFont(font);
	story.setString("Players in the role of a flying craft must fight against incoming enemy flying machines and in order not to be attacked, must only shoot, shoot and shoot.");
	story.setFillColor(sf::Color::Yellow);
	story.setOutlineColor(sf::Color::Blue);
	story.setOutlineThickness(5);
	story.setCharacterSize(100);
	story.setPosition(100, 300);


//scoreboard
	sf::RectangleShape board;
	board.setSize(sf::Vector2f(700, 500));
	board.setFillColor(sf::Color::Black);
	board.setPosition(500, 450);
	board.setOrigin(board.getGlobalBounds().width / 2, board.getGlobalBounds().height / 2);

	sf::Text scoreboard;
	scoreboard.setFont(font);
	scoreboard.setString("SCOREBOARD");
	scoreboard.setFillColor(sf::Color::White);
	scoreboard.setCharacterSize(50);
	scoreboard.setPosition(360, 200);

	vector<pair<string,int>> ScoreBoard;

//over whelm
	sf::Texture over;
	over.loadFromFile("mainmenu/over.png");
	sf::Sprite showover;
	showover.setTexture(over);
	showover.setPosition(100,-10);

	sf::Texture whelm;
	whelm.loadFromFile("mainmenu/whelm.png");
	sf::Sprite showwhelm;
	showwhelm.setTexture(whelm);
	showwhelm.setPosition(500, -10);


//how to play
	sf::RectangleShape bc;
	bc.setSize(sf::Vector2f(700, 500));
	bc.setFillColor(sf::Color::White);
	bc.setPosition(500, 450);
	bc.setOrigin(bc.getGlobalBounds().width / 2, bc.getGlobalBounds().height / 2);
	

	sf::Texture htp1;
	htp1.loadFromFile("howtoplay/1.png");
	sf::Sprite htp01;
	htp01.setTexture(htp1);
	htp01.setScale(0.7, 0.7);
	htp01.setPosition(400, 375);
	htp01.setOrigin(htp01.getGlobalBounds().width / 2, htp01.getGlobalBounds().height / 2);

	sf::Texture htp2;
	htp2.loadFromFile("howtoplay/2.png");
	sf::Sprite htp02;
	htp02.setTexture(htp2);
	htp02.setScale(0.7, 0.7);
	htp02.setPosition(400, 375);
	htp02.setOrigin(htp02.getGlobalBounds().width / 2, htp02.getGlobalBounds().height / 2);


//score
	sf::Text textscore;
	textscore.setFont(font);
	textscore.setString("SCORE : ");
	textscore.setFillColor(sf::Color::Black);
	textscore.setPosition(40, 0);
	textscore.setCharacterSize(40);


//high score
	sf::Text HighScoreText;
	HighScoreText.setFont(font);
	HighScoreText.setFillColor(sf::Color::Black);
	HighScoreText.setString("HIGH SCORE : ");
	HighScoreText.setCharacterSize(50);
	HighScoreText.setPosition(300, 300);


//hitbox player
	sf::RectangleShape hitbox_player1;
	hitbox_player1.setOrigin(hitbox_player1.getGlobalBounds().width / 2, hitbox_player1.getGlobalBounds().height / 2);
	hitbox_player1.setFillColor(sf::Color::Transparent);
	hitbox_player1.setOutlineThickness(1.f);
	hitbox_player1.setOutlineColor(sf::Color::Green);
	hitbox_player1.setSize(sf::Vector2f(60.f, 50.f));
	hitbox_player1.setPosition(player.Sprite_ship.getPosition().x + 15, player.Sprite_ship.getPosition().y + 35);

	sf::RectangleShape hitbox_player2;
	hitbox_player2.setOrigin(hitbox_player2.getGlobalBounds().width / 2, hitbox_player2.getGlobalBounds().height / 2);
	hitbox_player2.setFillColor(sf::Color::Transparent);
	hitbox_player2.setOutlineThickness(1.f);
	hitbox_player2.setOutlineColor(sf::Color::Green);
	hitbox_player2.setSize(sf::Vector2f(120.f, 40.f));
	hitbox_player2.setPosition(player.Sprite_ship.getPosition().x + 10, player.Sprite_ship.getPosition().y + 63);


//gameover
	Gameover gameover(600, 600);

	while (window.isOpen())
	{
		deltatime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{

			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		goto Story;
	}

	Main:
		while (window.isOpen())
		{
			deltatime = clock.restart().asSeconds();

			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{

				case sf::Event::Closed:
					window.close();
					break;
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			{

				//draw background menu state

				for (Background& background : backgrounds)
					background.Update(deltatime);
				for (Background& background : backgrounds)
				{ background.Draw(window); }

				/*window.draw(sound);*/

				
				//draw overwhelm
				if (showover.getPosition().y < 60) { showover.move(0, 1.0); }
				if (showwhelm.getPosition().y < 60) { showwhelm.move(0, 1.0); }
				window.draw(showover);
				window.draw(showwhelm);

				//hitbox
				if (mainmenu.hitbox[0].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
				{
						mainmenu.mainMenu[0].setFillColor(sf::Color::Blue);
						mainmenu.mainMenu[0].setScale(1.5, 1.5);
					
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						startmusic.pause();
						/*level1.play();*/
						goto Name;
					}
				}
				else
				{
					mainmenu.mainMenu[0].setFillColor(sf::Color::Black);
					mainmenu.mainMenu[0].setScale(1, 1);

				}

				if (mainmenu.hitbox[1].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
				{
					mainmenu.mainMenu[1].setFillColor(sf::Color::Blue);
					mainmenu.mainMenu[1].setScale(1.5, 1.5);

					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{

						goto Howtoplay;
					}
				}
				else
				{
					mainmenu.mainMenu[1].setFillColor(sf::Color::Black);
					mainmenu.mainMenu[1].setScale(1, 1);

				}

				if (mainmenu.hitbox[2].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
				{
					mainmenu.mainMenu[2].setFillColor(sf::Color::Blue);
					mainmenu.mainMenu[2].setScale(1.5, 1.5);

					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{

						goto Score;
					}
				}
				else
				{
					mainmenu.mainMenu[2].setFillColor(sf::Color::Black);
					mainmenu.mainMenu[2].setScale(1, 1);
				}

				if (mainmenu.hitbox[3].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
				{
					mainmenu.mainMenu[3].setFillColor(sf::Color::Blue);
					mainmenu.mainMenu[3].setScale(1.5, 1.5);

					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{

						window.close();
					}
				}
				else
				{
					mainmenu.mainMenu[3].setFillColor(sf::Color::Black);
					mainmenu.mainMenu[3].setScale(1, 1);
				}

			
				//draw mainmenu
				mainmenu.Draw(window);
				window.display();
			}
		}

	Story:
		while (window.isOpen())
		{
			deltatime = clock.restart().asSeconds();

			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{

				case sf::Event::Closed:
					window.close();
					break;
				}
			}

			for (Background& background : backgrounds)
				background.Update(deltatime);
			for (Background& background : backgrounds)
			{
				background.Draw(window);
			}

			window.draw(story);
			story.move(-5, 0);

			if (story.getPosition().x < -5500)
			{
				story.setPosition(1000, 300);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				goto Main;
			}

			window.display();

			
		}


	Name:
		while (window.isOpen())
		{
			
			deltatime = clock.restart().asSeconds();

			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{

				case sf::Event::Closed:
					window.close();
					break;
				}
			}

			for (Background& background : backgrounds)
				background.Update(deltatime);
			for (Background& background : backgrounds)
			{
				background.Draw(window);
			}


				
			
			if (event.type == sf::Event::TextEntered and debounce < clock2.getElapsedTime().asSeconds())
			{

				debounce = clock2.getElapsedTime().asSeconds() + 0.2;
				if (event.text.unicode >= 33 && event.text.unicode <= 126 && nameplayer.getSize() <= 13 && event.text.unicode != 44)
				{
					nameplayer += event.text.unicode;
				}
				else if (event.text.unicode == 8)//backspace
				{
					nameplayer = nameplayer.substring(0, nameplayer.getSize() - 1);
				}
				else if (event.text.unicode == 13 && nameplayer.getSize() > 0)//enter
				{
					goto Play;
				}

			}

			if (back.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					goto Main;
				}
			}

			name.setString("Name : " + nameplayer);

			window.draw(name);
			window.draw(back);
			window.display();
		}


	Howtoplay:
		while (window.isOpen())
		{
			deltatime = clock.restart().asSeconds();

			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{

				case sf::Event::Closed:
					window.close();
					break;
				}
			}

			/*cout << flag[1];*/
			for (Background& background : backgrounds)
				background.Update(deltatime);
			for (Background& background : backgrounds)
			{
				background.Draw(window);
			}
			window.draw(bc);

			if (bc.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and flag[1])
				{
					slide++;
					flag[1] = false;
				}
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
					flag[1] = true;
			}

			if (slide == 1)
			{
				window.draw(htp01);
			}
			if (slide == 2)
			{
				window.draw(htp02);
			}
			if (slide > 2)
			{
				slide = 1;
			}
			if (!bc.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					slide = 0;
					goto Main;
				}
			}
			window.display();
		}

	Score:
		while (window.isOpen())
		{
			deltatime = clock.restart().asSeconds();

			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{

				case sf::Event::Closed:
					window.close();
					break;
				}
			}
			for (Background& background : backgrounds)
				background.Update(deltatime);
			for (Background& background : backgrounds)
			{
				background.Draw(window);
			}
			if (!board.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					goto Main;
				}
			}

			window.draw(board);
			window.draw(scoreboard);
			window.display();
		}


	Play:
		while (window.isOpen())
		{
			deltatime = clock.restart().asSeconds();

			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{

				case sf::Event::Closed:
					window.close();
					break;
				}
			}


				CountTime += deltatime;
				cout << CountTime << endl;
				

				//hitbox player
				hitbox_player1.setPosition(player.Sprite_ship.getPosition().x + 15, player.Sprite_ship.getPosition().y + 35);
				hitbox_player2.setPosition(player.Sprite_ship.getPosition().x + 10, player.Sprite_ship.getPosition().y + 63);

				

				//Spacebar KeyPressed 
				if (firerate < 20) { firerate++; }
				if (firerate >= 20)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
					{

						Bulletblue.Sprite_bullet.setPosition
						(player.Sprite_ship.getPosition().x + (player.Sprite_ship.getGlobalBounds().width) - 20,
							player.Sprite_ship.getPosition().y + ((player.Sprite_ship.getGlobalBounds().height) / 2) + 20);
						soundbullet.play();
						bullets.push_back(Bullet(Bulletblue));

					}

					firerate = 0;

				}

				//bullets movement
				for (int i = 0; i < bullets.size(); i++)
				{
					bullets[i].Sprite_bullet.move(deltatime * 500, 0);

					if (bullets[i].Sprite_bullet.getPosition().x > window.getSize().x)
					{
						bullets.erase(bullets.begin() + i);
						break;
					}
				}

				//enemies movement
				if (enemySpawnTimer < 50) { enemySpawnTimer++; }
				if (enemySpawnTimer >= 50)
				{
					if(CountTime > 0 and CountTime <= 60)
					{
					Enemymini1.Sprite_enemy.setPosition(window.getSize().x, rand() % int(window.getSize().y - Enemymini1.Sprite_enemy.getSize().y));
					enemies1.push_back(Enemy(Enemymini1));
					}
					if (CountTime >= 30 and CountTime <= 90)
					{
						Enemymini2.Sprite_enemy.setPosition(window.getSize().x, rand() % int(window.getSize().y - Enemymini2.Sprite_enemy.getSize().y));
						enemies2.push_back(Enemy(Enemymini2));
					}

					if (CountTime >= 60 and CountTime <= 120)
					{
						Enemymedium1.Sprite_enemy.setPosition(window.getSize().x, rand() % int(window.getSize().y - Enemymedium1.Sprite_enemy.getSize().y));
						enemies3.push_back(Enemy(Enemymedium1));
					}

					if (CountTime >= /*0*/ 90 and CountTime <= 150)
					{
						Enemymedium2.Sprite_enemy.setPosition(window.getSize().x, rand() % int(window.getSize().y - Enemymedium2.Sprite_enemy.getSize().y));
						enemies4.push_back(Enemy(Enemymedium2));
					}
					if (CountTime >= /*0*/165 and CountTime <= 225)
					{
						Enemybig1.Sprite_enemy1.setPosition(window.getSize().x, rand() % int(window.getSize().y - Enemybig1.Sprite_enemy1.getSize().y));
						enemies5.push_back(Enemy1(Enemybig1));
					}
					enemySpawnTimer = 0;
				}

				//fruit item movement
				if (itemSpawnTimer < 30) { itemSpawnTimer++; }
				if (itemSpawnTimer >= 30)
				{
					if (CountTime >= 155 and CountTime <= 165 or CountTime >= 225 and CountTime <= 235)
					{
						Fruititem1.Sprite_Itemfruit.setPosition((rand() % int(window.getSize().x - Fruititem1.Sprite_Itemfruit.getSize().x)), 0.f);
						Itembanana.push_back(DropItem(Fruititem1));
						Fruititem2.Sprite_Itemfruit.setPosition((rand() % int(window.getSize().x - Fruititem2.Sprite_Itemfruit.getSize().x)), 0.f);
						Itemcherry.push_back(DropItem(Fruititem2));
						Fruititem3.Sprite_Itemfruit.setPosition((rand() % int(window.getSize().x - Fruititem3.Sprite_Itemfruit.getSize().x)), 0.f);
						Itemgrape.push_back(DropItem(Fruititem3));
						Fruititem4.Sprite_Itemfruit.setPosition((rand() % int(window.getSize().x - Fruititem4.Sprite_Itemfruit.getSize().x)), 0.f);
						Itemwatermelon.push_back(DropItem(Fruititem4));
					}

					itemSpawnTimer = 0;
				}

				//erase fruit item
				for (int i = 0; i < Itembanana.size(); i++)
				{
					Itembanana[i].Update(deltatime);
					if (Itembanana[i].Sprite_Itemfruit.getPosition().y > 700)
					{
						Itembanana.erase(Itembanana.begin() + i);
						break;
					}

				}

				for (int i = 0; i < Itemcherry.size(); i++)
				{
					Itemcherry[i].Update(deltatime);
					if (Itemcherry[i].Sprite_Itemfruit.getPosition().y > 700)
					{
						Itemcherry.erase(Itemcherry.begin() + i);
						break;
					}

				}

				for (int i = 0; i < Itemgrape.size(); i++)
				{
					Itemgrape[i].Update(deltatime);
					if (Itemgrape[i].Sprite_Itemfruit.getPosition().y > 700)
					{
						Itemgrape.erase(Itemgrape.begin() + i);
						break;
					}

				}

				for (int i = 0; i < Itemwatermelon.size(); i++)
				{
					Itemwatermelon[i].Update(deltatime);
					if (Itemwatermelon[i].Sprite_Itemfruit.getPosition().y > 700)
					{
						Itemwatermelon.erase(Itemwatermelon.begin() + i);
						break;
					}

				}

				//erase enemies
				for (int i = 0; i < enemies1.size(); i++)
				{
					enemies1[i].Update(deltatime, i);
					if (enemies1[i].Sprite_enemy.getPosition().x < -130)
					{
						enemies1.erase(enemies1.begin() + i);
						break;
					}

				}

				for (int i = 0; i < enemies2.size(); i++)
				{
					enemies2[i].Update(deltatime, i);
					if (enemies2[i].Sprite_enemy.getPosition().x < -130)
					{
						enemies2.erase(enemies2.begin() + i);
						break;
					}

				}

				for (int i = 0; i < enemies3.size(); i++)
				{
					enemies3[i].Update(deltatime, i);
					if (enemies3[i].Sprite_enemy.getPosition().x < -130)
					{
						enemies3.erase(enemies3.begin() + i);
						break;
					}

				}

				for (int i = 0; i < enemies4.size(); i++)
				{
					enemies4[i].Update(deltatime, i);
					if (enemies4[i].Sprite_enemy.getPosition().x < -130)
					{
						enemies4.erase(enemies4.begin() + i);
						break;
					}

				}

				for (int i = 0; i < enemies5.size(); i++)
				{
					enemies5[i].Update(deltatime);
					if (enemies5[i].Sprite_enemy1.getPosition().x < -130)
					{
						enemies5.erase(enemies5.begin() + i);
						break;
					}

				}
				
				//collistion bullets vs enemies
				for (size_t i = 0; i < bullets.size(); i++)
				{
					for (size_t j = 0; j < enemies1.size(); j++)
					{
						if (bullets[i].Sprite_bullet.getGlobalBounds().intersects(enemies1[j].hitbox[0].getGlobalBounds()))
						{
							iscollision++;
							score += 10;
							//UI
							textscore.setString("SCORE : " + to_string(score));
							bullets.erase(bullets.begin() + i);
							enemies1.erase(enemies1.begin() + j);
							break;
						}
						if (iscollision % 10 == 0)
						{
							/*Itemshoot_G.Sprite_item.setPosition(window.getSize().x, rand() % int(window.getSize().y - itemGreen.getSize().y));
							Item1.push_back(Item(Itemshoot_G));
							Itemshoot_G.Draw(window);*/
						}
					}

				}
				
				for (size_t i = 0; i < bullets.size(); i++)
				{
					for (size_t j = 0; j < enemies2.size(); j++)
					{
						if (bullets[i].Sprite_bullet.getGlobalBounds().intersects(enemies2[j].hitbox[0].getGlobalBounds()))
						{
							iscollision++;
							score += 10;
							//UI
							textscore.setString("SCORE : " + to_string(score));
							bullets.erase(bullets.begin() + i);
							enemies2.erase(enemies2.begin() + j);
							break;
						}

					}

				}


				for (size_t i = 0; i < bullets.size(); i++)
				{
					for (size_t j = 0; j < enemies3.size(); j++)
					{
						
						if (bullets[i].Sprite_bullet.getGlobalBounds().intersects(enemies3[j].hitbox[1].getGlobalBounds()))
						{
							iscollision++;
							enemies3[j].bloodenemymedium--;
							if (enemies3[j].bloodenemymedium == 0)
							{
								score += 20;
								enemies3.erase(enemies3.begin() + j);
							}
							//UI
							textscore.setString("SCORE : " + to_string(score));
							bullets.erase(bullets.begin() + i);
							break;
						}
					}
						
				}
				
				for (size_t i = 0; i < bullets.size(); i++)
				{
					for (size_t j = 0; j < enemies4.size(); j++)
					{

						if (bullets[i].Sprite_bullet.getGlobalBounds().intersects(enemies4[j].hitbox[2].getGlobalBounds()))
						{
							iscollision++;
							enemies4[j].bloodenemymedium--;
							if (enemies4[j].bloodenemymedium == 0)
							{
								score += 20;
								enemies4.erase(enemies4.begin() + j);

							}
							//UI
							textscore.setString("SCORE : " + to_string(score));
							bullets.erase(bullets.begin() + i);
							break;
						}
					}

				}

				for (size_t i = 0; i < bullets.size(); i++)
				{
					for (size_t j = 0; j < enemies5.size(); j++)
					{

						if (bullets[i].Sprite_bullet.getGlobalBounds().intersects(enemies5[j].Sprite_enemy1.getGlobalBounds()))
						{
							iscollision++;
							enemies5[j].bloodenemybig--;
							if (enemies5[j].bloodenemybig == 0)
							{
								score += 30;
								enemies5.erase(enemies5.begin() + j);

							}
							//UI
							textscore.setString("SCORE : " + to_string(score));
							bullets.erase(bullets.begin() + i);
							break;
						}
					}

				}

				//collistion player vs enemy
				for (size_t i = 0; i < enemies1.size(); i++)
				{
					if (hitbox_player1.getGlobalBounds().intersects(enemies1[i].hitbox[0].getGlobalBounds()) 
						or hitbox_player2.getGlobalBounds().intersects(enemies1[i].hitbox[0].getGlobalBounds()))
					{
						enemies1.erase(enemies1.begin() + i);
						blood -= 1;
						break;
					}
				}

				for (size_t i = 0; i < enemies2.size(); i++)
				{
					if (hitbox_player1.getGlobalBounds().intersects(enemies2[i].hitbox[0].getGlobalBounds())
						or hitbox_player2.getGlobalBounds().intersects(enemies2[i].hitbox[0].getGlobalBounds()))
					{
						enemies2.erase(enemies2.begin() + i);
						blood -= 1;
						break;
					}
				}

				for (size_t i = 0; i < enemies3.size(); i++)
				{
					if (hitbox_player1.getGlobalBounds().intersects(enemies3[i].hitbox[1].getGlobalBounds())
						or hitbox_player2.getGlobalBounds().intersects(enemies3[i].hitbox[1].getGlobalBounds()))
					{
						enemies3.erase(enemies3.begin() + i);
						blood -= 1;
						break;
					}
				}

				for (size_t i = 0; i < enemies4.size(); i++)
				{
					if (hitbox_player1.getGlobalBounds().intersects(enemies4[i].hitbox[2].getGlobalBounds()) 
						or hitbox_player2.getGlobalBounds().intersects(enemies4[i].hitbox[2].getGlobalBounds()))
					{
						enemies4.erase(enemies4.begin() + i);
						blood -= 1;
						break;
					}
				}

				for (size_t i = 0; i < enemies5.size(); i++)
				{
					if (player.Sprite_ship.getGlobalBounds().intersects(enemies5[i].Sprite_enemy1.getGlobalBounds()))
					{
						enemies5.erase(enemies5.begin() + i);
						blood -= 1;
						break;
					}
				}

				//collistion bullet vs fruit item
				for (size_t i = 0; i < bullets.size(); i++)
				{
					for (size_t j = 0; j < Itembanana.size(); j++)
					{

						if (bullets[i].Sprite_bullet.getGlobalBounds().intersects(Itembanana[j].Sprite_Itemfruit.getGlobalBounds()))
						{
							Itembanana[i].n_b++;
							//UI
							score += (2*(Itembanana[j].n_b));
							textscore.setString("SCORE : " + to_string(score));
							bullets.erase(bullets.begin() + i);
							Itembanana.erase(Itembanana.begin() + j);
							break;
						}
					}

				}

				for (size_t i = 0; i < bullets.size(); i++)
				{
					for (size_t j = 0; j < Itemgrape.size(); j++)
					{

						if (bullets[i].Sprite_bullet.getGlobalBounds().intersects(Itemgrape[j].Sprite_Itemfruit.getGlobalBounds()))
						{
							Itemgrape[j].n_g++;
							//UI
							score += (3*(Itemgrape[j].n_g));
							textscore.setString("SCORE : " + to_string(score));
							bullets.erase(bullets.begin() + i);
							Itemgrape.erase(Itemgrape.begin() + j);
							break;
						}
					}

				}

				for (size_t i = 0; i < bullets.size(); i++)
				{
					for (size_t j = 0; j < Itemcherry.size(); j++)
					{

						if (bullets[i].Sprite_bullet.getGlobalBounds().intersects(Itemcherry[j].Sprite_Itemfruit.getGlobalBounds()))
						{
							Itemcherry[j].n_c++;
							//UI
							score += (5*(Itemcherry[j].n_c));
							textscore.setString("SCORE : " + to_string(score));
							bullets.erase(bullets.begin() + i);
							Itemcherry.erase(Itemcherry.begin() + j);
							break;
						}
					}

				}


				for (size_t i = 0; i < bullets.size(); i++)
				{
					for (size_t j = 0; j < Itemwatermelon.size(); j++)
					{

						if (bullets[i].Sprite_bullet.getGlobalBounds().intersects(Itemwatermelon[j].Sprite_Itemfruit.getGlobalBounds()))
						{
							Itemwatermelon[j].n_w++;
							//UI
							score += (10*(Itemwatermelon[j].n_w));
							textscore.setString("SCORE : " + to_string(score));
							bullets.erase(bullets.begin() + i);
							Itemwatermelon.erase(Itemwatermelon.begin() + j);
							break;
						}
					}

				}

				//collistion player vs fruit item
				for (size_t i = 0; i < Itembanana.size(); i++)
				{
					if (player.Sprite_ship.getGlobalBounds().intersects(Itembanana[i].Sprite_Itemfruit.getGlobalBounds()))
					{
						Itembanana[i].n_b++;
						//UI
						score += (2*(Itembanana[i].n_b));
						textscore.setString("SCORE : " + to_string(score));
						Itembanana.erase(Itembanana.begin() + i);
						break;
					}
				}

				for (size_t i = 0; i < Itemgrape.size(); i++)
				{
					if (player.Sprite_ship.getGlobalBounds().intersects(Itemgrape[i].Sprite_Itemfruit.getGlobalBounds()))
					{
						Itemgrape[i].n_g++;
						//UI
						score += (3*(Itemgrape[i].n_g));
						textscore.setString("SCORE : " + to_string(score));
						Itemgrape.erase(Itemgrape.begin() + i);
						break;
					}
				}

				for (size_t i = 0; i < Itemcherry.size(); i++)
				{
					if (player.Sprite_ship.getGlobalBounds().intersects(Itemcherry[i].Sprite_Itemfruit.getGlobalBounds()))
					{
						Itemcherry[i].n_c++;
						//UI
						score += (5*(Itemcherry[i].n_c));
						textscore.setString("SCORE : " + to_string(score));
						Itemcherry.erase(Itemcherry.begin() + i);
						break;
					}
				}

				for (size_t i = 0; i < Itemwatermelon.size(); i++)
				{
					if (player.Sprite_ship.getGlobalBounds().intersects(Itemwatermelon[i].Sprite_Itemfruit.getGlobalBounds()))
					{
						Itemwatermelon[i].n_w++;
						//UI
						score += (10*(Itemwatermelon[i].n_w));
						textscore.setString("SCORE : " + to_string(score));
						Itemwatermelon.erase(Itemwatermelon.begin() + i);
						break;
					}
				}

				//pause menu
				if (pausemenu.hitbox.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{

						goto Pause;
					}
				}


				//hack
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::U) and debounce < clock3.getElapsedTime().asSeconds())
				{
					debounce = clock3.getElapsedTime().asSeconds() + 5;
					blood = 100;
				}

				//animation update
				Itemshoot_G.Update(deltatime);
				Itemshoot_Y.Update(deltatime);
				Itemshoot_R.Update(deltatime);


				//draw
				window.clear();


				//draw background game state
				for (Background& background : backgrounds)
					background.Update(deltatime);
				for (Background& background : backgrounds)
					background.Draw(window);

				

				player.Update();
				player.move(deltatime);




				//draw bullet
				for (int i = 0; i < bullets.size(); i++)
				{
					bullets[i].Draw(window);
				}

				//draw enemy
				for (int i = 0; i < enemies1.size(); i++)
				{
					enemies1[i].Draw(window);
				}

				for (int i = 0; i < enemies2.size(); i++)
				{
					enemies2[i].Draw(window);
				}

				for (int i = 0; i < enemies3.size(); i++)
				{
					enemies3[i].Draw(window);
				}

				for (int i = 0; i < enemies4.size(); i++)
				{
					enemies4[i].Draw(window);
				}

				for (int i = 0; i < enemies5.size(); i++)
				{
					enemies5[i].Draw(window);
				}

				//draw fruit item
				for (int i = 0; i < Itembanana.size(); i++)
				{
					Itembanana[i].Draw(window);
				}

				for (int i = 0; i < Itemcherry.size(); i++)
				{
					Itemcherry[i].Draw(window);
				}

				for (int i = 0; i < Itemgrape.size(); i++)
				{
					Itemgrape[i].Draw(window);
				}

				for (int i = 0; i < Itemwatermelon.size(); i++)
				{
					Itemwatermelon[i].Draw(window);
				}

				//draw player
				player.Draw(window);

				//draw hitbox player
				window.draw(hitbox_player1);
				window.draw(hitbox_player2);

				//draw hitbox enemies

				/*window.draw(hitbox_enemies1);*/
			

				//draw text
				window.draw(textscore);

				//draw pausebutton
				pausemenu.Draw(window);

				//draw heart
				if (blood >= 6)
				{
					window.draw(bloodfull);
				}
				if (blood == 5)
				{
					window.draw(bloodHalfFirst);
				}
				if (blood == 4)
				{
					window.draw(bloodFirst);
				}
				if (blood == 3)
				{
					window.draw(bloodHalfnd);
				}
				if (blood == 2)
				{
					window.draw(bloodnd);
				}
				if (blood == 1)
				{
					window.draw(bloodHalfrd);
				}
				if (blood == 0)
				{
					window.draw(bloodempty);
				}

				//game over
				if (blood <= -1)
				{
					window.clear();
					goto Gameover;
					
				}

				/*if (GameOverstate == 0)
				{
					for (Background& background : backgrounds)
						background.Update(deltatime);
					for (Background& background : backgrounds)
						background.Draw(window);

					level1.stop();
					startmusic.play();

					gameover.Draw(window);
					
					

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					{
						CountTime = 0;
						player.Sprite_ship.setPosition(0, 400);
						enemies1.clear();
						enemies2.clear();
						enemies3.clear();
						enemies4.clear();
						Itembanana.clear();
						Itemgrape.clear();
						Itemcherry.clear();
						Itemwatermelon.clear();
						blood = 6;
						Mainmenustate = 3;
						score = 0;
						textscore.setString("SCORE : " + to_string(score));
					}
			
				}*/
	
				window.display();
		}
				return 0;
				

		Pause:
				while (window.isOpen())
				{
					deltatime = clock.restart().asSeconds();

					sf::Event event;
					while (window.pollEvent(event))
					{
						switch (event.type)
						{

						case sf::Event::Closed:
							window.close();
							break;
						}
					}
					goto Main;
					window.display();
				}

		Gameover:
				while (window.isOpen())
				{
					deltatime = clock.restart().asSeconds();

					sf::Event event;
					while (window.pollEvent(event))
					{
						switch (event.type)
						{

						case sf::Event::Closed:
							window.close();
							break;
						}
					}

					for (Background& background : backgrounds)
						background.Update(deltatime);
					for (Background& background : backgrounds)
						background.Draw(window);

					level1.stop();
					startmusic.play();

					gameover.Draw(window);

					string name;
					name = nameplayer;
					ofstream highscore;
					highscore.open("score/Score.txt", ios::out | ios::app);
					highscore << "\n" << name << " " << score;
					highscore.close();


					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					{
						CountTime = 0;
						player.Sprite_ship.setPosition(0, 400);
						enemies1.clear();
						enemies2.clear();
						enemies3.clear();
						enemies4.clear();
						Itembanana.clear();
						Itemgrape.clear();
						Itemcherry.clear();
						Itemwatermelon.clear();
						blood = 6;
						score = 0;
						textscore.setString("SCORE : " + to_string(score));
						nameplayer = "";
						goto Main;
					}

					window.display();
				}

	
}

bool sortbysecdesc(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
{
	return a.second > b.second;
}