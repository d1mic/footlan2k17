#include "headers/ClientConnection.h"
#include <iostream>

ClientConnection::ClientConnection()
{
  m_socket.bind(sf::Socket::AnyPort);
  m_selector.add(m_socket);
  m_port_receive = m_socket.getLocalPort();
  // m_ip = sf::IpAddress::getLocalAddress();
}

void ClientConnection::send(int selected)
{
  m_packet << selected;
  // std::cout << m_selected << std::endl;

  m_socket.send(m_packet,m_ip,20000);
}

bool ClientConnection::wait()
{
  // std::cout << "USAO" << std::endl;
  unsigned short port;
  if (m_selector.wait(sf::milliseconds(1))) {
    if (m_socket.receive(m_packet,m_ip,port) == sf::UdpSocket::Done)
      if (m_packet >> m_port_send >> m_selected) {
        m_socket.unbind();
        return true;
      }
  }
  return false;
}

unsigned short ClientConnection::send()
{
  return m_port_send;
}
unsigned short ClientConnection::receive()
{
  return m_port_receive;
}
int ClientConnection::selected()
{
  return m_selected;
}
