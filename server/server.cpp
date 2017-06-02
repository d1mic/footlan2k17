#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>

void clear(unsigned short *port1,sf::Packet &packet_send1,unsigned short *port2,sf::Packet &packet_send2);
void send(unsigned short port1,sf::Packet packet_send1,int nation1,unsigned short port2,sf::Packet packet_send2,int nation2,sf::IpAddress ip);

sf::UdpSocket socket;

int main ()
{
  socket.bind(20000);
  sf::IpAddress ip;
  unsigned short port, port1=0, port2=0;
  int nation1,nation2;
  sf::Packet packet_send1,packet_send2,packet_receive;
  sf::SocketSelector selector;
  selector.add(socket);

  while (true) {
    if (selector.wait(sf::milliseconds(1))) {
      if (socket.receive(packet_receive,ip,port) == sf::UdpSocket::Done) {
        if (port1==0) {
          if (packet_receive >> nation1) {
            port1=port;
          }
        }
        else if (port2==0) {
          if (packet_receive >> nation2)
            port2=port;
          // socket.unbind();
          send(port1,packet_send1,nation1,port2,packet_send2,nation2,ip);
          // socket.bind(20000);
          clear(&port1,packet_send1,&port2,packet_send2);
        }
      }
    }
  }

  return 0;
}

void send(unsigned short port1,sf::Packet packet_send1,int nation1,unsigned short port2,sf::Packet packet_send2,int nation2,sf::IpAddress ip)
{
  packet_send1 << port2 << nation2;
  socket.send(packet_send1,ip,port1);
  packet_send2 << port1 << nation1;
  socket.send(packet_send2,ip,port2);
}

void clear(unsigned short *port1,sf::Packet &packet_send1,unsigned short *port2,sf::Packet &packet_send2)
{
  *port1=0;
  *port2=0;
  packet_send1.clear();
  packet_send2.clear();
}
