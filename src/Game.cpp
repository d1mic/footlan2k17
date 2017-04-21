#include "headers/Game.h"


Game::Game()
	:m_gameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), TITLE)
{
	m_gameWindow.setFramerateLimit(60);
	m_textures.load("ball", "../assets/images/ball.png");
	m_textures.load("serbia", "../assets/images/serbia.png");
	m_textures.load("field", "../assets/images/field.png");

	m_ball = new Entity(100, 100, m_textures.get("ball"));
	m_serbian_chetnik = new Entity(300, 300, m_textures.get("serbia"));
	m_field.setTexture(m_textures.get("field"));
	m_field.setScale(0.677,0.625);
}
Game::~Game()
{
	delete m_ball;
	delete m_serbian_chetnik;
}
void Game::run(){
	while (m_gameWindow.isOpen()) {
		proccessEvents();
		update();
		render();
	}
}
void Game::proccessEvents(){
	sf::Event event;
	while (m_gameWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_gameWindow.close();
		}
	}
}
void Game::update(){

}
void Game::render(){
	m_gameWindow.clear(sf::Color::Black);
	m_gameWindow.draw(m_field);
	m_ball->render(m_gameWindow);
	m_serbian_chetnik->render(m_gameWindow);
	m_gameWindow.display();
}
