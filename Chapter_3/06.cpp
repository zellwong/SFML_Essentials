#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(640, 480), "AssetManager");

  sf::Time elapsedTime;
  sf::Clock clock;
  while (window.isOpen()) {
    sf::Time deltaTime = clock.restart();
    // Accumulate time with each frame
    elapsedTime += deltaTime;

    if (elapsedTime > sf::seconds(5)) window.close();
  }

  return 0;
}