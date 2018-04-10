#include <SFML/Graphics.hpp>
#include "AssetManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "RenderTexture");
	AssetManager m;

	if (!sf::Shader::isAvailable())
		return -1; //Shaders are not supported. Abort!

	auto shader = AssetManager::GetShader("vertShader.vert", "fragShader.frag");

	sf::Sprite sprite(AssetManager::GetTexture("myTexture.png"));

	while (window.isOpen())
	{
		window.clear();

		window.draw(sprite, shader);

		window.display();
	}

	return 0;
}