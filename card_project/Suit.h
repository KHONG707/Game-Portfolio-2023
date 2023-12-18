//
// Created by Kristal Hong on 2/14/23.
//

#ifndef SFML_CARDPROJECT_SUIT_H
#define SFML_CARDPROJECT_SUIT_H
#include <SFML/Graphics.hpp>
#include "Suits.h"


class Suit : public sf::Sprite
{
public:
    Suit();
    Suit(CARDPROJECT::Suits suit);
};


#endif //SFML_CARDPROJECT_SUIT_H
