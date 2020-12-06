#include "Enemy1.h"

Enemy1::Enemy1(sf::Texture* texture)
{
	Sprite_enemy_1.setTexture(texture);
	Sprite_enemy_1.setSize(sf::Vector2f(texture->getSize().x / 2, texture->getSize().y));
	enemyposition_1.x = texture->getSize().x / 2;
	enemyposition_1.y = texture->getSize().y;
	sf::Vector2f spawnpoint = { 1000.f,256.f };
	Sprite_enemy_1.setPosition(spawnpoint);
	Sprite_enemy_1.setScale(1.25, 1.25);

}

Enemy1::~Enemy1()
{
}

void Enemy1::Update(float deltatime, int i)
{
	Sprite_enemy_1.move(deltatime * -200, cos(i));
	if (cos(i) > 0)
	{
		Sprite_enemy_1.setTextureRect(sf::IntRect(enemyposition_1.x * 0, enemyposition_1.y * 1, enemyposition_1.x, enemyposition_1.y));
	}
	if (cos(i) < 0)
	{
		Sprite_enemy_1.setTextureRect(sf::IntRect(enemyposition_1.x * 0, enemyposition_1.y * 0, enemyposition_1.x, enemyposition_1.y));
	}
	else
	{
		Sprite_enemy_1.setTextureRect(sf::IntRect(enemyposition_1.x * 0, enemyposition_1.y * 1, enemyposition_1.x, enemyposition_1.y));

	}

}

void Enemy1::Draw(sf::RenderWindow& window)
{
	window.draw(Sprite_enemy_1);
}

void Enemy1::move(float deltatime)
{
}
