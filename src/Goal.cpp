#include "headers/Goal.h"

Goal::Goal(double x, double y, const sf::Texture &texture)
  : m_image(texture)
  , m_position(x,y)
  {
    m_image.setPosition(x,y);
  }

void Goal::render(sf::RenderWindow& window) {
    window.draw(m_image);
}
