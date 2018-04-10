#include <SFML/Graphics.hpp>
#include "AssetManager.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(640, 320), "Views - Viewports");
  AssetManager manager;

  auto wSize = window.getSize();

  sf::View viewTL(sf::Vector2f(0, 0), sf::Vector2f(wSize.x, wSize.y));
  viewTL.setViewport(sf::FloatRect(0, 0, 0.5f, 0.5f));

  sf::View viewTR(sf::Vector2f(0, 0), sf::Vector2f(wSize.x, wSize.y));
  viewTR.setViewport(sf::FloatRect(0.5f, 0, 0.5f, 0.5f));
  viewTR.setRotation(45.f);

  sf::View viewBL(sf::Vector2f(0, 0), sf::Vector2f(wSize.x, wSize.y));
  viewBL.setViewport(sf::FloatRect(0, 0.5f, 0.5f, 0.5f));
  viewBL.move(64, 0);

  sf::View viewBR(sf::Vector2f(0, 0), sf::Vector2f(wSize.x, wSize.y));
  viewBR.setViewport(sf::FloatRect(0.5f, 0.5f, 0.5f, 0.5f));
  viewBR.zoom(1.5f);

  std::vector<sf::View> viewList;
  viewList.push_back(viewTL);
  viewList.push_back(viewTR);
  viewList.push_back(viewBL);
  viewList.push_back(viewBR);

  sf::Vector2f spriteSize = sf::Vector2f(32, 32);
  auto& texture = AssetManager::GetTexture("myTexture.png");
  sf::Sprite sprite1(texture);
  sprite1.setOrigin(spriteSize * 0.5f);
  sprite1.setPosition(sf::Vector2f(-80, -80));

  sf::Sprite sprite2(texture);
  sprite2.setOrigin(spriteSize * 0.5f);
  sprite2.setPosition(sf::Vector2f(80, -80));

  sf::Sprite sprite3(texture);
  sprite3.setOrigin(spriteSize * 0.5f);
  sprite3.setPosition(sf::Vector2f(80, 80));

  sf::Sprite sprite4(texture);
  sprite4.setOrigin(spriteSize * 0.5f);
  sprite4.setPosition(sf::Vector2f(-80, 80));

  sf::Clock clock;
  while (window.isOpen()) {
    // Returns the elapsed time and restarts the clock
    sf::Time deltaTime = clock.restart();

    window.clear(sf::Color::Black);

    for (auto it = viewList.begin(); it != viewList.end(); ++it) {
      // Set the view
      window.setView(*it);

      // Render sprites
      window.draw(sprite1);
      window.draw(sprite2);
      window.draw(sprite3);
      window.draw(sprite4);
    }

    window.display();
  }

  // After main() returns, the manager is destroyed
  return 0;
}
