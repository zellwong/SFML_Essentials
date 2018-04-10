#include <SFML/Graphics.hpp>

struct Vertex {
  sf::Vector2f Position;
  sf::Vector2f TexCoord;
};

int main() {
  sf::RenderWindow window(sf::VideoMode(640, 480), "Textures");
  // Set target Frames per second
  window.setFramerateLimit(60);

  sf::Texture texture;
  texture.loadFromFile("tile.png");
  // Set the texture in repeat mode
  texture.setRepeated(true);

  sf::RectangleShape rectShape(sf::Vector2f(384, 442));
  // Bigger texture rectangle than the size of the texture
  rectShape.setTextureRect(sf::IntRect(0, 0, 384, 442));

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
