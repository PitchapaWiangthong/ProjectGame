#pragma once
#include <SFML/Graphics.hpp>
class DropItem
{
public:
	sf::RectangleShape Sprite_Itemfruit;
	sf::Vector2f itemfruitposition;
	sf::Vector2f movement;

	DropItem(sf::Texture* texture);
	~DropItem();

	void Update(float delteTime);
	void Draw(sf::RenderWindow& window);
	void move(float deltatime);

	float dx = 0;
	float dy = 0;
	float speed = 100;
	int n_b = 0;
	int n_g = 0;
	int n_c = 0;
	int n_w = 0;
private:
	sf::Vector2f imageSize;
};

