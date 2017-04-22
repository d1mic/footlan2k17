#include "headers/Game.h"
#include <iostream>

Game::Game()
	:m_gameWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), TITLE)
{
	m_gameWindow.setFramerateLimit(60);
	m_textures.load("ball", "../assets/images/ball.png");
	m_textures.load("serbia", "../assets/images/serbia.png");
	m_textures.load("field", "../assets/images/field.png");

	m_ball = new Entity(0, 0, m_textures.get("ball"));
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
	start();
	while (m_gameWindow.isOpen()) {
		proccessEvents();
		checkForUpdate();
		render();
	}
}
void Game::proccessEvents(){
	sf::Event event;
	while (m_gameWindow.pollEvent(event)) {
		if (event.type == sf::Event::Closed || (event.type==sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
			m_gameWindow.close();
		}
	}
}
void Game::update(){
	// Sluzi samo za testiranje tajmera
	std::cout << "Iiiiideeeemooooo" << std::endl;
}
void Game::render(){
	m_gameWindow.clear(sf::Color::Black);
	m_gameWindow.draw(m_field);
	m_ball->render(m_gameWindow);
	m_serbian_chetnik->render(m_gameWindow);
	m_gameWindow.display();
	std::cout << m_ball->colisionField() << std::endl;
}

void Game::start()
{
	m_clock.restart();
}

void Game::checkForUpdate()
{
	if (m_clock.getElapsedTime().asSeconds() >= UPDATE_TIME) {
		update();
		m_clock.restart();
	}
}
