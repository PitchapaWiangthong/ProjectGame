#pragma once
#include <SFML/Graphics.hpp>


class Item 
{
public: 
	sf::RectangleShape Sprite_Item;
	Item(sf::Texture* texture);
	~Item();

	void update();
	void Draw(sf::RenderWindow& window);


};

