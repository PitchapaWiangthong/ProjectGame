#include "Enemy1.h"

Enemy1::Enemy1(sf::Texture& texture, const sf::Vector2i& row_colum):
	row(row_colum.x),
	colum(row_colum.y)
{
	this->Sprite_enemy1.setTexture(&texture);
	this->currentframe.x = texture.getSize().x / row;
	this->currentframe.y = texture.getSize().y / colum;
	this->Sprite_enemy1.setTextureRect(sf::IntRect(0, 0, this->currentframe.x, this->currentframe.y));

}

Enemy1::~Enemy1() { }

void Enemy1::Update(const float& deltaTime)
{
	this->Sprite_enemy1.setTextureRect(sf::IntRect(currentframe.x * 0, currentframe.y * i, currentframe.x, currentframe.y));
	this->offsetanimation += deltaTime;
	if (offsetanimation > 0.2)
	{
		offsetanimation -= 0.2;
		i++;
	}
	if (i >= colum)
	{
		i = 0;
	}
}

void Enemy1::Draw(sf::RenderWindow& window)
{
	window.draw(this->Sprite_enemy1);
}

void Enemy1::Move(float deltaTime)
{

}
