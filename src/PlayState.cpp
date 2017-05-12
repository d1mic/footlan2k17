#include "headers/PlayState.h"

PlayState::PlayState(Game* game)
    :State(game)
{
  m_ball = new Entity(100, 348, game->textures()->get("ball"),12,7);
  m_serbian_chetnik = new Entity(400, 300, game->textures()->get("serbia"),-3,6);

  m_goal_home = new Goal((WINDOW_WIDTH-GOAL_WIDTH)/2, 6, game->textures()->get("goal"));
  m_goal_away = new Goal((WINDOW_WIDTH-GOAL_WIDTH)/2, WINDOW_HEIGHT-100, game->textures()->get("goal2"));
  m_field.setTexture(p_game->textures()->get("field"));
	m_field.setScale(0.677,0.625);
}
PlayState::~PlayState() {
    delete m_ball;
    delete m_serbian_chetnik;
    delete m_goal_home;
    delete m_goal_away;
}
void PlayState::update() {
  m_serbian_chetnik->update(*m_ball);
	m_ball->update(*m_serbian_chetnik);
}
void PlayState::render(sf::RenderWindow& window) {
  window.draw(m_field);
	m_ball->render(window);
	m_serbian_chetnik->render(window);
  m_goal_home->render(window);
  m_goal_away->render(window);
}
void PlayState::keyboard(sf::Keyboard::Key& key) {

}
