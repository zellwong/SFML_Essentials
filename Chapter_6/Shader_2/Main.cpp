#include <SFML/Graphics.hpp>
#include "AssetManager.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(640, 480), "Shaders");
  AssetManager m;

  if (!sf::Shader::isAvailable()) return -1;  // Shaders are not supported. Abort!

  auto shader = AssetManager::GetShader("vertShader.vert", "rippleShader.frag");

  sf::Sprite sprite(AssetManager::GetTexture("myTexture.png"));

  shader->setParameter("uTexture", *sprite.getTexture());
  shader->setParameter("uPositionFreq", 0.1f);
  shader->setParameter("uSpeed", 20);
  shader->setParameter("uStrength", 0.03f);

  sf::Clock clock;
  while (window.isOpen()) {
    sf::Event ev;
    while (window.pollEvent(ev)) {
    }

    window.clear();

    shader->setParameter("uTime", clock.getElapsedTime().asSeconds());

    window.draw(sprite, shader);

    window.display();
  }

  return 0;
}