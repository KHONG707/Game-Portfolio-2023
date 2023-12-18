//
// Created by Kristal Hong on 3/30/23.
//

#ifndef SFML_TUTORIAL_MOUSEEVENTS_H
#define SFML_TUTORIAL_MOUSEEVENTS_H
#include <SFML/Graphics.hpp>
namespace PHASER {
    class MouseEvents {
    public:
        static bool isClicked(const sf::FloatRect &bounds, const sf::RenderWindow &window);

        static bool isHovered(const sf::FloatRect &bounds, const sf::RenderWindow &window);
    };
}

#endif //SFML_TUTORIAL_MOUSEEVENTS_H
