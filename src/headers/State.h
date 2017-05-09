#ifndef STATE_H_
#define STATE_H_

#include <SFML/Graphics.hpp>
#include "ResourceManager.h"

class Game;

class State
{
public:
    virtual ~State();

    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void keyboard(sf::Keyboard::Key& key) = 0; // Metoda za input sa tastature
    // dodati za mouse input, i eventualno jos nesto
protected:
    State(Game* game);
    Game* p_game;
};

#endif
