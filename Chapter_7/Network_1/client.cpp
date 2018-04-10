#include <SFML/Network.hpp>
#include <iostream>

int main() {
  sf::TcpSocket tcpSocket;
  // Connect onto the local host
  if (tcpSocket.connect(sf::IpAddress::LocalHost, 45000) != sf::Socket::Done) {
    // Connection failed - abort!
    return -1;
  }

  // Send some data to the other client

  const int msgSize = 100;
  char message[msgSize] = "Nice hat you have there";
  if (tcpSocket.send(message, msgSize) != sf::Socket::Done) {
    // Something went wrong - data was not sent
  }

  tcpSocket.disconnect();

  return 0;
}