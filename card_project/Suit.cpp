//
// Created by Kristal Hong on 2/14/23.
//

#include "Suit.h"
#include "Images.h"

Suit::Suit()
{

}

Suit::Suit(CARDPROJECT::Suits suit)
{
    setTexture(Images::getImage(suit));
}

