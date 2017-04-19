#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "consts.h"
#include "ResourceManager.h"
#include "Vector2.h"
#include "Entity.h"

class Game {
public:
	Game();
	~Game();
	void run();

private:
	void proccessEvents();
	void update();
	void render();
	sf::RenderWindow m_gameWindow;
	ResourceManager<std::string, sf::Texture> m_textures;
	// NEK ZA SADA STOJI OVO OVAKO, IZVESCEMO KLASE IZ 
	// OVE OSNOVNE
	Entity* m_ball;
	Entity* m_serbian_chetnik;
	sf::Sprite m_field;
};
#endif
