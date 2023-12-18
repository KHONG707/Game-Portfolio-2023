//
// Created by Kristal Hong on 3/29/23.
//

#ifndef POKERANALYSIS_APPLICATION_H
#define POKERANALYSIS_APPLICATION_H
#include <SFML/Graphics.hpp>
#include "Component.h"
#include "../drawable_project.h"
#include <vector>
#include "CardSet.h"
#include "PokerScore.h"
#include "PokerProbability.h"

namespace POKER {
    class Application : public DrawableProject {
    public:
        Application();
        static void run();
        static void addComponent(Component &component);
        void eventHandler(sf::RenderWindow& window, sf::Event event);
        virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
        void update(sf::RenderWindow &window, sf::Event event);
    private:
        //static sf::RenderWindow window;
        //no need to make object, only use it once
        //belongs to class not object
        //static std::vector<Component *> components;
        CardSet c1, c2, c3, c4, c5, c6, c7, c8, c9 , c10;
        PokerProbability scoring;
        Deck deck;
        Card dealtCard;
        CardHand theCards;
        PokerScore pokerScore;
    };
}


#endif //POKERANALYSIS_APPLICATION_H
