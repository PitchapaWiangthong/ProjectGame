#pragma once
#include <SFML/Graphics.hpp>
class Enemy1
{
public:
	sf::RectangleShape Sprite_enemy1;
	sf::Vector2f enemy1position;
	sf::Vector2f movement;

	Enemy1(sf::Texture& texture, const sf::Vector2i& row_colum);
	~Enemy1();
	void Update(const float& deltaTime);
	void Draw(sf::RenderWindow& window);
	void Move(float deltaTime);

	int bloodenemybig = 4;
	float dx = 0;
	float dy = 0;

private:
	float offsetanimation = 0;
	sf::Vector2f imageSize;
	sf::Vector2f currentframe;
	short int row = 0;
	short int colum = 0;
	short int i = 0;
};

