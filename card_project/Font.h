//
// Created by Kristal Hong on 2/14/23.
//

#ifndef SFML_CARDPROJECT_FONT_H
#define SFML_CARDPROJECT_FONT_H
#include <SFML/Graphics.hpp>
namespace CardProject {
    class Font {
    public:
        static sf::Font &getFont();

    private:
        static sf::Font font;

        static void loadFont();
    };
}


#endif //SFML_CARDPROJECT_FONT_H

//static - belongs to class itself, can be shared
//  doesnt get created here but rather in .cpp file
//member - own set of variables