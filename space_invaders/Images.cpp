//
// Created by Kristal Hong on 4/18/23.
//

#include "Images.h"

std::map<SPACE::images, sf::Texture> SPACE::Images::texture;

std::string SPACE::Images::getPath(images image) {
    switch(image)
    {
        case BACKGROUND:
            return "space_invaders/Background.jpeg";
        case SPACESHIP:
            return "space_invaders/spaceship.png";
        case ALIEN:
            return "space_invaders/Alien.png";
        case LASER:
            return "space_invaders/laser.png";
    }
    return std::string();
}

void SPACE::Images::load(images image)
{
    texture[image].loadFromFile(getPath(image));
}


sf::Texture& SPACE::Images::getImage(images image)
{
    load(image);
    return texture[image];
}