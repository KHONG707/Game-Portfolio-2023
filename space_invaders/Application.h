//
// Created by Kristal Hong on 4/20/23.
//

#ifndef FINALPROJECT_GAME_APPLICATION_H
#define FINALPROJECT_GAME_APPLICATION_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Gun.h"
#include "ManageEnemies.h"
#include "../drawable_project.h"

namespace SPACE {
    class Application : public DrawableProject
    {
    public:
        Application();

        void eventHandler(sf::RenderWindow &window, sf::Event event);

        virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;

        void update(sf::RenderWindow &window, sf::Event event);

    private:
        sf::Sprite background;
        Gun gun;
        ManageEnemies enemies;
    };
}

#endif //FINALPROJECT_GAME_APPLICATION_H
