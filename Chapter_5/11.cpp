#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "AssetManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Audio");
	AssetManager manager;

	//Listener at the center of the window
	sf::Listener::setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f, 0);
	//The listener is facing UP (-Y)
	sf::Listener::setDirection(0, -1, 0);

	//Shape for the listener (world representation)
	sf::CircleShape shapeListener(20);
	shapeListener.setFillColor(sf::Color::Red);

	sf::Sound sound(AssetManager::GetSoundBuffer("mySound.ogg"));
	//Sound will start to fade away from the listener when it's
	//more than 160 pixels away from the listener ( 640 / 4 = 160)
	sound.setMinDistance(window.getSize().x / 4.f);
	//Sound will fade quite quickly, once it passes the 160 pixel boundary
	sound.setAttenuation(20.f);

	//Shape for the sound (world representation)
	sf::CircleShape shapeSound(10);
	shapeSound.setFillColor(sf::Color::White);

	while (window.isOpen())
	{
		//Handle events
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			//Close window on close button click
			if (ev.type == sf::Event::Closed)
				window.close();
			//Play the sound on mouse button click
			else if (ev.type == sf::Event::MouseButtonPressed)
				sound.play();
		}

		//Get 2D listener position
		sf::Vector2f listenerPos(sf::Listener::getPosition().x, sf::Listener::getPosition().y);
		//Set listener position (constant for this example)
		shapeListener.setPosition(listenerPos);

		//Set sound position
		sf::Vector2f soundPos(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		sound.setPosition(soundPos.x, soundPos.y, 0);
		shapeSound.setPosition(soundPos);

		//Render frame
		window.clear();

		window.draw(shapeListener);
		window.draw(shapeSound);

		window.display();
	}

	return 0;
}