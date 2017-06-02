#ifndef CLINETCONNECTION_H
#define CLINETCONNECTION_H

#include <SFML/Network.hpp>

class ClientConnection {
public:
  ClientConnection();
  void send(int selected);
  bool wait();
  unsigned short send();
  unsigned short receive();
  int selected();

private:
  sf::UdpSocket m_socket;
  sf::SocketSelector m_selector;
  unsigned short m_port_receive;
  unsigned short m_port_send;
  sf::Packet m_packet;
  sf::IpAddress m_ip;
  int m_selected;
};
#endif
