#pragma once
#define Max_main_menu 3
#include <SFML/Graphics.hpp>

class Mainmenu
{
public:
	Mainmenu(float width, float height);
	void Draw(sf::RenderWindow& window);
	

	~Mainmenu();

private:
	
	sf::Font font;
	sf::Text mainMenu[Max_main_menu];
};

