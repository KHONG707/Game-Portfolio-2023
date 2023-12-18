//
// Created by Kristal Hong on 3/29/23.
//

#ifndef SFML_TUTORIAL_COMPONENT_H
#define SFML_TUTORIAL_COMPONENT_H
#include <SFML/Graphics.hpp>
#include "MouseEvents.h"
#include "States.h"
namespace PHASER {
    class Component : public States {
    public:
        virtual void eventHandler(sf::RenderWindow &window, sf::Event event) = 0;

        virtual void update() = 0;
    };
}

#endif //SFML_TUTORIAL_COMPONENT_H
