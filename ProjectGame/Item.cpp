#include "Item.h"

Item::Item(sf::Texture& texture , const sf::Vector2i &row_colum , float startTime):
	row(row_colum.x) ,
	colum(row_colum.y)

{
	srand(time(NULL));
	
	this->Sprite_item.setTexture(texture);
	this->currentframe.x = texture.getSize().x / row;
	this->currentframe.y = texture.getSize().y / colum;
	this->Sprite_item.setTextureRect(sf::IntRect(0, 0, this->currentframe.x, this->currentframe.y));
	this->Sprite_item.setPosition(rand()%1000 , rand() % 768);
	this->Sprite_item.setScale(1.3,1.3);
	
	this->startTime = startTime;
}

Item::~Item() { }

void Item::Update(const float &deltaTime)
{
	lifetime -= deltaTime;
	this->Sprite_item.setTextureRect(sf::IntRect(currentframe.x * 0, currentframe.y * i, currentframe.x, currentframe.y));
	this->offsetanimation += deltaTime;
	if (offsetanimation > 0.2)
	{
		offsetanimation -= 0.2;
		i++;
	}
	if (i >= colum)
	{
		i = 0;
	}

}

void Item::Draw(sf::RenderWindow& window)
{
	window.draw(this->Sprite_item);
}

void Item::move(float deltaTime)
{
}
