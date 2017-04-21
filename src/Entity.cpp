#include "headers/Entity.h"

Entity::Entity(double x, double y, const sf::Texture& texture)
    :m_position(x, y), m_image(texture)
{
    m_image.setPosition(x, y);
    m_radius = m_image.getTexture()->getSize().x;
    m_center.setBoth(x + m_radius , y + m_radius);


}
Entity::Entity(const Vector2f& position, const sf::Texture& texture)
    :m_position(position), m_image(texture)
{
    m_image.setPosition(position.x(), position.y());
    m_radius = m_image.getTexture()->getSize().x;
    m_center.setBoth(position.x() + m_radius , position.y() + m_radius);

}

const Vector2f& Entity::position() const {
    return m_position;
}
const Vector2f& Entity::center() const {
    return m_center;
}
const sf::Sprite& Entity::image() const {
    return m_image;
}
const int Entity::radius() const {
  return m_radius;
}

void Entity::setPosition(double x, double y) {
    m_position.setBoth(x, y);
}
void Entity::setPosition(const Vector2f& position) {
    m_position.setBoth(position.x(), position.y());
}

void Entity::update() {

}
void Entity::render(sf::RenderWindow& window) {
    window.draw(m_image);
}
bool Entity::colisionEntity(const Entity& entity){
  float distance = abs(sqrt(((entity.center().x() - m_position.x()) * (entity.center().x() - m_position.x())) + ((entity.center().y() - m_position.y()) * (entity.center().y() - m_position.y()))));
  return (distance <= entity.radius() + m_radius)? true : false;
}
