//
// Created by Kristal Hong on 4/20/23.
//

#ifndef PORTFOLIO_GREEN_CIRCLE_H
#define PORTFOLIO_GREEN_CIRCLE_H
#include "../drawable_project.h"

class GreenCircle: public DrawableProject {
public:
    GreenCircle();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow &window, sf::Event event) {};
    void update(sf::RenderWindow &window, sf::Event event){ };
private:
    sf::CircleShape shape;
};


#endif //PORTFOLIO_GREEN_CIRCLE_H
