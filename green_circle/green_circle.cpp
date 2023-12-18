//
// Created by Kristal Hong on 4/20/23.
//

#include "green_circle.h"

GreenCircle::GreenCircle(): shape(200.f) {
    shape.setFillColor(sf::Color(100, 250, 50));
    shape.setPosition(292,90);
}

void GreenCircle::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(shape);
}
