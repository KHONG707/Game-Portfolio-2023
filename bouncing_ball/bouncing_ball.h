//
// Created by Kristal Hong on 4/27/23.
//

#ifndef PORTFOLIO_BOUNCING_BALL_H
#define PORTFOLIO_BOUNCING_BALL_H
#include "../drawable_project.h"

class BouncingBall : public DrawableProject
{
public:
    BouncingBall();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void move();
    void update();
    void eventHandler(sf::RenderWindow &window, sf::Event event) {};
    void update(sf::RenderWindow &window, sf::Event event);
private:
    sf::CircleShape shape;
    float x = 5.f, y = 5.f;
};


#endif //PORTFOLIO_BOUNCING_BALL_H
