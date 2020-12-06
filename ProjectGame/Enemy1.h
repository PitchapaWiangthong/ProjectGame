#pragma once
#include <SFML/Graphics.hpp>
class Enemy1
{
public:
	sf::RectangleShape Sprite_enemy_1;
	sf::Vector2f enemyposition_1;

	Enemy1(sf::Texture* texture);
	~Enemy1();

	void Update(float deltatime, int i);
	void Draw(sf::RenderWindow& window);
	void move(float deltatime);

	int bloodenemybig = 3;
	float dx = 0;
	float dy = 0;
	float speed = 150;
private:
	int offsetanimation = 1;
	float offset = 0;

	sf::Vector2f imageSize;
};

