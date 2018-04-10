#include <SFML/Graphics.hpp>
#include "AssetManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(320, 320), "Views - Rotation : 0");
	AssetManager manager;

	auto wSize = window.getSize();
	//The view is centered around the world point (0; 0) 
	//The view has the size of the window
	sf::View view(sf::Vector2f(0, 0), sf::Vector2f(wSize.x, wSize.y));

	//Set rotation view.setRotation(...);

	window.setView(view);

	sf::Vector2f spriteSize = sf::Vector2f(32, 32);
	auto& texture = AssetManager::GetTexture("myTexture.png");
	sf::Sprite sprite1(texture);
	sprite1.setOrigin(spriteSize * 0.5f);
	sprite1.setPosition(sf::Vector2f(-80, -80));

	sf::Sprite sprite2(texture);
	sprite2.setOrigin(spriteSize * 0.5f);
	sprite2.setPosition(sf::Vector2f(80, -80));

	sf::Sprite sprite3(texture);
	sprite3.setOrigin(spriteSize * 0.5f);
	sprite3.setPosition(sf::Vector2f(80, 80));

	sf::Sprite sprite4(texture);
	sprite4.setOrigin(spriteSize * 0.5f);
	sprite4.setPosition(sf::Vector2f(-80, 80));

	sf::Clock clock;
	while (window.isOpen())
	{
		//Returns the elapsed time and restarts the clock
		sf::Time deltaTime = clock.restart();

		sf::Event ev;
		while (window.pollEvent(ev))
		{
		}

		window.clear(sf::Color::Black);

		window.draw(sprite1);
		window.draw(sprite2);
		window.draw(sprite3);
		window.draw(sprite4);

		window.display();
	}

	//After main() returns, the manager is destroyed
	return 0;
}

