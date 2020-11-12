#include <SFML/Graphics.hpp>

class Enemy
{
public:
	sf::RectangleShape Sprite_enemy;
	sf::Vector2f enemyposition;
	sf::Vector2f movement;

	Enemy(sf::Texture* texture);
	~Enemy();

	void Update(float deltatime , int i);
	void Draw(sf::RenderWindow& window);
	void move(float deltatime);
	
	float dx = 0;
	float dy = 0;
	float speed = 200;
private:
	int offsetanimation = 1;
	float offset = 0;

	sf::Vector2f imageSize;


};

