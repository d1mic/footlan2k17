#include "headers/Entity.h"
#include "headers/consts.h"
#include <iostream>
#include <math.h>

Entity::Entity(double x, double y, const sf::Texture& texture, double x_, double y_)
    :m_position(x, y), m_image(texture)
{
    m_image.setPosition(x, y);
    m_radius = m_image.getTexture()->getSize().x;
    m_center.x = x + m_radius/2;
    m_center.y =  y + m_radius/2;
    // Stavljeno zbog testiranja funkcije move
    m_direction.x=x_;
    m_direction.y=y_;
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

const sf::Vector2f& Entity::direction() const {
    return m_direction;
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
void Entity::setDirection(double x , double y) {
  m_direction.x = x;
  m_direction.y = y;
}

void Entity::setPosition(const sf::Vector2f& position) {
    m_position.x = position.x;
    m_position.y = position.y;
}
void Entity::setDirection(const sf::Vector2f& direction) {
    m_direction.x = direction.x;
    m_direction.y = direction.y;
}

void Entity::setCenter(double x, double y)
{
  m_center.x=x;
  m_center.y=y;
}

void Entity::update(Entity &other) {
  move(other);
}

void Entity::render(sf::RenderWindow& window) {
    window.draw(m_image);
}

bool Entity::colisionEntity(const Entity& entity){
  float distance = abs(sqrt(((entity.center().x - m_center.x) * (entity.center().x - m_center.x)) + ((entity.center().y - m_center.y) * (entity.center().y - m_center.y))));
  return (distance <= entity.radius()/2 + m_radius/2) ? true : false;
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

void Entity::move(Entity &other)
{
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
    // m_direction.x*=0.99;
    // m_direction.y*=0.99;
  }

  if (colisionEntity(other)) {

    double distance = distanceBetweenPoints(other.center().x,other.center().y,m_center.x,m_center.y);

    double nx = (other.center().x - m_center.x) / distance;
    double ny = (other.center().y - m_center.y) / distance;

    double p = (m_direction.x * nx + m_direction.y * ny - other.direction().x * nx - other.direction().y * ny);

    m_direction.x = m_direction.x - p * nx;
    m_direction.y = m_direction.y - p * ny;

    double vx2 = other.direction().x + p * nx;
    double vy2 = other.direction().y + p * ny;
    other.setDirection(vx2,vy2);
    other.setPosition(other.position().x+other.direction().x,other.position().y+other.direction().y);
    other.setCenter(other.position().x+other.radius()/2, other.position().y+other.radius()/2);
  }

  // Uvecavamo trenutnu poziciju objekta, idemo za x i y koliko kaze vektor pravca
  m_position.x+=m_direction.x;
  m_position.y+=m_direction.y;

  // Azurira se centar sprite-a, samim tim i entity-a
  m_center.x = m_position.x + m_radius/2;
  m_center.y = m_position.y + m_radius/2;

  // Postavlja se pozicija teksture kako bi iscrtavanje bilo moguce
  m_image.setPosition(m_position.x,m_position.y);
}
float Entity::distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
  return abs(sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2))));
}
