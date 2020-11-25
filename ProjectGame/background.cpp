#include "Background.h"
#include <iostream>
using namespace std;
Background::Background(sf::Texture* texture, float speed)
{
	this->speed = speed;
	this->size = sf::Vector2f(5000.f, 800.f);
	
	body[0].setSize(size);
	body[1].setSize(size);
	body[0].setTexture(texture);
	body[1].setTexture(texture);

	if (speed < 0)
	{
		body[1].setPosition(size.x , 0.0f);
	}
	else
	{
		body[1].setPosition(-size.x, 0.0f);
	}
}
void Background::Update(float deltatime)
{
	for (int i = 0; i < 2; i++)
	{
		position = body[i].getPosition();
		cout << -size.x << position.x <<endl;
		
		if (position.x -5 < (-size.x) && speed < 0)
			body[i].setPosition(size.x, position.y);
		body[i].move(speed*deltatime, 0);
	}
}
void Background::Draw(sf::RenderWindow& window)
{
	window.draw(body[0]);
	window.draw(body[1]);
}