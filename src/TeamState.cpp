#include "headers/TeamState.h"

TeamState::TeamState(Game* game)
    :State(game)
{
    m_teams = {
        "serbia",
        "spain",
        "russia"
    };
    m_selected = m_teams.size() / 2;
    m_background.setTexture(p_game->textures()->get("menu"));
    
    m_current.setPosition(WINDOW_WIDTH/2 - 75, WINDOW_HEIGHT-300);
    m_current.setScale(1.5, 1.5);
    m_currPos = m_current.getPosition();

    

    m_left.setScale(0.8, 0.8);
    m_left.setPosition(m_currPos.x - 80, m_currPos.y+50);
    m_left.setColor(sf::Color(255, 255, 255, 128));
    
    m_right.setScale(0.8, 0.8);
    m_right.setPosition(m_currPos.x + 150, m_currPos.y+50);
    m_right.setColor(sf::Color(255, 255, 255, 100));
    
    setTeams();

    

    m_teamName = sf::Text(m_teams[m_selected], p_game->fonts()->get("menu_font2"), 25);
    m_teamName.setPosition((m_currPos.x + 75) - ((m_teams[m_selected].size()/2.0)*15), m_currPos.y + 150);

    m_message = sf::Text("select your team", p_game->fonts()->get("menu_font2"), 30);
    m_message.setPosition(m_currPos.x - 80, m_currPos.y - 50);
}
TeamState::~TeamState() {

}

void TeamState::update() {

}
void TeamState::render(sf::RenderWindow& window) {
    window.draw(m_background);
    window.draw(m_current);
    window.draw(m_left);
    window.draw(m_right);
    window.draw(m_teamName);
    window.draw(m_message);
}
void TeamState::keyboard(sf::Keyboard::Key& key) {

    if (key == sf::Keyboard::Key::D) {
        m_selected = (m_selected + 1) % m_teams.size();
    } else if (key == sf::Keyboard::Key::A) {
        m_selected = (m_selected == 0 ? m_teams.size()-1 : m_selected-1);
    } else if (key == sf::Keyboard::Key::Space) {
        
        p_game->changeState(new PlayState(p_game));
        return;// mora return da se ne bi izvrsilo ovo setTeams nakon promene
    }

    setTeams();

}
void TeamState::setTeams() {
    m_current.setTexture(p_game->textures()->get(m_teams[m_selected]));
    m_teamName.setString(m_teams[m_selected]);
    
    m_teamName.setPosition((m_currPos.x + 75) - ((m_teamName.getString().getSize()/2.0)*15), m_currPos.y + 150);

    int leftVal = m_selected == 0 ? m_teams.size() - 1 : m_selected - 1;
    int rightVal = m_selected == (int)m_teams.size()-1 ? 0 : m_selected + 1;
    
    m_left.setTexture(p_game->textures()->get(m_teams[leftVal]));
    m_right.setTexture(p_game->textures()->get(m_teams[rightVal]));
}
void TeamState::mouse(sf::Event::MouseButtonEvent& event) {

}