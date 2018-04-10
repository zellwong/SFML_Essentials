#include <SFML/Window.hpp>

int main() {
  sf::Window window(sf::VideoMode(800, 640), "The title");

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
    }

    // Update scene using input

    // Render scene
  }

  return 0;
}