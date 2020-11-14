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


using namespace std;
int main()
{
	//window
	sf::RenderWindow window(sf::VideoMode(1000, 768), "OverWhelm!", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	//variable
	float deltatime = 0.0f;
	float firerate = 0;
	int enemySpawnTimer = 0;
	int CountBulletEnemymini = 0;
	int score = 0;
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
	//sound
		//background
	sf::Music level1;
	level1.openFromFile("sound/level1.WAV");
	level1.setLoop(true);
	level1.play();

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
	vector<Enemy> enemies;

	//enemies animation
	Animation animation(&enemySmallOrange, sf::Vector2u(1, 3), 0.3f);

	//score
	sf::Font font;
	font.loadFromFile("font/fontscore.ttf");
	sf::Text textscore;
	textscore.setFont(font);
	textscore.setString("SCORE : ");
	textscore.setFillColor(sf::Color::Black);
	textscore.setPosition(40, 0);
	textscore.setCharacterSize(40);


	sf::Clock clock;

	while (window.isOpen())
	{
		deltatime = clock.restart().asSeconds();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

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
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Up)
			{
				mainmenu.moveUp();
				break;
			}
			if (event.key.code == sf::Keyboard::Down)
			{
				mainmenu.moveDown();
				break;
			}
			if (event.key.code == sf::Keyboard::Return)
			{
				int x = mainmenu.mainmenuPressed();
				if (x == 0)
				{
					printf("play button was pressed\n");
				}
				if (x == 1)
				{
					printf("score botton was pressed\n");
				}
				if (x == 2)
				{
					printf("quit button was pressed\n");
				}
			}
		}
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
				Enemymini1.Sprite_enemy.setPosition(window.getSize().x, rand() % int(window.getSize().y - Enemymini1.Sprite_enemy.getSize().y));
				enemies.push_back(Enemy(Enemymini1));

				enemySpawnTimer = 0;
			}

			for (int i = 0; i < enemies.size(); i++)
			{
				enemies[i].Update(deltatime , i);
				/*cout << cos(i) << endl;*/
				if (enemies[i].Sprite_enemy.getPosition().x < -130)
				{
					enemies.erase(enemies.begin() + i);
				}

			}


			//collistion
			for (size_t i = 0; i < bullets.size(); i++)
			{
				for (size_t j = 0; j < enemies.size(); j++)
				{
					if (bullets[i].Sprite_bullet.getGlobalBounds().intersects(enemies[j].Sprite_enemy.getGlobalBounds()))
					{
						bullets.erase(bullets.begin() + i);
						enemies.erase(enemies.begin() + j);
						score += 10;
						//UI
						textscore.setString("SCORE : " + to_string(score));
						break;
					}
				}

			}


			for (Background& background : backgrounds)
				background.Update(deltatime);

			//animation update
			animation.Update(1, deltatime);

			//draw
			window.clear();


			//draw background
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
			for (int i = 0; i < enemies.size(); i++)
			{
				enemies[i].Draw(window);
			}

			//draw player
			player.Draw(window);

			//draw text
			window.draw(textscore);
			
			//draw mainmenu
			mainmenu.Draw(window);

			window.display();

	}
	return 0;
}