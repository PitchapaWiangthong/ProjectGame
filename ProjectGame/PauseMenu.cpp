#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::Vector2f position)
{
	Texture_Button.loadFromFile("pause/pausebutton.png");
	Sprite_Button.setTexture(Texture_Button);
	Sprite_Button.setScale(0.1, 0.1);
	sf::Vector2f spawnPoint = { 940.f,10.f };
	Sprite_Button.setPosition(spawnPoint);
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::Draw(sf::RenderWindow& window)
{
	window.draw(Sprite_Button);
}
