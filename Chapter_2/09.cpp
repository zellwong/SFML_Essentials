#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(480, 250), "Textures");
	//Set target Frames per second
	window.setFramerateLimit(60);

	sf::Texture texture;
	texture.loadFromFile("myTexture.png");

	sf::RectangleShape rectShape(sf::Vector2f(300, 150));
	rectShape.setTexture(&texture);

	while (window.isOpen())
	{
		sf::Event ev;
		window.pollEvent(ev);
		//Handle events

		window.clear(sf::Color::Black);
		window.draw(rectShape);
		window.display();
	}

	return 0;
}

