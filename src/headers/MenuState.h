#ifndef MENUSTATE_H_
#define MENUSTATE_H_

#include "Game.h"
#include "State.h"
#include "TeamState.h"
#include <vector>

class MenuState : public State {
public:
    MenuState(Game* game);
    ~MenuState();

    void update();
    void render(sf::RenderWindow& window);
    void keyboard(sf::Keyboard::Key& key);
private:
    sf::Sprite m_background;
    sf::Sprite m_ball;
    std::vector<sf::Text> m_options;
    short m_selected;

    void setBallPosition(); // pozicionira lopticu pored svake opcije
};

#endif