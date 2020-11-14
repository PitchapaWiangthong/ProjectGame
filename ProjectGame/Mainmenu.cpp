#include "Mainmenu.h"

Mainmenu::Mainmenu(float width, float height)
{
	font.loadFromFile(("font/fontscore.ttf"));

	//play
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::Black);
	mainMenu[0].setString("PLAYGAME");
	mainMenu[0].setCharacterSize(50);
	mainMenu[0].setPosition(400, 192);

	//score
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::Black);
	mainMenu[1].setString("SCORE");
	mainMenu[1].setCharacterSize(50);
	mainMenu[1].setPosition(420, 384);

	//quit
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::Black);
	mainMenu[2].setString("QUIT");
	mainMenu[2].setCharacterSize(50);
	mainMenu[2].setPosition(430, 576);

	mainMenuSelected = 0;
}

void Mainmenu::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
		window.draw(mainMenu[i]);
}

void Mainmenu::moveUp()
{
	if (mainMenuSelected - 1 >= -1)
	{
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Blue);

		mainMenuSelected--;
		if (mainMenuSelected == -1)
		{
			mainMenuSelected = 2;
		}
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Black);
	}
}

void Mainmenu::moveDown()
{
	if (mainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Blue);

		mainMenuSelected++;
		if (mainMenuSelected == 3)
		{
			mainMenuSelected = 0;
		}
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Black);
	}
}

Mainmenu::~Mainmenu()
{
}
