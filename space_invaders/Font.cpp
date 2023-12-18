//
// Created by Kristal Hong on 4/28/23.
//

#include "Font.h"
sf::Font SPACE::Font::font;

void SPACE::Font::loadFont()
{
    font.loadFromFile("space_invaders/OpenSans-Bold.ttf");
}


sf::Font& SPACE::Font::getFont()
{
    loadFont();
    return font;
}