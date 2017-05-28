#ifndef TEAM_H_
#define TEAM_H_

#include "Entity.h"
#include "consts.h"
#include <vector>

class Team {
public:
    Team(const sf::Texture& texture, Entity* ball);
    ~Team();
    void render(sf::RenderWindow& window);
    void update();

    Entity& player(size_t index) const;
private:
    std::vector<Entity*> m_players;
    Entity* m_ball;
    // I pokazivac na protivnicki tim

    void collisionTeammates(size_t indeks);
};

#endif
