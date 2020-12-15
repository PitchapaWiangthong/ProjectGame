#include "Enemy.h"

Enemy::Enemy(sf::Texture* texture)
{
	Sprite_enemy.setTexture(texture);
	Sprite_enemy.setSize(sf::Vector2f(texture->getSize().x, texture->getSize().y / 3));
	enemyposition.x = texture->getSize().x;
	enemyposition.y = texture->getSize().y / 3;
	sf::Vector2f spawnpoint = { 1000.f,256.f };
	Sprite_enemy.setPosition(spawnpoint);

	hitbox[0].setFillColor(sf::Color::Transparent);
	hitbox[0].setOutlineThickness(1.f);
	hitbox[0].setOutlineColor(sf::Color::Red);
	hitbox[0].setSize(sf::Vector2f(100.f,40.f));
	hitbox[0].setOrigin(Sprite_enemy.getGlobalBounds().width / 2, Sprite_enemy.getGlobalBounds().height / 2);

	hitbox[1].setFillColor(sf::Color::Transparent);
	hitbox[1].setOutlineThickness(1.f);
	hitbox[1].setOutlineColor(sf::Color::Yellow);
	hitbox[1].setSize(sf::Vector2f(150.f, 70.f));
	hitbox[1].setOrigin(Sprite_enemy.getGlobalBounds().width / 2, Sprite_enemy.getGlobalBounds().height / 2);

	hitbox[2].setFillColor(sf::Color::Transparent);
	hitbox[2].setOutlineThickness(1.f);
	hitbox[2].setOutlineColor(sf::Color::Cyan);
	hitbox[2].setSize(sf::Vector2f(50.f, 70.f));
	hitbox[2].setOrigin(Sprite_enemy.getGlobalBounds().width / 2, Sprite_enemy.getGlobalBounds().height / 2);
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

	hitbox[0].setPosition(Sprite_enemy.getPosition().x + 63, Sprite_enemy.getPosition().y + 100);
	hitbox[1].setPosition(Sprite_enemy.getPosition().x + 90, Sprite_enemy.getPosition().y + 90);
	hitbox[2].setPosition(Sprite_enemy.getPosition().x + 90, Sprite_enemy.getPosition().y + 70);

}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(Sprite_enemy);
	/*for(int i = 0;i<10;i++)
	{
		window.draw(hitbox[i]);
	}*/
	
}

