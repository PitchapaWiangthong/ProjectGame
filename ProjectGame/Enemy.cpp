#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture)
{
	Sprite_enemy.setTexture(texture);
	Sprite_enemy.setSize(sf::Vector2f(texture->getSize().x, texture->getSize().y / 3));
	enemyposition.x = texture->getSize().x;
	enemyposition.y = texture->getSize().y / 3;
	sf::Vector2f spawnpoint = { 1000.f,256.f };
	Sprite_enemy.setPosition(spawnpoint);
}

Enemy::~Enemy() { }

void Enemy::Update(float deltatime)
{

	Sprite_enemy.setTextureRect(sf::IntRect(enemyposition.x * 0, enemyposition.y * offsetanimation, enemyposition.x, enemyposition.y));
	offset += deltatime;
	if (offset >= 0.1)
	{
		offset -= 0.1;
		offsetanimation++;
	}

	if (offsetanimation >= 2)
	{
		offsetanimation = 0;
	}
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(Sprite_enemy);
}

void Enemy::move(float deltatime)
{
	movement.x = dx * speed * deltatime;
	movement.y = dy * speed * deltatime;
	Sprite_enemy.move(movement);
	dx = 0;
	dy = 0;
}