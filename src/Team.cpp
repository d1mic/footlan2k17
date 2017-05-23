#include "headers/Team.h"

Team::Team(const sf::Texture& texture)
{
  //ovaj polozaj treba jos naravno ispraviti
  m_player1 = new Entity((WINDOW_WIDTH - 100)/2, 250, texture,-3,6);
  m_player2 = new Entity((WINDOW_WIDTH - 100)/2 - 150, 120, texture,-3,6);
  m_player3 = new Entity((WINDOW_WIDTH - 100)/2 + 150, 120, texture,-3,6);
}
Team::~Team() {
    delete m_player1;
    delete m_player2;
    delete m_player3;
}
void Team::update(Entity &other){

  // DA LI MORAJU SVAKA DVA? THAT IS THE QUESTION?
  m_player1->update(other);
  m_player1->update(*m_player2);
  m_player1->update(*m_player3);

  m_player2->update(other);
  m_player2->update(*m_player1);
  m_player2->update(*m_player3);

  m_player3->update(other);
  m_player3->update(*m_player1);
  m_player3->update(*m_player2);

}
Entity& Team::player(const int i){
  switch (i) {
    case 1: return *m_player1; break;
    case 2: return *m_player2; break;
    case 3: return *m_player3; break;
    default: return *m_player1;
  }

}

void Team::render(sf::RenderWindow& window) {
      m_player1->render(window);
      m_player2->render(window);
      m_player3->render(window);
  }
