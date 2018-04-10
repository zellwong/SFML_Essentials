#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main() {
  sf::Window window(sf::VideoMode(640, 480), "Audio");

  sf::SoundBuffer sBuffer;
  if (!sBuffer.loadFromFile("mySound.ogg")) return -1;

  sf::Sound sound(sBuffer);

  sound.play();

  while (window.isOpen()) {
  }

  return 0;
}
