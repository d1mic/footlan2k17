#ifndef TEAM_H_
#define TEAM_H_

#include "Entity.h"
#include "consts.h"
#include "client.h"
#include <vector>

class Team {
public:
    Team(const sf::Texture& texture, Entity* ball,Goal *goal,Goal *goal2, unsigned int port_listen, unsigned int port_send);
    ~Team();
    void render(sf::RenderWindow& window);
    void update();
    void mouse(sf::Event::MouseButtonEvent& event);
    void reset();
    void receiveMessage();

    Entity& player(size_t index) const;
    client m_client;

private:
    std::vector<Entity*> m_players;
    Entity* m_ball;
    Goal *m_goal1;
    Goal *m_goal2;
    // I pokazivac na protivnicki tim
    size_t m_selected;
    unsigned int m_port_send;

    void collisionTeammates(size_t index);
    void findSelectedPlayer(int x, int y);
};

#endif
