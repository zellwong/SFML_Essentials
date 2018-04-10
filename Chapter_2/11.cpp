#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(480, 250), "Textures");
  // Set target Frames per second
  window.setFramerateLimit(60);

  sf::Texture texture;
  texture.loadFromFile("myTexture.png");

  sf::Vector2u textureSize = texture.getSize();
  float rectWidth = static_cast<float>(textureSize.x);
  float rectHeight = static_cast<float>(textureSize.y);
  sf::RectangleShape rectShape(sf::Vector2f(rectWidth, rectHeight));
  rectShape.setTexture(&texture);

  while (window.isOpen()) {
    sf::Event ev;
    window.pollEvent(ev);
    // Handle events

    window.clear(sf::Color::Black);
    window.draw(rectShape);
    window.display();
  }

  return 0;
}
