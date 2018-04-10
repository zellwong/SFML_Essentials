#include <SFML/Graphics.hpp>
#include "AssetManager.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(640, 480), "AssetManager");
  AssetManager manager;

  sf::Vector2i spriteSize(32, 32);
  sf::Sprite sprite(AssetManager::GetTexture("spriteSheet.png"));
  // Set the sprite image to the first frame of the animation
  sprite.setTextureRect(sf::IntRect(0, 0, spriteSize.x, spriteSize.y));

  int framesNum = 8;            // Animation consists of 8 frames
  float animationDuration = 1;  // 1 second

  sf::Time elapsedTime;
  sf::Clock clock;
  while (window.isOpen()) {
    // Returns the elapsed time and restarts the clock
    sf::Time deltaTime = clock.restart();
    // Accumulate time with each frame
    elapsedTime += deltaTime;
    float timeAsSeconds = elapsedTime.asSeconds();

    // Get the current animation frame
    int animFrame =
        static_cast<int>((timeAsSeconds / animationDuration) * framesNum) % framesNum;
    // Set the texture rectangle, depending on the frame
    sprite.setTextureRect(
        sf::IntRect(animFrame * spriteSize.x, 0, spriteSize.x, spriteSize.y));

    // Render frame
    window.clear(sf::Color::Black);

    window.draw(sprite);

    window.display();
  }

  // After main() returns, the manager is destroyed
  return 0;
}
