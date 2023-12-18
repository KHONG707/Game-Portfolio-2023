//
// Created by Kristal Hong on 2/14/23.
//

#ifndef SFML_CARDPROJECT_CARD_H
#define SFML_CARDPROJECT_CARD_H
#include "Background.h"
#include "Rank.h"
#include "Suit.h"
#include "../drawable_project.h"

namespace CardProject {
    class Card : public DrawableProject {
    public:
        Card();

        Card(CARDPROJECT::Ranks rank, CARDPROJECT::Suits suit);

        virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;

        //const at the end of functions - you cannot make any changes to the member variables/objects
        //const at beginning - you cannot modify it, you cannot modify the parameters
        void position();

        void eventHandler(sf::RenderWindow &window, sf::Event event) {};
        void update(sf::RenderWindow &window, sf::Event event);
    private:
        Background background;
        Rank rank;
        Suit suit;
    };
}

#endif //SFML_CARDPROJECT_CARD_H
