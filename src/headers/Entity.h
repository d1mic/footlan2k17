#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics.hpp>
#include "Vector2.h"

class Entity
{
public:
    Entity(double x, double y, const sf::Texture& texture);
    Entity(const Vector2d& position, const sf::Texture& texture);

    // geteri
    const Vector2d& position() const;
    const sf::Sprite& image() const;

    // seteri
    void setPosition(double x, double y);
    void setPosition(const Vector2d& position);

    void update();
    void render(sf::RenderWindow& window);
private:
    Vector2d m_position; // Mozda staviti Vector2f
    sf::Sprite m_image;
};

#endif