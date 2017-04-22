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
    // Stavljeno zbog testiranja funkcije move
    m_direction.x=5;
    m_direction.y=5;
}
Entity::Entity(const sf::Vector2f& position, const sf::Texture& texture)
    :m_position(position), m_image(texture)
{
    m_image.setPosition(position.x, position.y);
    m_radius = m_image.getTexture()->getSize().x;
    m_center.x = position.x + m_radius/2;
    m_center.y = position.y + m_radius/2;
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
  move();
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
  // Proveravamo da li centar + ili - minus poluprecnik ide do ili preko ivice
  if (m_center.x + m_radius/2 >= WINDOW_WIDTH || m_center.y + m_radius/2 >= WINDOW_HEIGHT
     || m_center.x - m_radius/2 <= 0 || m_center.y - m_radius/2 <= 0) {
    return true;
  }

  return false;
}

void Entity::move()
{
  // Uvecavamo trenutnu poziciju objekta, idemo za x i y koliko kaze vektor pravca
  m_position.x+=m_direction.x;
  m_position.y+=m_direction.y;
  // Proveravamo da li je bilo kolizije
  if (colisionField()) {
    // Ako idemo previse levo postavljamo udaranje u levu ivicu i menjamo pravac x
    if (m_position.x <= 0) {
      m_position.x=0;
      m_direction.x=-m_direction.x;
    }
    // Slicno kao gore samo sto se proverava desna ivica
    else if (m_position.x + m_radius >= WINDOW_WIDTH) {
      m_position.x=WINDOW_WIDTH - m_radius;
      m_direction.x=-m_direction.x;
    }
    // Provera za gornji deo igralista
    else if (m_position.y <= 0) {
      m_position.y = 0;
      m_direction.y=-m_direction.y;
    }
    // Provera za donji deo igralista
    else if (m_position.y + m_radius >= WINDOW_HEIGHT) {
      m_position.y=WINDOW_HEIGHT - m_radius;
      m_direction.y=-m_direction.y;
    }
  }
  // Azurira se centar sprite-a, samim tim i entity-a
  m_center.x = m_position.x + m_radius/2;
  m_center.y = m_position.y + m_radius/2;
  // Postavlja se pozicija teksture kako bi iscrtavanje bilo moguce
  m_image.setPosition(m_position.x,m_position.y);
}
