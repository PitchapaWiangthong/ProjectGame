#pragma once
#include <SFML\Graphics.hpp>

class Player
{
public:
	sf::Sprite Sprite_ship;
	Player(sf::Vector2f position);
	~Player();

	void Update(); 
	void Draw(sf::RenderWindow& window);
	void move(float deltatime);

	const sf::Vector2f Posi_ship();
	const sf::Vector2f position() { return Sprite_ship.getPosition(); };

	float dx = 0;
	float dy = 0;

private:
	sf::Texture Texture_shipplayer;
	sf::Vector2f shipposition;

	float speed = 400;
	sf::Vector2f movement;
};
