#pragma once
#include<SFML/Graphics.hpp>
class Hitbox
{
private:
	sf::Sprite& sprite;
	sf::RectangleShape hitbox;
	float offsetX;
	float offsetY;

	Hitbox(sf::Sprite& sprite,
		float offset_x, float offset_y,
		float width, float height);
	~Hitbox();

	bool checkIntersect(const sf::FloatRect& frect);

	void update();
	void render(sf::RenderTarget& target);


public:

};

