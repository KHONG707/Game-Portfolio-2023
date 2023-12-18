//
// Created by Kristal Hong on 4/20/23.
//

#ifndef PORTFOLIO_DRAWABLE_PROJECT_H
#define PORTFOLIO_DRAWABLE_PROJECT_H
#include <SFML/Graphics.hpp>

class DrawableProject: public sf::Drawable, public sf::Transformable {
public:
    virtual void eventHandler(sf::RenderWindow &window, sf::Event event) = 0;
    virtual void update(sf::RenderWindow &window, sf::Event event) = 0;
};

#endif //PORTFOLIO_DRAWABLE_PROJECT_H
