//
// Created by Kristal Hong on 4/29/23.
//

#ifndef PORTFOLIO_FONT_H
#define PORTFOLIO_FONT_H


#include <SFML/Graphics.hpp>

class Font {
public:
    static sf::Font& getFont();

private:
    static sf::Font font;
    static void loadFont();
    static void loadOtherCharacters();
};


#endif //PORTFOLIO_FONT_H
