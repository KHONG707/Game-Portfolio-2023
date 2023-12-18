//
// Created by Kristal Hong on 2/14/23.
//

#include "Images.h"

std::vector<sf::Texture> Images:: images(CARDPROJECT::LAST_SUIT, sf::Texture());

std::string Images::getPath(CARDPROJECT::Suits suit)
{
    switch(suit)
    {
        case CARDPROJECT::HEARTS:
            return "card_project/heart.png";
        case CARDPROJECT::DIAMONDS:
            return "card_project/diamonds.png";
        case CARDPROJECT::CLUBS:
            return "card_project/club.png";
        case CARDPROJECT::SPADES:
            return "card_project/spades.png";
    }
}


void Images::loadFile(CARDPROJECT::Suits suit)
{
    images[suit].loadFromFile(getPath(suit));
}

sf::Texture& Images::getImage(CARDPROJECT::Suits suit)
{
    loadFile(suit);
    return images[suit];
}