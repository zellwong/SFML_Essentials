#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(480, 250), "Textures");
	//Set target Frames per second
	window.setFramerateLimit(60);

	sf::Texture texture;
	texture.loadFromFile("myTexture.png");

	sf::ConvexShape shape(5); //Convex shape has 5 points
	shape.setPoint(0, sf::Vector2f(0, 0));
	shape.setPoint(1, sf::Vector2f(200, 0));
	shape.setPoint(2, sf::Vector2f(180, 120));
	shape.setPoint(3, sf::Vector2f(100, 200));
	shape.setPoint(4, sf::Vector2f(20, 120));
	shape.setTexture(&texture);
	shape.setOutlineThickness(2);
	shape.setOutlineColor(sf::Color::Red);
	shape.move(20, 20); //Move it, so the outline is clearly visible

	while (window.isOpen())
	{
		sf::Event ev;
		window.pollEvent(ev);
		//Handle events

		window.clear(sf::Color::Black);
		window.draw(shape);
		window.display();
	}

	return 0;
}

