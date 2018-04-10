#include <SFML/Graphics.hpp>

void setupShape(sf::RectangleShape& shape, sf::Vector2f const& pos, sf::Color const& color)
{
	shape.setFillColor(color);
	shape.setPosition(pos);
	shape.setOrigin(shape.getSize() * 0.5f); // The center of the rectangle
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(480, 180), "Bad Squares");
	//Set target Frames per second
	window.setFramerateLimit(60);

	sf::Vector2f startPos = sf::Vector2f(50, 50);
	sf::RectangleShape playerRect(sf::Vector2f(50, 50));
	setupShape(playerRect, startPos, sf::Color::Green);
	sf::RectangleShape targetRect(sf::Vector2f(50, 50));
	setupShape(targetRect, sf::Vector2f(400, 50), sf::Color::Blue);
	sf::RectangleShape badRect(sf::Vector2f(50, 100));
	setupShape(badRect, sf::Vector2f(250, 50), sf::Color::Red);

	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
		{
		}

		//Always moving right
		playerRect.move(1, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
			playerRect.move(0, 1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
			playerRect.move(0, -1);

		//Target reached. You win. Exit game
		if (playerRect.getGlobalBounds().intersects(targetRect.getGlobalBounds()))
			window.close();
		//Bad square intersect. You lose. Restart
		if (playerRect.getGlobalBounds().intersects(badRect.getGlobalBounds()))
			playerRect.setPosition(startPos);

		window.clear(sf::Color::Black);

		window.draw(badRect);
		window.draw(targetRect);
		window.draw(playerRect);

		window.display();

	}

	return 0;
}

