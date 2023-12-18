//
// Created by Kristal Hong on 4/24/23.
//

#ifndef PORTFOLIO_MOUSEEVENTS_H
#define PORTFOLIO_MOUSEEVENTS_H
#include <SFML/Graphics.hpp>

class MouseEvents {
public:
    template<typename T>
    static bool isHovered(T& object, sf::RenderWindow& window);

    template<typename T>
    static bool isClicked(T& object, sf::RenderWindow& window);
};


#include "MouseEvents.cpp"
#endif //PORTFOLIO_MOUSEEVENTS_H
