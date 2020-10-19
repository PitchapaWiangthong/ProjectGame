#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 768), "OverWhelm!");
	
	//texture
	sf::Texture wall;
	wall.loadFromFile("wallpaper/background1.png");
	
	
	sf::Texture ship;
	ship.loadFromFile("player/spriteplayer1.png");
	
	//sprite
	sf::Sprite swall(wall);
	swall.setScale(1, 1);

	sf::Sprite player(ship);
	int shipX = ship.getSize().x / 2;
	int shipY = ship.getSize().y / 2;
	player.setTextureRect(sf::IntRect(shipX * 0, shipY * 0, shipX, shipY));

	sf::Vector2f spawnPoint = {0.f,400.f };
	player.setPosition(spawnPoint);
	player.setScale(0.6, 0.6);

	sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	player.move(1.f, 0.f);

	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e));
		{

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		player.setTextureRect(sf::IntRect(shipX * 0, shipY * 0, shipX, shipY));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			player.move(.1f, 0.f);
			player.setTextureRect(sf::IntRect(shipX * 0 , shipY * 0, shipX, shipY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			player.move(-.1f, 0.f);
			player.setTextureRect(sf::IntRect(shipX * 0 , shipY * 0, shipX, shipY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			player.move(0.f, -.1f);
			player.setTextureRect(sf::IntRect(shipX *1 , shipY *1 , shipX, shipY));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			player.move(0.f, .1f);
			player.setTextureRect(sf::IntRect(shipX *1 , shipY *0, shipX, shipY));
		}

		window.clear();
		window.draw(swall);
		window.draw(player);
		window.display();
	}
	return 0;
}


