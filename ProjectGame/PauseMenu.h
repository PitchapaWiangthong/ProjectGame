#pragma once
#include <SFML/Graphics.hpp>

class PauseMenu
{
public:
	PauseMenu(sf::Vector2f position);
	~PauseMenu();

	void Draw(sf::RenderWindow& window);
	sf::Sprite Sprite_Button_pause;
	sf::Texture Texture_Button_pause;
	
	sf::Text pauseMenu;
	sf::RectangleShape hitbox;
};

