#include <SFML/Network.hpp>

int main()
{
	sf::UdpSocket udpSocket;

	//Send some data to the other client
	const int msgSize = 100;
	char message[msgSize] = "Nice hat you have there";
	if (udpSocket.send(message, msgSize,
		sf::IpAddress::LocalHost, 45000) != sf::Socket::Done)
	{
		//Something went wrong - data was not sent
	}

	return 0;
}