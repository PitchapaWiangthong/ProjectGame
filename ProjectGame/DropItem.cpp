#include "DropItem.h"

DropItem::DropItem(sf::Texture* texture)
{
	Sprite_Itemfruit.setTexture(texture);
	Sprite_Itemfruit.setSize(sf::Vector2f(texture->getSize().x, texture->getSize().y));
	Sprite_Itemfruit.setScale(0.8,0.8);
	itemfruitposition.x = texture->getSize().x;
	itemfruitposition.y = texture->getSize().y;
	sf::Vector2f spawnpoint = { 500.f,-10.f };
	Sprite_Itemfruit.setPosition(spawnpoint);
}

DropItem::~DropItem() { }

void DropItem::Update(float delteTime)
{
	Sprite_Itemfruit.move(0, delteTime * 400);

}

void DropItem::Draw(sf::RenderWindow& window)
{
	window.draw(Sprite_Itemfruit);
}

void DropItem::move(float deltatime)
{

}
