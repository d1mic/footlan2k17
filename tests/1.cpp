#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <string>
#include <iostream>

// Pozicije kruga koje se salju i menjaju interno, i one koje se dobijaju preko mreze kako bi bile menjane, y je pomeraj
int posX_receive=100,posY_receive=220,y=5,posX_send=330,posY_send=50;
// Socketi za slanje primanje podataka, i selector koji cuva reference na sockete koje zelimo
sf::UdpSocket receiver;
sf::SocketSelector selector;
sf::UdpSocket sender;
sf::IpAddress ipAddress=sf::IpAddress::getLocalAddress();
// Paketi u kojima su smesteni podaci koji se salju i primaju
sf::Packet packet_send;
sf::Packet packet_receive;

void defineWindow(sf::RenderWindow &window,sf::Clock &clock);
void drawCircle(sf::CircleShape &circle_send, sf::CircleShape &circle_receive, sf::RenderWindow &window);
void changePosition ();
void sendMessage(sf::Clock &clock);

int main ()
{
  // Sat koji sluzi kao timer
  sf::Clock clock;

  // "Vezivanje" socketa za port gde ce osluskivati dogadjaje
  receiver.bind(15000);
  // Dodavanje u selektor
  selector.add(receiver);

  sf::RenderWindow window(sf::VideoMode(800,600), "Krugovi");

  defineWindow(window,clock);

  return 0;
}

void defineWindow(sf::RenderWindow &window, sf::Clock &clock)
{
  sf::CircleShape circle_send(50);
  sf::CircleShape circle_receive(50);
  sf::Event event;

  while (window.isOpen()) {
    while(window.pollEvent(event)) {
      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape)
          window.close();
      }
      if (event.type==sf::Event::Closed)
        window.close();
    }

    // Ciscenje sadrzaja prozora
    window.clear(sf::Color::White);

    sendMessage(clock);

    // Promenljiva u koju se smesta sadrzaj paketa ako postoji
    int posX;
    // Adresa sa kojeg su poslati podaci
    sf::IpAddress ip;
    // Port sa kojeg su stigli podaci
    unsigned short port;

    // Cekamo na poruku 1 milisekundu, ako je socket spreman uzimaju se podaci
    if (selector.wait(sf::milliseconds(1))) {
      // Primamo paket
      if (receiver.receive(packet_receive,ip,port) == sf::UdpSocket::Done) {
        // Uzimamo podatke iz paketa
        if (packet_receive >> posX) {
          posX_receive=posX;
        }
      }
    }

    drawCircle(circle_send,circle_receive,window);

    // Ponovno iscrtavanje sadrzaja prozora
    window.display();
  }
}

void drawCircle(sf::CircleShape &circle_send, sf::CircleShape &circle_receive, sf::RenderWindow &window)
{
  circle_send.setFillColor(sf::Color::Yellow);
  circle_send.setOutlineThickness(15);
  circle_send.setOutlineColor(sf::Color::Green);
  circle_send.setPosition(posX_send,posY_send);
  window.draw(circle_send);
  circle_receive.setFillColor(sf::Color::Yellow);
  circle_receive.setOutlineThickness(15);
  circle_receive.setOutlineColor(sf::Color::Red);
  circle_receive.setPosition(posX_receive,posY_receive);
  window.draw(circle_receive);
}

void changePosition ()
{
  if (y>0 && posY_send+y>485) {
    posY_send=485;
    y=-y;
  }
  else if (y<0 && posY_send+y<15) {
    posY_send=15;
    y=-y;
  }
  else
    posY_send=posY_send+y;
}

void sendMessage(sf::Clock &clock)
{
    // Provera da li je prosao neki vremenski period, ako jeste azurira se pozicija kruga i salje se informacija o tome
    // Brzina igre zavisi od intervala, sto su azuriranja cesca, brza je igra
    if (clock.getElapsedTime().asSeconds() >= 0.007) {
      // Pakujemo podatke u paket
      packet_send << posY_send;
      // Saljemo podatke
      sender.send(packet_send,ipAddress,10000);
      // Cistimo paket, praznimo ga
      packet_send.clear();
      changePosition();
      // Restartujemo sat, kako bi krenuo da broji od 0
      clock.restart();
    }
}
