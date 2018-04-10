#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(480, 180), "Animation");
  // Set target Frames per second
  window.setFramerateLimit(60);

  sf::RectangleShape rect(sf::Vector2f(50, 50));
  rect.setFillColor(sf::Color::Red);
  rect.setOrigin(sf::Vector2f(25, 25));
  rect.setPosition(sf::Vector2f(50, 50));

  while (window.isOpen()) {
    /*Handle events here*/

    // Update frame
    rect.setRotation(rect.getRotation() + 1.5f);
    rect.move(sf::Vector2f(1, 0));

    // Render frame
    window.clear(sf::Color::Black);
    window.draw(rect);
    window.display();
  }
  return 0;
}
