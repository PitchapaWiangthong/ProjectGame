#include <SFML/Graphics.hpp>

class Item
{
public:
	sf::Sprite Sprite_item;
	sf::Vector2f itemposition;
	sf::Vector2f movement;

	Item(sf::Texture& texture, const sf::Vector2i &row_colum, float startTime);
	~Item();
	void Update(const float &deltaTime);
	void Draw(sf::RenderWindow& window);
	void move(float deltaTime);

	float startTime = 0;
	float dx = 0;
	float dy = 0;
	float lifetime = 10;

private:
	float offsetanimation = 0;
	sf::Vector2f imageSize;
	sf::Vector2f currentframe;
	short int row = 0;
	short int colum = 0;
	short int i = 0;

};