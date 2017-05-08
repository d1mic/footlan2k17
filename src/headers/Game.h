#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "consts.h"
#include "ResourceManager.h"
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
	void start();
	void checkForUpdate();
	sf::RenderWindow m_gameWindow;
	TextureManager m_textures;
	// NEK ZA SADA STOJI OVO OVAKO, IZVESCEMO KLASE IZ
	// OVE OSNOVNE
	Entity* m_ball;
	Entity* m_serbian_chetnik;
	sf::Sprite m_field;
	sf::Clock m_clock;
};
#endif
