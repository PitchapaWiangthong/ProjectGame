#include<iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Background.h"
#include "Player.h"
#include "Bullet.h"

using namespace std;
int main()
{
	//window
	sf::RenderWindow window(sf::VideoMode(1000, 768), "OverWhelm!", sf::Style::Titlebar | sf::Style::Close);

	//variable
	float deltatime = 0.0f;


	//background
	sf::Texture bgTexture[2];
	bgTexture[0].loadFromFile("wallpaper/stage1.jpg");
	bgTexture[1].loadFromFile("wallpaper/stage1.jpg");

	vector<Background> backgrounds;
	backgrounds.push_back(Background(&bgTexture[0], -125.f));
	backgrounds.push_back(Background(&bgTexture[1], -125.f));
	Player player(sf::Vector2f(0.f, 400.f));

	//sound
	sf::SoundBuffer shootimgeffect;
	shootimgeffect.loadFromFile("sound/shooting.WAV");
	sf::Sound soundbullet;
	soundbullet.setBuffer(shootimgeffect);


	//bullets
	sf::Texture bulletB;
	bulletB.loadFromFile("bullet/bulletBlue.png");
	Bullet Bulletblue(&bulletB);
	Bulletblue.Sprite_bullet.setScale(0.8, 0.8);
	vector<Bullet> bullets;


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
		
		//set position bullet
		Bulletblue.Sprite_bullet.setPosition(player.Sprite_ship.getPosition().x + (player.Sprite_ship.getGlobalBounds().width)-20,
			player.Sprite_ship.getPosition().y + ((player.Sprite_ship.getGlobalBounds().height) / 2) + 20);


		//Spacebar KeyPressed 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			soundbullet.play();
			bullets.push_back(Bullet(Bulletblue));
		}

		//bullets movement
		for (int i = 0; i < bullets.size(); i++)
		{
			bullets[i].Sprite_bullet.move(1, 0);
		}
			
				for (Background& background : backgrounds)
						background.Update(deltatime);

		window.clear();

				for (Background& background : backgrounds)

			background.Draw(window);
			player.Update();
			player.move(deltatime);

				for (int i = 0; i < bullets.size(); i++)
				{
					bullets[i].Draw(window);
				}

			player.Draw(window);

		window.display();

	}
	return 0;
}