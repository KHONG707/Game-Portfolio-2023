//
// Created by Kristal Hong on 4/18/23.
//

#ifndef FINALPROJECT_GAME_COMPONENT_H
#define FINALPROJECT_GAME_COMPONENT_H
#include <SFML/Graphics.hpp>


namespace SPACE {
    class Component : public sf::Drawable {
    public:
        virtual void eventHandler(sf::RenderWindow &window, sf::Event event) = 0;

        virtual void update() = 0;
    };
}

#endif //FINALPROJECT_GAME_COMPONENT_H
