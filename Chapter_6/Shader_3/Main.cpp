#include <SFML/Graphics.hpp>
#include <iostream>
#include "AssetManager.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Pixelation");
  AssetManager m;

  if (!sf::Shader::isAvailable()) return -1;  // Shaders are not supported. Abort!

  sf::RenderTexture rTexture;
  auto wSize = window.getSize();
  rTexture.create(wSize.x, wSize.y);

  // The sprite used for post-processing the texture
  sf::Sprite ppSprite(rTexture.getTexture());

  // The shader used for post-processing the texture
  auto shader = AssetManager::GetShader("vertShader.vert", "pixelationShader.frag");

  shader->setParameter("uTexture", rTexture.getTexture());
  shader->setParameter("uTextureSize", static_cast<sf::Vector2f>(rTexture.getSize()));
  shader->setParameter("uPixelSize", 8);

  sf::Sprite sprite(AssetManager::GetTexture("myTexture.png"));

  while (window.isOpen()) {
    // Handle events
    sf::Event ev;
    while (window.pollEvent(ev)) {
    }

    /* Update frame here */

    // Render frame
    rTexture.clear();
    {
      /* Draw scene here */
      rTexture.draw(sprite);
    }
    rTexture.display();

    window.clear();
    {
      // Post processing by applying the shader to the RenderTexture
      window.draw(ppSprite, shader);
    }
    window.display();
  }

  return 0;
}