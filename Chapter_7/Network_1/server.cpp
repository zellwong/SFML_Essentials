#include <SFML/Network.hpp>
#include <iostream>

int main()
{
	//Star listening for incoming sockets
	sf::TcpListener listener;
	listener.listen(45000);

	//Wait until the listener has accepted a valid connection
	sf::TcpSocket socket;
	if (listener.accept(socket) != sf::Socket::Done)
		return -1;

	sf::sleep(sf::seconds(1));

	//Read the data
	const std::size_t size = 100;
	char data[size];
	std::size_t readSize;
	if (socket.receive(data, size, readSize) != sf::Socket::Done)
	{
		//Something went wrong - data was not received
		return -1;
	}

	std::cout << data << std::endl;

	return 0;
}