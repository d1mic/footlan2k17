#ifndef TEAMSTATE_H_
#define TEAMSTATE_H_

#include "Game.h"
#include "State.h"
#include "PlayState.h"
#include <vector>
#include <iostream>

class TeamState : public State {

public:
    TeamState(Game* game);
    ~TeamState();

    void update();
    void render(sf::RenderWindow& window);
    void keyboard(sf::Keyboard::Key& key);
    void mouse(sf::Event::MouseButtonEvent& event);
    
private:
    std::vector<std::string> m_teams;
    sf::Sprite m_current, m_left, m_right;
    sf::Sprite m_background;
    sf::Text m_teamName, m_message;
    sf::Vector2f m_currPos;
    int m_selected;

    void setTeams();
};

#endif