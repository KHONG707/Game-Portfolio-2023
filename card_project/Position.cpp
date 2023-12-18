//
// Created by Kristal Hong on 2/15/23.
//

#ifndef SFML_CARDPROJECT_POSITION_CPP
#define SFML_CARDPROJECT_POSITION_CPP
#include "Position.h"

template<typename T, typename S>
void Position::center(const T& constObj, S& obj)
{
    sf::FloatRect bounds = constObj.getGlobalBounds();
    obj.setPosition
    ({
        bounds.left + bounds.width/2 - obj.getGlobalBounds().width/2,
        bounds.top + bounds.height/2 - obj.getGlobalBounds().height/2
    });
}
#endif
