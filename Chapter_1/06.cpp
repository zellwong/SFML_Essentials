#include <SFML/Window.hpp>

int main() {
  sf::Window window(sf::VideoMode(800, 640), "The title");

  sf::String buffer;
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::EventType::Closed:
          window.close();
          break;
        case sf::Event::EventType::TextEntered:
          // Add the character directly to the string
          buffer += event.text.unicode;
          break;
        case sf::Event::EventType::KeyReleased:
          // Change the title to the current buffer and clear the buffer
          if (event.key.code == sf::Keyboard::Key::Return) {
            window.setTitle(buffer);
            buffer.clear();
          }
          break;
        default:
          break;
      }
    }
  }

  return 0;
}
