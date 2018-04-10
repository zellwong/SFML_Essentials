#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(480, 180), "The title");

	sf::RectangleShape rect(sf::Vector2f(50, 50));
	rect.setFillColor(sf::Color::Red);
	rect.setPosition(sf::Vector2f(50, 50));
	rect.setRotation(30);
	rect.setScale(sf::Vector2f(2, 1));

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

		window.draw(rect);

		window.display();
	}

	return 0;
}

