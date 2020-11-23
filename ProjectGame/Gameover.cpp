#include "Gameover.h"

Gameover::Gameover(float width, float height)
{
	font.loadFromFile(("font/fontscore.ttf"));

	//game over
	GameOverText.setFont(font);
	GameOverText.setFillColor(sf::Color::Red);
	GameOverText.setString("GAME OVER");
	GameOverText.setCharacterSize(80);
	GameOverText.setPosition(350, 192);
	//high score
	HighScoreText.setFont(font);
	HighScoreText.setFillColor(sf::Color::Black);
	HighScoreText.setString("HIGH SCORE : 2340315");
	HighScoreText.setCharacterSize(50);
	HighScoreText.setPosition(300, 300);



}

void Gameover::Draw(sf::RenderWindow& window)
{
	window.draw(GameOverText);
	window.draw(HighScoreText);
}

Gameover::~Gameover()
{
}
