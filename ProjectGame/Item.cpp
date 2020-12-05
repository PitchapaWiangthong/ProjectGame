#include "Item.h"
#include "Enemy.h"

Item::Item(sf::Texture* texture)
{

	Sprite_Item.setTexture(texture);
	Sprite_Item.setSize(sf::Vector2f(texture->getSize().x, texture->getSize().y));

}

Item::~Item()
{
}

void Item::update()
{
	/*Sprite_Item.setPosition(.getPosition());*/
}

void Item::Draw(sf::RenderWindow& window)
{
}
