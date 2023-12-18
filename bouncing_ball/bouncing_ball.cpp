//
// Created by Kristal Hong on 4/27/23.
//

#include "bouncing_ball.h"

BouncingBall::BouncingBall(): shape(300.f) {
    shape.setPosition(350,300);
    shape.setRadius(50);
    shape.setFillColor(sf::Color::Green);
    update();
}

void BouncingBall::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(shape);
}

void BouncingBall::update() {
    move();
}

void BouncingBall::update(sf::RenderWindow &window, sf::Event event) {
    update();
}


void BouncingBall::move() {
    if(shape.getPosition().x + shape.getRadius()*2 >= 820  || shape.getPosition().x < 200)//if ball reaches right or left
    {

        x = - x;
    }
    if(shape.getPosition().y + shape.getRadius()*2 >= 600 || shape.getPosition().y < 100)//if ball reaches top or bottom
    {

        y = - y;
    }

    shape.move (x,y);
}