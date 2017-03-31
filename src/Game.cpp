#include "headers/Game.h"


Game::Game()
	:GameWindow(sf::VideoMode(550, 800), "Footlan2k17"),
	Player1(),
	bkgTexture(),
	bkgSprite()
{
	Player1.setRadius(35);
	Player1.setFillColor(sf::Color::Blue);
	Player1.setPosition(100, 100);

	if(!bkgTexture.loadFromFile("img/footBall.png")){
		//std::cout<<"Error loading picture"<<std::endl;
		//GameWindow.close();
	}
	bkgSprite.setTexture(bkgTexture);
	bkgSprite.setScale(0.677,0.625);

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
	GameWindow.draw(bkgSprite);
	GameWindow.draw(Player1);
	GameWindow.display();
}
