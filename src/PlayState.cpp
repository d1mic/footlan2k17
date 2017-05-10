#include "headers/PlayState.h"

PlayState::PlayState(Game* game)
    :State(game)
{
    m_ball = new Entity(0, 0, game->textures()->get("ball"));
    m_serbian_chetnik = new Entity(300, 300,
                                   game->textures()->get("serbia"));

    m_field.setTexture(p_game->textures()->get("field"));
	m_field.setScale(0.677,0.625);
}
PlayState::~PlayState() {
    delete m_ball;
    delete m_serbian_chetnik;
}
void PlayState::update() {
    m_serbian_chetnik->update(*m_ball);
	m_ball->update(*m_serbian_chetnik);
}
void PlayState::render(sf::RenderWindow& window) {
    window.draw(m_field);
	m_ball->render(window);
	m_serbian_chetnik->render(window);
}
void PlayState::keyboard(sf::Keyboard::Key& key) {

}
