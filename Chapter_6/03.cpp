#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(640, 480), "RenderTexture");

  sf::RenderTexture rTexture;
  rTexture.create(32, 32, /*Depth buffer enabled = */ false);

  sf::CircleShape circle(16);  // Circle radius = 16

  // Render routine - clear -> draw -> display
  rTexture.clear();

  rTexture.draw(circle);

  rTexture.display();

  // RenderTexture::getTexture() gets a ref to the Texture object
  sf::Sprite sprite(rTexture.getTexture());

  // Use the sprite in any way we like

  while (true) {
    window.clear();

    window.draw(sprite);

    window.display();
  }

  return 0;
}