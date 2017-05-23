#ifndef TEAM_H_
#define TEAM_H_

#include "Entity.h"
#include "consts.h"


class Team {
public:
    Team(const sf::Texture& texture);
    ~Team();
    void render(sf::RenderWindow& window);
    void update(Entity &other);
    Entity& player(const int i);
private:
  Entity* m_player1;
	Entity* m_player2;
  Entity* m_player3;
};

#endif
