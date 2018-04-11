#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

int main() {
  sf::ContextSettings settings;
  settings.depthBits = 24;
  settings.stencilBits = 8;
  settings.majorVersion = 3;
  settings.minorVersion = 0;
  settings.antialiasingLevel = 2;
  sf::RenderWindow window(sf::VideoMode(640, 480),
                          "OpenGL - Window is ready to receive OpenGL calls",
                          sf::Style::Default, settings);

  settings = window.getSettings();
  std::cout << "depthBits: " << settings.depthBits << std::endl;
  std::cout << "stencilBits: " << settings.stencilBits << std::endl;
  std::cout << "antialiasingLevel: " << settings.antialiasingLevel << std::endl;
  std::cout << "version: " << settings.majorVersion << "." << settings.minorVersion
            << std::endl;

  std::cout << "Window is ready to receive OpenGL calls!\n";

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
  }

  return 0;
}
