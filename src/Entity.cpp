#include "headers/Entity.h"

Entity::Entity(double x, double y, const sf::Texture& texture)
    :m_position(x, y), m_image(texture)
{
    m_image.setPosition(x, y);
}
Entity::Entity(const Vector2f& position, const sf::Texture& texture)
    :m_position(position), m_image(texture)
{
    m_image.setPosition(position.x(), position.y());
}

const Vector2f& Entity::position() const {
    return m_position;
}
const sf::Sprite& Entity::image() const {
    return m_image;
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