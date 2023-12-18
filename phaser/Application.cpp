//
// Created by Kristal Hong on 3/29/23.
//

#include "Application.h"

sf::RenderWindow Application_phaser::window;
//actually creating it bc it's a static private
std::vector<PHASER::Component*> Application_phaser::components;

void Application_phaser::run()
{
    window.create({1024, 720, 32}, "Tutorial");
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        //if there is input/event happening, exits or skips if none found
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            for(PHASER::Component* c : components)
                c->eventHandler(window, event);

//                reinterpret_cast<EventHandlable*>(c)->eventHandler(window, event); //reinterpret_cast - tells compiler to just trust me
        }
        for(PHASER::Component* c : components)
        {
//            reinterpret_cast<Updatable*>(c)->update();
            c->update();
        }

        window.clear();
        for(PHASER::Component* c : components)
        {
            window.draw(*reinterpret_cast<sf::Drawable*>(c));
        }

        window.display();
    }

}

void Application_phaser::addComponent(PHASER::Component &component)
{
    components.push_back(&component);
}



void Application_phaser::eventHandler(sf::RenderWindow &window, sf::Event event) {
//    for(PHASER::Component* c : components)
//        c->eventHandler(window, event);
//    for(PHASER::Component* c : components)
//        c->update();
//    run();

    phaser.eventHandler(window, event);

}

void Application_phaser::draw(sf::RenderTarget &window, sf::RenderStates states) const {
//    for(PHASER::Component* c : components)
//    {
//        window.draw(*reinterpret_cast<sf::Drawable*>(c));
//    }

//    addComponent(phaser);

    window.draw(phaser);

//    addComponent(phaser);
}

void Application_phaser::update(sf::RenderWindow &window, sf::Event event) {
    phaser.update();
}

Application_phaser::Application_phaser() {

    //AnimatedSprite phaser(Images::getImage(PHASER::PHASER), 4, 12);
    phaser.setUp(Images::getImage(PHASER::PHASER), 4, 12);
    phaser.changeDirection(FORWARD);
    phaser.setTime(100);
    phaser.setSpeed(5);
    phaser.setPosition(450,300);
//    AnimatedSprite phaser(Images::getImage(PHASER::PHASER), 4, 12);
//    phaser.changeDirection(FORWARD);
//    phaser.setTime(100);
//    phaser.setSpeed(5);
//
//    addComponent(phaser);
//    run();
}
