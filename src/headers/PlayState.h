#ifndef PLAYSTATE_H_
#define PLAYSTATE_H_

#include "Game.h"
#include "State.h"
#include "Entity.h"
#include "Goal.h"
#include "Team.h"

class PlayState : public State {
public:
    PlayState(Game* game, const std::string& team,unsigned short receive_port, unsigned short send_port);
    ~PlayState();

    void update();
    void render(sf::RenderWindow& window);
    void keyboard(sf::Keyboard::Key& key);
    void mouse(sf::Event::MouseButtonEvent& event);
    void resetBall();
    void isGoal(Goal &goal1 , Goal &goal2);
private:
  Entity* m_ball;
	Entity* m_serbian_chetnik;
  Goal *m_goal_home;
  Goal *m_goal_away;
  Team *m_team1;
  sf::Sprite m_field;
  unsigned short m_receive_port;
  unsigned short m_send_port;
};

#endif
