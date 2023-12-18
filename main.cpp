#include <SFML/Graphics.hpp>
#include "GameSelection.h"


int main() {

    GameSelection gs;

    sf::RenderWindow window({1024, 720, 32}, "Menu");
    window.setFramerateLimit(60);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
                window.close();

            gs.eventHandler(window, event);

        }

        window.clear();
        window.draw(gs);
        window.display();
    }


    return 0;
}
