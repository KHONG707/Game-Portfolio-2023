//
// Created by Kristal Hong on 4/28/23.
//

#ifndef FINALPROJECT_GAME_FONT_H
#define FINALPROJECT_GAME_FONT_H
#include <SFML/Graphics.hpp>

namespace SPACE {
    class Font {
    public:
        static sf::Font &getFont();

    private:
        static sf::Font font;

        static void loadFont();
    };
}

#endif //FINALPROJECT_GAME_FONT_H
