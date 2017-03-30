#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Game {
public:
	Game();
	void run();

private:
	void proccessEvents();
	void update();
	void render();
	sf::RenderWindow GameWindow;
	sf::CircleShape Player1;
};
#endif
