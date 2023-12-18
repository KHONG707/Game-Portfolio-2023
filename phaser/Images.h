//
// Created by Kristal Hong on 4/10/23.
//

#ifndef SFML_TUTORIAL_IMAGES_H
#define SFML_TUTORIAL_IMAGES_H
#include <map>
#include <SFML/Graphics.hpp>
namespace PHASER {
    enum images {
        PHASER
    };
}

class Images {
private:
    static std::map<PHASER::images, sf::Texture> textures;
    static std::string getPath(PHASER::images image);
    static void load(PHASER::images image);

public:
    static sf::Texture& getImage(PHASER::images image);
};


#endif //SFML_TUTORIAL_IMAGES_H
