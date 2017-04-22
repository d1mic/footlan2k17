#ifndef STATE_H_
#define STATE_H_

#include <SFML/Graphics.hpp>
#include "ResourceManager.h"

class State
{
public:
    State(TextureManager* textures, FontManager* fonts);
    virtual ~State();

    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
private:
    TextureManager* m_textures;
    FontManager* m_fonts;
};

#endif
