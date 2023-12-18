//
// Created by Kristal Hong on 4/29/23.
//


#include "Font.h"
sf::Font Font::font;

void Font::loadFont()
{
    font.loadFromFile("OpenSans-Bold.ttf");
}

void Font::loadOtherCharacters() {
    font.loadFromFile("");
}


sf::Font& Font::getFont()
{
    loadFont();
    return font;
}