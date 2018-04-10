#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(480, 180), "The title");

	sf::ConvexShape triangle;
	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f(100, 0));
	triangle.setPoint(1, sf::Vector2f(100, 100));
	triangle.setPoint(2, sf::Vector2f(0, 100));
	triangle.setFillColor(sf::Color::Blue);

	while (window.isOpen())
	{
		//Handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
				window.close();
		}

		//Update scene

		//Render cycle
		window.clear(sf::Color::Black);

		window.draw(triangle);

		window.display();
	}

	return 0;
}

