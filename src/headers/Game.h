#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"

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
	sf::Sprite bkgSprite;
	ResourceManager<std::string, sf::Texture> textures;
};
#endif
