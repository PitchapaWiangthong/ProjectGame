#include "Item.h"

Item::Item(sf::Texture& texture , const sf::Vector2i &row_colum):
	row(row_colum.x) ,
	colum(row_colum.y)

{
	this->Sprite_item.setTexture(texture);
	this->currentframe.x = texture.getSize().x / row;
	this->currentframe.y = texture.getSize().y / colum;
	this->Sprite_item.setTextureRect(sf::IntRect(0, 0, this->currentframe.x, this->currentframe.y));
	this->Sprite_item.setPosition(0, 0);



}

Item::~Item() { }

void Item::Update(const float& delteTime)
{
	this->Sprite_item.setTextureRect(sf::IntRect(currentframe.x * 0, currentframe.y * i, currentframe.x, currentframe.y));
	this->offsetanimation += delteTime;
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
