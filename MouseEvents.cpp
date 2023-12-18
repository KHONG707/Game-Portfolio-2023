//
// Created by Kristal Hong on 4/24/23.
//

#ifndef PORTFOLIO_MOUSEEVENTS_CPP
#define PORTFOLIO_MOUSEEVENTS_CPP

#include "MouseEvents.h"

template<typename T>
bool MouseEvents::isHovered(T &object, sf::RenderWindow &window) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return object.getGlobalBounds().contains(mpos);
}

template<typename T>
bool MouseEvents::isClicked(T &object, sf::RenderWindow &window) {
    return (isHovered(object, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left));
}

#endif