#include <SFML/Graphics.hpp>

void renderTextureSet(sf::Vector2f const& origin, sf::Shape& shape,
                      sf::RenderWindow& window) {
  // Move to the origin and scale down
  shape.setPosition(origin);
  shape.setScale(0.5f, 0.5f);
  window.draw(shape);

  // Move right, normal scaling
  shape.move(100, 0);
  shape.setScale(1, 1);
  window.draw(shape);

  // Move right and scale up
  shape.move(150, 0);
  shape.setScale(1.5f, 1.5f);
  window.draw(shape);
}

int main() {
  sf::RenderWindow window(sf::VideoMode(640, 442), "Textures");

  sf::Texture texture;
  texture.loadFromFile("myTexture.png");

  sf::RectangleShape rectShape(sf::Vector2f(texture.getSize().x, texture.getSize().y));
  rectShape.setOrigin(rectShape.getSize() * 0.5f);
  rectShape.setTexture(&texture);

  while (window.isOpen()) {
    sf::Event ev;
    window.pollEvent(ev);
    // Handle events

    window.clear(sf::Color::Black);

    texture.setSmooth(false);
    renderTextureSet(sf::Vector2f(50, 120), rectShape, window);
    texture.setSmooth(true);
    renderTextureSet(sf::Vector2f(50, 340), rectShape, window);

    window.display();
  }

  return 0;
}
