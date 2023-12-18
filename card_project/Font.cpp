//
// Created by Kristal Hong on 2/14/23.
//

#include "Font.h"
sf::Font CardProject::Font::font;

void CardProject::Font::loadFont()
{
    font.loadFromFile("card_project/OpenSans-Bold.ttf");
}


sf::Font& CardProject::Font::getFont()
{
    loadFont();
    return font;
}