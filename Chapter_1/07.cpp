#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(640, 480), "The title");

  while (window.isOpen()) {
    // Handle events
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::EventType::Closed) window.close();
    }

    // Update scene

    // Render cycle
    window.clear(sf::Color::Black);

    // Render objects

    window.display();
  }

  return 0;
}
