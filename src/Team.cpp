#include "headers/Team.h"

Team::Team(const sf::Texture& texture, Entity* ball)
{
  //ovaj polozaj treba jos naravno ispraviti
  m_players.push_back(new Entity((WINDOW_WIDTH - 100)/2, 250, texture,0,0));
  m_players.push_back(new Entity((WINDOW_WIDTH - 100)/2 - 150, 120, texture,0,0));
  m_players.push_back(new Entity((WINDOW_WIDTH - 100)/2 + 150, 120, texture,0,0));
  m_ball = ball;
  // kada nije selektovan nijedan igrac, bice vrednost veca od velicine niza
  m_selected = m_players.size() + 1;
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
void Team::mouse(sf::Event::MouseButtonEvent& event) {
  if (event.button == sf::Mouse::Button::Left) {
    /*
    * Kada se desi left click event (pritiskanje/pustanje)
    * proverava se da li je neki igrac selektovan.
    * Ako nije selektovan, to znaci da je mis pritisnut i proveravam
    * na kog igraca je kliknuto. A ako je igrac selektovan i desio se
    * event, to znaci da se desilo odpustanje i tu idu kalkulacije
    */
    // ukoliko nije selektovan nijedan, m_selected ce biti vece od broja igraca
    if (m_selected > m_players.size()) {
      findSelectedPlayer(event.x, event.y);
    } else {
      // Ovde ce ici kod kada se otpusti desni klik, za proracun vektora i cuda
      std::cout << "Selektovan je igrac: " << m_selected << std::endl;
      m_selected = m_players.size() + 1;
    }
  }
}
void Team::findSelectedPlayer(int x, int y) {
  for (size_t i = 0; i < m_players.size(); i++) {
    Entity* p = m_players[i];

    // srediti ovo za proveru da li je u igracu
    // Resiti se ovih konstanti 100 i ubaciti sta vec treba
    // jer u suprotnom ovako hvata poziciju izvan igraca
    if (x >= p->position().x-p->radius() && x <= p->position().x+p->radius()) {
      if (y >= p->position().y-1.5*p->radius() && y <= p->position().y+p->radius()/2) {
        m_selected = i;
        return;
      }
    }
  }
}
