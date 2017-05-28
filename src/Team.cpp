#include "headers/Team.h"

Team::Team(const sf::Texture& texture, Entity* ball)
{
  //ovaj polozaj treba jos naravno ispraviti
  m_players.push_back(new Entity((WINDOW_WIDTH - 100)/2, 250, texture,-3,6));
  m_players.push_back(new Entity((WINDOW_WIDTH - 100)/2 - 150, 120, texture,-3,6));
  m_players.push_back(new Entity((WINDOW_WIDTH - 100)/2 + 150, 120, texture,-3,6));
  m_ball = ball;
}
Team::~Team() {
    for (size_t i = 0; i < m_players.size(); i++) {
      delete m_players[i];
    }
}
void Team::update(){

    for (size_t i = 0; i < m_players.size(); i++) {
        
      m_players[i]->checkEntityCollision(*m_ball); // kolizija pojedinca sa loptom
      collisionTeammates(i); // kolizija sa saigracima
      
      m_players[i]->update();
    }
}
void Team::render(sf::RenderWindow& window) {
    for (size_t i = 0; i < m_players.size(); i++) {
      m_players[i]->render(window);
    }
  }
Entity& Team::player(size_t index) const {
    return *m_players[index];
}
void Team::collisionTeammates(size_t index) {
    size_t size = m_players.size();

    for (size_t i = index+1; i < size; i++) {
      m_players[index]->checkEntityCollision(*m_players[i]);
    }
}