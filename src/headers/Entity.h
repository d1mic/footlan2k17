#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics.hpp>
#include <iostream>


class Entity
{
public:
    Entity(double x, double y, const sf::Texture& texture,double x_, double y_);
    Entity(const sf::Vector2f& position, const sf::Texture& texture);

    // geteri
    const sf::Vector2f& position() const;
    const sf::Vector2f& direction() const;
    const sf::Vector2f& center() const;
    const sf::Sprite& image() const;
    const int radius() const;

    // seteri
    void setPosition(double x, double y);
    void setPosition(const sf::Vector2f& position);
    void setDirection(double x , double y);
    void setDirection(const sf::Vector2f& direction);
    void setCenter(double x, double y);

    void update(Entity& other);
    void render(sf::RenderWindow& window);

    bool colisionEntity(const Entity& entity);
    bool colisionField();

    void move(Entity& other);
private:
    sf::Vector2f m_position; // Mozda staviti Vector2f
    sf::Vector2f m_center;
    sf::Sprite m_image;
    // Precnik je u pitanju, za poluprecnik se deli sa 2
    int m_radius;
    sf::Vector2f m_direction;
    float distanceBetweenPoints(float x1, float y1, float x2, float y2);

};

#endif
