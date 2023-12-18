//
// Created by Kristal Hong on 2/14/23.
//

#ifndef SFML_CARDPROJECT_IMAGES_H
#define SFML_CARDPROJECT_IMAGES_H
#include <vector>
#include <string>
#include "Suits.h"
#include <SFML/Graphics.hpp>

class Images {
public:
    static sf::Texture& getImage(CARDPROJECT::Suits suit);
private:
    static std::vector<sf::Texture> images;
    static std::string getPath(CARDPROJECT::Suits suit);
    static void loadFile(CARDPROJECT::Suits suit);
};


#endif //SFML_CARDPROJECT_IMAGES_H
