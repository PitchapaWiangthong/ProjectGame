#include "Bullet.h"

Bullet::Bullet(sf::Texture *texture)
{
	Sprite_bullet.setTexture(texture);
	Sprite_bullet.setSize(sf::Vector2f(texture->getSize().x, texture->getSize().y));
	Sprite_bullet.setOrigin(0, Sprite_bullet.getSize().y / 2);

}

Bullet::~Bullet()
{
}


void Bullet::Update()
{
	
}


void Bullet::Draw(sf::RenderWindow& window)
{
	window.draw(Sprite_bullet);
}

