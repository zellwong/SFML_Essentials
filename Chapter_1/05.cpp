#include <SFML/Window.hpp>

int main() {
  sf::Window window(sf::VideoMode(800, 640), "The title");

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::EventType::Closed:
          window.close();
          break;
        case sf::Event::EventType::KeyPressed:
          // Change the title if the space is pressed
          if (event.key.code == sf::Keyboard::Space) window.setTitle("Space pressed");
          break;
        case sf::Event::EventType::KeyReleased:
          // Change the title again if space is released
          if (event.key.code == sf::Keyboard::Space) window.setTitle("Space released");
          // Close the window if the Escape key is released
          else if (event.key.code == sf::Keyboard::Escape)
            window.close();
          break;
        default:
          break;
      }
    }

    // Update scene using input

    // Render scene
  }

  return 0;
}
