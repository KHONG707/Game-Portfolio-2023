//
// Created by Kristal Hong on 4/2/23.
//

#include "Font.h"
sf::Font POKER::Font::font;

void POKER::Font::loadFont()
{
    font.loadFromFile("poker_analysis/OpenSans-Bold.ttf");
}


sf::Font& POKER::Font::getFont()
{
    loadFont();
    return font;
}