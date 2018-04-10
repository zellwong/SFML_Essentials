#include <SFML/Network.hpp>
#include <iostream>

int main() {
  sf::UdpSocket socket;
  // Bind the socket to a port so it can receive data
  socket.bind(45000);

  // Receive the data
  const std::size_t size = 100;
  char data[size];
  std::size_t readSize;
  sf::IpAddress senderIP;
  unsigned short remotePort;
  if (socket.receive(data, size, readSize, senderIP, remotePort) != sf::Socket::Done) {
    // Something went wrong - data was not received
    return -1;
  }

  std::cout << "Received data from: " << senderIP << " on " << remotePort << std::endl;
  std::cout << data << std::endl;

  // Unbind the socket
  socket.unbind();

  return 0;
}