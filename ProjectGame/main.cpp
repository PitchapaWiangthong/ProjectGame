#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<iostream>


int main()
{
	sf::Clock clock;
	
	//variable
	float deltaTime = 0.0f;

	//player moveset
	sf::Vector2f movement;
	float speed = 500.f;

	//background moveset
	float offsetbackground = 0.0f;
	float ibackground = 0.0f;

	sf::RenderWindow window(sf::VideoMode(1000, 768), "OverWhelm!",sf::Style::Close | sf::Style::Titlebar );
	//texture
	sf::Texture background_test;
	background_test.loadFromFile("wallpaper/test.png");

	
	sf::Texture ship;
	ship.loadFromFile("player/spriteplayer1.png");
	
	sf::Texture bulletB;
	bulletB.loadFromFile("bullet/bulletBlue.png");
	
	sf::Texture bulletR;
	bulletR.loadFromFile("bullet/bulletRed.png");

	sf::Texture bulletG;
	bulletG.loadFromFile("bullet/bulletGreen.png");

	sf::Texture bulletY;
	bulletY.loadFromFile("bullet/bulletYellow.png");

	
	//sprite
	sf::Sprite background;
	background.setTexture(background_test);
	window.setFramerateLimit(60);

	sf::Sprite player(ship);
	int shipX = ship.getSize().x / 2;
	int shipY = ship.getSize().y / 2;
	player.setTextureRect(sf::IntRect(shipX * 0, shipY * 0, shipX, shipY));


	sf::Sprite bB(bulletB);
	//bB.setPosition()
	bB.setScale(2, 2);


	//sound
	sf::SoundBuffer shootingeffect;
	shootingeffect.loadFromFile("sound/shooting.WAV");
	sf::Sound sound1;
	sound1.setBuffer(shootingeffect);


	sf::Vector2f spawnPoint = {0.f,400.f };
	player.setPosition(spawnPoint);
	player.setScale(0.6, 0.6);
	
	float dx = 0;
	float dy = 0;
	

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event e;
		while (window.pollEvent(e));
		{
			if (e.type == e.Closed)
			{
				window.close();
			}
		}
		//Game start

		player.setTextureRect(sf::IntRect(shipX * 0, shipY * 0, shipX, shipY));

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) and player.getPosition().x<875)
		{
			dx = 1.0;
			player.setTextureRect(sf::IntRect(shipX * 0 , shipY * 0, shipX, shipY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) and player.getPosition().x>0)
		{
			dx = -1.0;
			player.setTextureRect(sf::IntRect(shipX * 0 , shipY * 0, shipX, shipY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) and player.getPosition().y>-45)
		{
			dy = -1.0;
			player.setTextureRect(sf::IntRect(shipX *1 , shipY *1 , shipX, shipY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) and player.getPosition().y<670)
		{
			dy = 1.0;
			player.setTextureRect(sf::IntRect(shipX *1 , shipY *0, shipX, shipY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			sound1.play();
			window.draw(bB);
		}

		movement.x = dx * speed * deltaTime;
		movement.y = dy * speed * deltaTime;

		background.setTextureRect(sf::IntRect(ibackground, 0 ,1000 , 768 ));
		offsetbackground += deltaTime;
		if (offsetbackground >= 0.0005)
		{
			ibackground += 3;

			offsetbackground -= 0.0005;
		}
		if (ibackground >= 2048)
		{
			ibackground = 0;
		}
		player.move(movement);
		dx = 0;
		dy = 0;


		window.clear();
		window.draw(background);
		window.draw(player);
		window.display();
	}
	return 0;
}



