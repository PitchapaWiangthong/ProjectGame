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

void Enemy::Update(float deltatime , int i)
{
	Sprite_enemy.move(deltatime * -200, cos(i));
	if (cos(i) > 0)
	{
		Sprite_enemy.setTextureRect(sf::IntRect(enemyposition.x * 0, enemyposition.y * 0, enemyposition.x, enemyposition.y));
	}
	if (cos(i) < 0)
	{
		Sprite_enemy.setTextureRect(sf::IntRect(enemyposition.x * 0, enemyposition.y * 2, enemyposition.x, enemyposition.y));
	}
	else
	{
		Sprite_enemy.setTextureRect(sf::IntRect(enemyposition.x * 0, enemyposition.y * 1, enemyposition.x, enemyposition.y));
	}
	
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(Sprite_enemy);
}

void Enemy::move(float deltatime)
{

}