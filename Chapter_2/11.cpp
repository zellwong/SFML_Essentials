#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(480, 250), "Textures");
  // Set target Frames per second
  window.setFramerateLimit(60);

  sf::Texture texture;
  texture.loadFromFile("leaf.png");

  sf::Vector2u textureSize = texture.getSize();
  float rectWidth = static_cast<float>(textureSize.x);
  float rectHeight = static_cast<float>(textureSize.y);
  sf::RectangleShape rectShape(sf::Vector2f(rectWidth, rectHeight));
  rectShape.setTexture(&texture);

  while (window.isOpen()) {
    // Handle events
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::EventType::Closed:
          window.close();
          break;
        case sf::Event::EventType::KeyPressed:
          if (event.key.code == sf::Keyboard::Escape) window.close();
          break;
        default:
          break;
      }
    }

    window.clear(sf::Color::Black);
    window.draw(rectShape);
    window.display();
  }

  return 0;
}
