#include <SFML/Graphics.hpp>
#include "AssetManager.h"

int main() {
  sf::Window window(sf::VideoMode(640, 480), "Audio");
  // Remember, we need an instance of the asset manager
  AssetManager manager;

  sf::Sound sound(AssetManager::GetSoundBuffer(("mySound.ogg")));
  sound.play();

  while (window.isOpen()) {
  }

  return 0;
}
