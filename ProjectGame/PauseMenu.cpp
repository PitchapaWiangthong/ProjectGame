#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::Vector2f position)
{
	Texture_Button_pause.loadFromFile("pause/pausebutton.png");
	Sprite_Button_pause.setTexture(Texture_Button_pause);
	Sprite_Button_pause.setScale(0.1, 0.1);
	sf::Vector2f spawnPoint = { 940.f,10.f };
	Sprite_Button_pause.setPosition(spawnPoint);

	hitbox.setSize(sf::Vector2f(Sprite_Button_pause.getGlobalBounds().width,Sprite_Button_pause.getGlobalBounds().height));
	hitbox.setPosition(sf::Vector2f(Sprite_Button_pause.getGlobalBounds().left,Sprite_Button_pause.getGlobalBounds().top));
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::Draw(sf::RenderWindow& window)
{
		window.draw(Sprite_Button_pause);
}
