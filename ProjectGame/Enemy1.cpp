#include "Enemy1.h"

Enemy1::Enemy1(sf::Texture& texture, const sf::Vector2i& row_colum):
	row(row_colum.x),
	colum(row_colum.y)
{
	srand(time(NULL));

	this->Sprite_enemy1.setTexture(texture);
	this->currentframe.x = texture.getSize().x / row;
	this->currentframe.y = texture.getSize().y / colum;
	this->Sprite_enemy1.setTextureRect(sf::IntRect(0, 0, this->currentframe.x, this->currentframe.y));


	hitbox[1].setFillColor(sf::Color::Transparent);
	hitbox[1].setOutlineThickness(1.f);
	hitbox[1].setOutlineColor(sf::Color::Magenta);
	hitbox[1].setSize(sf::Vector2f(130.f, 150.f));
	hitbox[1].setOrigin(Sprite_enemy1.getGlobalBounds().width / 2, Sprite_enemy1.getGlobalBounds().height / 2);

	hitbox[2].setFillColor(sf::Color::Transparent);
	hitbox[2].setOutlineThickness(1.f);
	hitbox[2].setOutlineColor(sf::Color::Blue);
	hitbox[2].setSize(sf::Vector2f(280.f, 120.f));
	hitbox[2].setOrigin(Sprite_enemy1.getGlobalBounds().width / 2, Sprite_enemy1.getGlobalBounds().height / 2);
}

Enemy1::~Enemy1() { }

void Enemy1::Update(const float &deltaTime)
{
	this->Sprite_enemy1.setTextureRect(sf::IntRect(currentframe.x * 0, currentframe.y * i, currentframe.x, currentframe.y));
	this->offsetanimation += deltaTime;
	Sprite_enemy1.move(deltaTime * -250,0);
	if (offsetanimation > 0.6)
	{
		offsetanimation -= 0.6;
		i++;
	}
	if (i >= colum)
	{
		i = 0;
	}

	hitbox[1].setPosition(Sprite_enemy1.getPosition().x + 63, Sprite_enemy1.getPosition().y + 130);
	hitbox[2].setPosition(Sprite_enemy1.getPosition().x + 220, Sprite_enemy1.getPosition().y + 100);
}

void Enemy1::Draw(sf::RenderWindow& window)
{
	window.draw(this->Sprite_enemy1);
	/*for (int i = 0; i < 10; i++)
	{
		window.draw(hitbox[i]);
	}*/
}

void Enemy1::Move(float deltaTime)
{

}
