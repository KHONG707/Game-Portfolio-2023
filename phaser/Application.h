//
// Created by Kristal Hong on 3/29/23.
//

#ifndef SFML_TUTORIAL_APPLICATION_H
#define SFML_TUTORIAL_APPLICATION_H
#include <SFML/Graphics.hpp>
#include "Component.h"
#include <vector>
#include "../drawable_project.h"
#include "AnimatedSprite.h"
#include "Images.h"

class Application_phaser : public DrawableProject
{
public:
    Application_phaser();
    static void run();
    static void addComponent(PHASER::Component& component);

    void eventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void update(sf::RenderWindow &window, sf::Event event);

private:
    static sf::RenderWindow window;
    //no need to make object, only use it once
    //belongs to class not object
    AnimatedSprite phaser;
    static std::vector<PHASER::Component*> components;

};


#endif //SFML_TUTORIAL_APPLICATION_H
