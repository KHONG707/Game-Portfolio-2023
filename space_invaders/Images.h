//
// Created by Kristal Hong on 4/18/23.
//

#ifndef FINALPROJECT_GAME_IMAGES_H
#define FINALPROJECT_GAME_IMAGES_H
#include <map>
#include <SFML/Graphics.hpp>

namespace SPACE {
    enum images {
        SPACESHIP, ALIEN, BACKGROUND, LASER
    };

    class Images {
    private:
        static std::map<images, sf::Texture> texture;

        static std::string getPath(images image);

        static void load(images image);

    public:
        static sf::Texture &getImage(images image);

    };
}

#endif //FINALPROJECT_GAME_IMAGES_H
