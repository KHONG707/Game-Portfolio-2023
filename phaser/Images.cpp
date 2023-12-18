//
// Created by Kristal Hong on 4/10/23.
//

#include "Images.h"
std::map<PHASER::images, sf::Texture> Images::textures;

std::string Images::getPath(PHASER::images image) {
    switch(image)
    {
        case PHASER::PHASER:
            return "phaser/phaser.png";
    }
    return std::string();
}

void Images::load(PHASER::images image)
{
    textures[image].loadFromFile(getPath(image));
}


sf::Texture& Images::getImage(PHASER::images image)
{
    load(image);
    return textures[image];
}