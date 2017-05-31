#include "headers/Goal.h"
#include "iostream"

Goal::Goal(double x, double y, const sf::Texture &texture)
  : m_image(texture)
  , m_position(x,y)
  {
    m_image.setPosition(x,y);
    m_image.setScale(1.3,1);
    /*
    std::cout <<  m_image.getGlobalBounds().left << std::endl;
    std::cout <<  m_image.getGlobalBounds().top << std::endl;
    std::cout <<  m_image.getGlobalBounds().height << std::endl;
    std::cout <<  m_image.getGlobalBounds().width << std::endl;
    std::cout <<  "-------------------------------" << std::endl;
    */
  }

void Goal::render(sf::RenderWindow& window) {
    window.draw(m_image);
}
