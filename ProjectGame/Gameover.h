#pragma once
#include <SFML/Graphics.hpp>

class Gameover
{
public:
	Gameover(float width, float height);
	void Draw(sf::RenderWindow& window);


	~Gameover();

private:
	sf::Font font;
	sf::Text GameOverText;
	sf::Text HighScoreText;
};

