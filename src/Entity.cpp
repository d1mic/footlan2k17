#include "headers/Entity.h"
#include "headers/consts.h"
#include <iostream>

Entity::Entity(double x, double y, const sf::Texture& texture)
    :m_position(x, y), m_image(texture)
{
    m_image.setPosition(x, y);
    m_radius = m_image.getTexture()->getSize().x;
    m_center.x = x + m_radius/2;
    m_center.y =  y + m_radius/2;


}
Entity::Entity(const sf::Vector2f& position, const sf::Texture& texture)
    :m_position(position), m_image(texture)
{
    m_image.setPosition(position.x, position.y);
    m_radius = m_image.getTexture()->getSize().x;
    m_center.x = position.x + m_radius;
    m_center.y = position.y + m_radius;

}

const sf::Vector2f& Entity::position() const {
    return m_position;
}
const sf::Vector2f& Entity::center() const {
    return m_center;
}
const sf::Sprite& Entity::image() const {
    return m_image;
}
const int Entity::radius() const {
  return m_radius;
}

void Entity::setPosition(double x, double y) {
    m_position.x = x;
    m_position.y = y;
}
void Entity::setPosition(const sf::Vector2f& position) {
    m_position.x = position.x;
    m_position.y = position.y;
}

void Entity::update() {

}
void Entity::render(sf::RenderWindow& window) {
    window.draw(m_image);
}
bool Entity::colisionEntity(const Entity& entity){
  float distance = abs(sqrt( ( (entity.center().x - m_position.x) * (entity.center().x - m_position.x)) + ((entity.center().y - m_position.y) * (entity.center().y - m_position.y))));
  return (distance <= entity.radius() + m_radius)? true : false;
}

bool Entity::colisionField()
{
  if (m_center.x + m_radius/2 >= WINDOW_WIDTH || m_center.y + m_radius/2 >= WINDOW_HEIGHT
     || m_center.x - m_radius/2 <= 0 || m_center.y - m_radius/2 <= 0) {
    return true;
  }

  return false;
}
