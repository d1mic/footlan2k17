#include <iostream>
#include <SFML/Graphics.hpp>


int main(int argc, char *argv[])
{	
	
	sf::RenderWindow window(sf::VideoMode(600, 800), "Footlan2k17");
	sf::CircleShape circle(50);
	circle.setFillColor(sf::Color::Red);
	circle.setOutlineColor(sf::Color::Blue);
	circle.setOutlineThickness(10);
	circle.setPosition(100, 100);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color::Black);
		window.draw(circle);
		window.display();
	}
	//	g++ main.cpp -lsfml-window -lsfml-system -lsfml-graphics

	return 0;
}
