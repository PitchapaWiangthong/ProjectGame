#include "Mainmenu.h"

Mainmenu::Mainmenu(float width, float height)
{
	font.loadFromFile(("font/fontscore.ttf"));

	//play
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::Black);
	mainMenu[0].setString("PLAYGAME");
	mainMenu[0].setCharacterSize(50);
	mainMenu[0].setPosition(490, 270);
	mainMenu[0].setOrigin(mainMenu[0].getGlobalBounds().width / 2, mainMenu[0].getGlobalBounds().height / 2);

	//how to play
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::Black);
	mainMenu[1].setString("HOW TO PLAY");
	mainMenu[1].setCharacterSize(50);
	mainMenu[1].setPosition(480, 340);
	mainMenu[1].setOrigin(mainMenu[1].getGlobalBounds().width / 2, mainMenu[1].getGlobalBounds().height / 2);

	//score
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::Black);
	mainMenu[2].setString("SCORE");
	mainMenu[2].setCharacterSize(50);
	mainMenu[2].setPosition(475, 410);
	mainMenu[2].setOrigin(mainMenu[2].getGlobalBounds().width / 2, mainMenu[2].getGlobalBounds().height / 2);

	//quit
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(sf::Color::Black);
	mainMenu[3].setString("QUIT");
	mainMenu[3].setCharacterSize(50);
	mainMenu[3].setPosition(470, 480);
	mainMenu[3].setOrigin(mainMenu[3].getGlobalBounds().width / 2, mainMenu[3].getGlobalBounds().height / 2);

	
	for (unsigned short int i = 0; i < Max_main_menu; i++)
	{
		 hitbox[i].setSize(sf::Vector2f(mainMenu[i].getGlobalBounds().width , mainMenu[i].getGlobalBounds().height));
		 hitbox[i].setPosition(sf::Vector2f(mainMenu[i].getGlobalBounds().left, mainMenu[i].getGlobalBounds().top));
	}

}

void Mainmenu::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 4; i++)
		window.draw(mainMenu[i]);
}


Mainmenu::~Mainmenu()
{
}
