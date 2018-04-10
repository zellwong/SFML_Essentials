#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(480, 180), "The title");

  sf::CircleShape circleShape(50);
  circleShape.setFillColor(sf::Color::Red);
  circleShape.setOutlineColor(sf::Color::White);
  circleShape.setOutlineThickness(3);

  sf::RectangleShape rectShape(sf::Vector2f(50, 50));
  rectShape.setFillColor(sf::Color::Green);

  while (window.isOpen()) {
    // Handle events
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::EventType::Closed) window.close();
    }

    // Update scene

    // Render cycle
    window.clear(sf::Color::Black);

    window.draw(circleShape);
    window.draw(rectShape);

    window.display();
  }

  return 0;
}
