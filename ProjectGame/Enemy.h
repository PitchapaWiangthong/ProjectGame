#include <SFML/Graphics.hpp>

class Enemy
{
public:
	sf::RectangleShape Sprite_enemy;
	sf::RectangleShape hitbox[10];
	sf::Vector2f enemyposition;
	sf::Vector2f movement;

	Enemy(sf::Texture* texture);
	~Enemy();

	void Update(float deltatime , int i);
	void Draw(sf::RenderWindow& window);
	void move(float deltatime);
	
	int bloodenemymedium = 2;
	float dx = 0;
	float dy = 0;
	float speed = 100;
private:
	

	sf::Vector2f imageSize;


};

