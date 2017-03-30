#include <iostream>
#include <SFML/Graphics.hpp>

class Game{
public:
	Game()
	:GameWindow(sf::VideoMode(600, 800), "Footlan2k17")
	, Player1()
	{
		Player1.setRadius(50);
		Player1.setFillColor(sf::Color::Red);
		Player1.setPosition(100, 100);
	}

	void run(){
		while (GameWindow.isOpen()) {
			proccessEvents();
			update();
			render();
		}
	}

private:
	void proccessEvents(){
		sf::Event event;
		while (GameWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				GameWindow.close();
			}
		}
	}
	void update(){

	}
	void render(){
		GameWindow.clear(sf::Color::Black);
		GameWindow.draw(Player1);
		GameWindow.display();
	}

	sf::RenderWindow GameWindow;
	sf::CircleShape Player1;
};



int main(int argc, char *argv[])
{
	Game game;
	game.run();
	//	g++ main.cpp -lsfml-window -lsfml-system -lsfml-graphics

	return 0;
}
