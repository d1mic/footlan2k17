#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vector2.h"


class Entity
{
public:
    Entity(double x, double y, const sf::Texture& texture);
    Entity(const Vector2f& position, const sf::Texture& texture);

    // geteri
    const Vector2f& position() const;
    const Vector2f& center() const;
    const sf::Sprite& image() const;
    const int radius() const;

    // seteri
    void setPosition(double x, double y);
    void setPosition(const Vector2f& position);

    void update();
    void render(sf::RenderWindow& window);
private:
    Vector2f m_position; // Mozda staviti Vector2f
    Vector2f m_center;
    sf::Sprite m_image;
    int m_radius = 0;

};

#endif
