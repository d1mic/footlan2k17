#include "Game.h"


Game::Game()
	:GameWindow(sf::VideoMode(600, 800), "Footlan2k17"), Player1()
{
	Player1.setRadius(50);
	Player1.setFillColor(sf::Color::Red);
	Player1.setPosition(100, 100);
}

void Game::run(){
	while (GameWindow.isOpen()) {
		proccessEvents();
		update();
		render();
	}
}
void Game::proccessEvents(){
	sf::Event event;
	while (GameWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			GameWindow.close();
		}
	}
}
void Game::update(){
}
void Game::render(){
	GameWindow.clear(sf::Color::Black);
	GameWindow.draw(Player1);
	GameWindow.display();
}
