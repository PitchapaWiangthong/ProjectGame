#include <SFML/Graphics.hpp>

class Bullet
{
public:
	sf::RectangleShape Sprite_bullet;
	Bullet(sf::Texture* texture);
	~Bullet();
	void Update();
	void Draw(sf::RenderWindow& window);

private:

};

