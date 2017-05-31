#include "headers/Team.h"

Team::Team(const sf::Texture& texture, Entity* ball, unsigned int port_listen, unsigned int port_send)
  : m_client(port_listen)
  , m_port_send(port_send)
{
  //centralni igrac
  m_players.push_back(new Entity( WINDOW_WIDTH/2  , WINDOW_HEIGHT - 250, texture,0,0));
  // levi igrac
  m_players.push_back(new Entity( 120  , WINDOW_HEIGHT - 120, texture,0,0));
  // desni igrac
  m_players.push_back(new Entity(WINDOW_WIDTH - 120, WINDOW_HEIGHT -120, texture,0,0));
  // lopta
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

    receiveMessage();
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
      // ja sam mislio da ce bolje raditi za .center al ipak je bolje ovako sa .position
      double hit_x = (m_players[m_selected]->position().x - event.x)/10;
      double hit_y = (m_players[m_selected]->position().y - event.y)/10;

      // hit_max regulise koliki je maksimalno jak udarac
      const double hit_max = 20;
      hit_x = ((std::abs(hit_x) > hit_max) ? (hit_x > 0 ? hit_max : - hit_max) : hit_x);
      hit_y = ((std::abs(hit_y) > hit_max) ? (hit_y > 0 ? hit_max : - hit_max) : hit_y);
      // std::cout << hit_x << " " << hit_y << std::endl;

      m_client.send(m_port_send,m_selected,hit_x,hit_y);
      m_players[m_selected]->setDirection(hit_x,hit_y);

      std::cout << m_selected << " " << hit_x << " " << hit_y << std::endl;
      //std::cout << "Selektovan je igrac: " << m_selected << "na poziciji " << event.x << " " << event.y << std::endl;
      m_selected = m_players.size() + 1;
    };
  }
}
void Team::findSelectedPlayer(int x, int y) {
  for (size_t i = 0; i < m_players.size(); i++) {
    Entity* p = m_players[i];

    // srediti ovo za proveru da li je u igracu
    // Resiti se ovih konstanti 100 i ubaciti sta vec treba
    // jer u suprotnom ovako hvata poziciju izvan igraca
    if (x >= p->position().x-p->radius() && x <= p->position().x+p->radius()) {
      if (y >= p->position().y-p->radius() && y <= p->position().y+p->radius()) {
        m_selected = i;
        return;
      }
    }
  }
}
void Team::reset(){

    // centralni igrac
    m_players[0]->setPosition( WINDOW_WIDTH/2  , WINDOW_HEIGHT - 250);
    m_players[0]->setDirection(0,0);
    // levi igrac
    m_players[1]->setPosition( 120  , WINDOW_HEIGHT - 120);
    m_players[1]->setDirection(0,0);
    //desni igrac
    m_players[2]->setPosition( WINDOW_WIDTH - 120  , WINDOW_HEIGHT - 120);
    m_players[2]->setDirection(0,0);

}

void Team::receiveMessage()
{
  m_client.receive(m_players);
}
