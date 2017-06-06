#include "headers/PlayState.h"

PlayState::PlayState(Game* game, const std::string& team, const std::string& team2, unsigned short receive_port, unsigned short send_port, std::string ip)
    :State(game)
{
  m_ball = new Entity(WINDOW_WIDTH/2, WINDOW_HEIGHT/2, game->textures()->get("ball"),0,0);

  m_goal_home = new Goal((WINDOW_WIDTH- GOAL_WIDTH)/2, 0, game->textures()->get("goal2"));
  m_goal_away = new Goal((WINDOW_WIDTH - GOAL_WIDTH)/2, WINDOW_HEIGHT - GOAL_HEIGHT , game->textures()->get("goal"));

  // Inicijalizacija prvog tima i povezivanje
  m_team1 = new Team(game->textures()->get(team), m_ball, m_goal_home,m_goal_away, receive_port, send_port, ip);
  m_team1->setFormation(new Formation(120  , WINDOW_HEIGHT - 120, WINDOW_WIDTH -120 , WINDOW_HEIGHT - 120,  WINDOW_WIDTH/2  , WINDOW_HEIGHT - 250));

  // Inicijalizacija drugog tima i povezivanje
  m_team2 = new Team(game->textures()->get(team2), m_ball, m_goal_home,m_goal_away, receive_port, send_port, ip);
  m_team2->setFormation(new Formation(120, 120, WINDOW_WIDTH-120, 120, WINDOW_WIDTH/2 , 250 ));

  m_field.setTexture(p_game->textures()->get("field"));
	m_field.setScale(0.677,0.625);


  score.x = 0;
  score.y = 0;
  // m_receive_port = receive_port;
  // m_send_port = send_port;
}
PlayState::~PlayState() {
  delete m_ball;

  delete m_goal_home;
  delete m_goal_away;
  delete m_team1;
  delete m_team2;
}
void PlayState::update() {

  m_team1->update();
  m_team2->update();
	m_ball->update();
  isGoal(*m_goal_home,*m_goal_away);

}
void PlayState::render(sf::RenderWindow& window) {
  window.draw(m_field);
	m_ball->render(window);
  m_team1->render(window);
  m_team2->render(window);
  m_goal_home->render(window);
  m_goal_away->render(window);
}
void PlayState::keyboard(sf::Keyboard::Key& key) {
  /* Stavljeno za proveru reset funkcija
  if( key == sf::Keyboard::R){
     m_team1->reset();
     resetBall();
  }*/

}
void PlayState::mouse(sf::Event::MouseButtonEvent& event) {
  m_team1->mouse(event);
}

void PlayState::isGoal(Goal &goal1 , Goal &goal2){
  if(int g = m_ball->isInGoal(goal1,goal2) ){
    if(g == 1) score.x += 1;
    if(g == 2) score.y += 1;
    m_team1->reset();
    m_team2->reset();
    resetBall();
    std::cout << score.x << score.y << std::endl;
  }
  m_ball->checkGoalCollision(goal1,goal2);
}
void PlayState::resetBall(){
  m_ball->setPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
  m_ball->setDirection(0,0);
}
//m_serbian_chetnik->render(window);
