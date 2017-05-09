#include "headers/MenuState.h"

MenuState::MenuState(Game* game)
    :State(game)
{
    m_background.setTexture(p_game->textures()->get("menu2"));
    m_options.push_back(sf::Text("Start Game", p_game->fonts()->get("menu"), 40));
    m_options.push_back(sf::Text("About", p_game->fonts()->get("menu"), 40));
    m_options.push_back(sf::Text("Exit", p_game->fonts()->get("menu"), 40));

    m_ball.setTexture(p_game->textures()->get("ball"));

    m_options[0].setPosition(50, WINDOW_HEIGHT - 350);
    m_options[1].setPosition(50, m_options[0].getPosition().y + 80);
    m_options[2].setPosition(50, m_options[1].getPosition().y + 80);

    m_selected = 0;

    setBallPosition();
}
MenuState::~MenuState() {

}

void MenuState::update() {

}
void MenuState::render(sf::RenderWindow& window) {
    window.draw(m_background);
    for (auto it = m_options.cbegin(); it != m_options.cend(); it++) {
        window.draw(*it);
    }
    window.draw(m_ball);
}
void MenuState::setBallPosition() {
    sf::Vector2f textPosition = m_options[m_selected].getPosition();
    unsigned textWidth = m_options[m_selected].getLocalBounds().width;

    m_ball.setPosition(textPosition.x + textWidth + 30, textPosition.y + m_ball.getGlobalBounds().height/2);
}

void MenuState::keyboard(sf::Keyboard::Key& key) {
    if (key == sf::Keyboard::Key::S) {
        m_selected = (m_selected+1) % m_options.size();
        setBallPosition();
    } else if (key == sf::Keyboard::Key::W) {
        m_selected--;
        if (m_selected < 0)
            m_selected = m_options.size()-1;
        setBallPosition();
    } else if (key == sf::Keyboard::Key::Space) {
        if (m_selected == 0) {
            p_game->changeState(new PlayState(p_game));
        } else if ((size_t)m_selected == m_options.size()-1) {
            p_game->exit();
        }
    }
}