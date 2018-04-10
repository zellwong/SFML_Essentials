#include <SFML/Window.hpp>

int main()
{
	sf::Window window(sf::VideoMode(800, 640), "The title");

	//Game loop
	while (window.isOpen())
	{
		/* Game loop stages:

		1. Handle input - handle events from input devices and the window
		2. Update frame - update objects in the scene
		3. Render frame - render objects from the scene onto the window

		*/
	}

	return 0;
}

