#include<iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <cstdlib>
#include "Background.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Animation.h"
#include "Mainmenu.h"
#include "Gameover.h"
#include "PauseMenu.h"


using namespace std;
int main()
{
	//window
	sf::RenderWindow window(sf::VideoMode(1000, 768), "OverWhelm!", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);
	sf::Clock clock;


	//variable
	float deltatime = 0.0f;
	float firerate = 0;
	int enemySpawnTimer = 0;
	int CountBulletEnemymini = 0;
	int score = 0;
	int blood = 6;
	float CountTime = 0;
	int mainmenustate = 1; //0 = not display , 1,3 = display
	int GameOverstate = 1; //1 = not display , 0 = display
	bool playsound = 0;//0 = not play , 1 = play
	srand(time(NULL));


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

	//pause menu
	PauseMenu pausemenu(sf::Vector2f(900.f, 0.f));

	//sound
		//background started
	sf::Music level1;
	level1.openFromFile("sound/level1.WAV");
	level1.setLoop(true);
		
		//background
	sf::Music startmusic;
	startmusic.openFromFile("sound/start.WAV");
	startmusic.setLoop(true);
	startmusic.play();

	

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
	
	//sf::Texture enemyBig;
	//enemyBig.loadFromFile("enemy/big1.png");
	//Enemy Enemybig1(&enemyBig);
	//vector<Enemy> enemies5;


	//enemies animation
	Animation animation(&enemySmallOrange, sf::Vector2u(1, 3), 0.3f);

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

	//score
	sf::Font font;
	font.loadFromFile("font/fontscore.ttf");
	sf::Text textscore;
	textscore.setFont(font);
	textscore.setString("SCORE : ");
	textscore.setFillColor(sf::Color::Black);
	textscore.setPosition(40, 0);
	textscore.setCharacterSize(40);

	//gameover
	Gameover gameover(600, 600);

	while (window.isOpen())
	{
		deltatime = clock.restart().asSeconds();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();
		if (mainmenustate == 1 or mainmenustate == 3);
		{

			
			//draw background menu state

			for (Background& background : backgrounds)
				background.Update(deltatime);
			for (Background& background : backgrounds)
			{ background.Draw(window); }

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

					mainmenustate = 0;
					startmusic.stop();
					playsound = 1;
					if (playsound == 1)
					{
						level1.play();
					}
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

					/*mainmenustate = 0;*/
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

					window.close();
				}
			}
			else
			{
				mainmenu.mainMenu[2].setFillColor(sf::Color::Black);
				mainmenu.mainMenu[2].setScale(1, 1);
			}

			//draw mainmenu
			mainmenu.Draw(window);
		}
		
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
		if (mainmenustate == 0) 
		{
			
			CountTime += deltatime;
			//cout << CountTime << endl;
			

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

				if (CountTime >= 90 and CountTime <= 150)
				{
					Enemymedium2.Sprite_enemy.setPosition(window.getSize().x, rand() % int(window.getSize().y - Enemymedium2.Sprite_enemy.getSize().y));
					enemies4.push_back(Enemy(Enemymedium2));
				}

				enemySpawnTimer = 0;
			}

			for (int i = 0; i < enemies1.size(); i++)
			{
				enemies1[i].Update(deltatime, i);
				if (enemies1[i].Sprite_enemy.getPosition().x < -130)
				{
					enemies1.erase(enemies1.begin() + i);
				}

			}

			for (int i = 0; i < enemies2.size(); i++)
			{
				enemies2[i].Update(deltatime, i);
				if (enemies2[i].Sprite_enemy.getPosition().x < -130)
				{
					enemies2.erase(enemies2.begin() + i);
				}

			}

			for (int i = 0; i < enemies3.size(); i++)
			{
				enemies3[i].Update(deltatime, i);
				if (enemies3[i].Sprite_enemy.getPosition().x < -130)
				{
					enemies3.erase(enemies3.begin() + i);
				}

			}

			for (int i = 0; i < enemies4.size(); i++)
			{
				enemies4[i].Update(deltatime, i);
				if (enemies4[i].Sprite_enemy.getPosition().x < -130)
				{
					enemies4.erase(enemies4.begin() + i);
				}

			}

			//collistion
			for (size_t i = 0; i < bullets.size(); i++)
			{
				for (size_t j = 0; j < enemies1.size(); j++)
				{
					if (bullets[i].Sprite_bullet.getGlobalBounds().intersects(enemies1[j].Sprite_enemy.getGlobalBounds()))
					{

						bullets.erase(bullets.begin() + i);
						enemies1.erase(enemies1.begin() + j);
						score += 10;
						//UI
						textscore.setString("SCORE : " + to_string(score));
						break;
					}

				}

			}

			for (size_t i = 0; i < bullets.size(); i++)
			{
				for (size_t j = 0; j < enemies2.size(); j++)
				{
					if (bullets[i].Sprite_bullet.getGlobalBounds().intersects(enemies2[j].Sprite_enemy.getGlobalBounds()))
					{

						bullets.erase(bullets.begin() + i);
						enemies2.erase(enemies2.begin() + j);
						score += 10;
						//UI
						textscore.setString("SCORE : " + to_string(score));
						break;
					}

				}

			}


			for (size_t i = 0; i < bullets.size(); i++)
			{
				for (size_t j = 0; j < enemies3.size(); j++)
				{
					
					if (bullets[i].Sprite_bullet.getGlobalBounds().intersects(enemies3[j].Sprite_enemy.getGlobalBounds()))
					{
						enemies3[i].bloodenemymedium--;
						bullets.erase(bullets.begin() + i);
						if (enemies3[i].bloodenemymedium == 0)
						{
							score += 20;
							enemies3.erase(enemies3.begin() + j);
	
						}
						//UI
						textscore.setString("SCORE : " + to_string(score));
						break;
					}
				}
					
			}
			
			for (size_t i = 0; i < bullets.size(); i++)
			{
				for (size_t j = 0; j < enemies4.size(); j++)
				{

					if (bullets[i].Sprite_bullet.getGlobalBounds().intersects(enemies4[j].Sprite_enemy.getGlobalBounds()))
					{
						enemies4[i].bloodenemymedium--;
						bullets.erase(bullets.begin() + i);
						if (enemies4[i].bloodenemymedium == 0)
						{
							score += 20;
							enemies4.erase(enemies4.begin() + j);

						}
						//UI
						textscore.setString("SCORE : " + to_string(score));
						break;
					}
				}

			}

			//collistion player vs enemy
			for (size_t i = 0; i < enemies1.size(); i++)
			{
				if (player.Sprite_ship.getGlobalBounds().intersects(enemies1[i].Sprite_enemy.getGlobalBounds()))
				{
					enemies1.erase(enemies1.begin() + i);
					blood -= 1;
				}
			}

			for (size_t i = 0; i < enemies2.size(); i++)
			{
				if (player.Sprite_ship.getGlobalBounds().intersects(enemies2[i].Sprite_enemy.getGlobalBounds()))
				{
					enemies2.erase(enemies2.begin() + i);
					blood -= 1;
				}
			}

			for (size_t i = 0; i < enemies3.size(); i++)
			{
				if (player.Sprite_ship.getGlobalBounds().intersects(enemies3[i].Sprite_enemy.getGlobalBounds()))
				{
					enemies3.erase(enemies3.begin() + i);
					blood -= 1;
				}
			}

			for (size_t i = 0; i < enemies4.size(); i++)
			{
				if (player.Sprite_ship.getGlobalBounds().intersects(enemies4[i].Sprite_enemy.getGlobalBounds()))
				{
					enemies4.erase(enemies4.begin() + i);
					blood -= 1;
				}
			}

			if (pausemenu.Sprite_Button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{

					/*mainmenustate = 0;*/
				}
			}

			//animation update
			animation.Update(1, deltatime);

			//draw
			window.clear();


			//draw background game state
			for (Background& background : backgrounds)
				background.Update(deltatime);
			for (Background& background : backgrounds)
				background.Draw(window);

			player.Update();
			player.move(deltatime);

			//draw pausebutton
			pausemenu.Draw(window);

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

			

			//draw player
			player.Draw(window);

			//draw text
			window.draw(textscore);

			//draw heart
			if (blood == 6)
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
				GameOverstate = 0;
			}

			if (GameOverstate == 0)
			{
				gameover.Draw(window);
			}
		}
			window.display();
		
	}
	return 0;
}