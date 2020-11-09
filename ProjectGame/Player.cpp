#include "Player.h"

Player::Player(sf::Vector2f position)
{
	Texture_shipplayer.loadFromFile("player/spriteplayer1.png");
	Sprite_ship.setTexture(Texture_shipplayer);
	shipposition.x = Texture_shipplayer.getSize().x / 2;
	shipposition.y = Texture_shipplayer.getSize().y / 2;
	sf::Vector2f spawnPoint = { 0.f,350.f };
	Sprite_ship.setPosition(spawnPoint);

}

Player::~Player()
{

}

void Player::Update()
{
	Sprite_ship.setTextureRect(sf::IntRect(shipposition.x * 0, shipposition.y * 0,shipposition.x,shipposition.y));
	Sprite_ship.setScale(0.6,0.6);
}
void Player::Draw(sf::RenderWindow& window)
{
	window.draw(Sprite_ship);
}
void Player::move(float deltatime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && Sprite_ship.getPosition().x < 875)
	{
		dx = 1.0;
		Sprite_ship.setTextureRect(sf::IntRect(shipposition.x * 0, shipposition.y * 0, shipposition.x, shipposition.y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && Sprite_ship.getPosition().x > 0)
	{
		dx = -1.0;
		Sprite_ship.setTextureRect(sf::IntRect(shipposition.x * 0, shipposition.y * 0, shipposition.x, shipposition.y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && Sprite_ship.getPosition().y > -45)
	{
		dy = -1.0;
		Sprite_ship.setTextureRect(sf::IntRect(shipposition.x * 1, shipposition.y * 1, shipposition.x, shipposition.y));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Sprite_ship.getPosition().y < 670)
	{
		dy = 1.0;
		Sprite_ship.setTextureRect(sf::IntRect(shipposition.x * 1, shipposition.y * 0, shipposition.x, shipposition.y));
	}

	movement.x = dx * speed * deltatime;
	movement.y = dy * speed * deltatime;
	Sprite_ship.move(movement);
	dx = 0;
	dy = 0;
}
const sf::Vector2f Player::Posi_ship()
{
	return sf::Vector2f(Sprite_ship.getPosition());
}

