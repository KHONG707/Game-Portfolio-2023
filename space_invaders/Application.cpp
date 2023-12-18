//
// Created by Kristal Hong on 4/20/23.
//

#include "Application.h"
#include "Images.h"

void SPACE::Application::eventHandler(sf::RenderWindow &window, sf::Event event) {
    gun.eventHandler(window, event);
}

void SPACE::Application::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(background);
    window.draw(enemies);
    window.draw(gun);
}

void SPACE::Application::update(sf::RenderWindow &window, sf::Event event) {
    if (!gun.gameOver()) {
        gun.hit(enemies);
        gun.update();
        enemies.update();
    }
}

SPACE::Application::Application() : background (SPACE::Images::getImage(SPACE::BACKGROUND)), gun (10, {1024, 720})
{

    background.scale({.35,.35});

    background.setPosition(512 - background.getGlobalBounds().width/2, 360 - background.getGlobalBounds().height/2);

    gun.setPosition({460, 500});

}
