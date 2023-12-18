//
// Created by Kristal Hong on 3/29/23.
//

#include "Application.h"
//#include "SFMLCard.h"
#include "CardSet.h"
#include "PokerProbability.h"

//sf::RenderWindow POKER::Application::window;
//actually creating it bc it's a static private
//std::vector<Component*> POKER::Application::components;

void POKER::Application::update(sf::RenderWindow &window, sf::Event event) {

}

void POKER::Application::run()
{
//    window.create({1024, 720, 32}, "Poker Cards");
//    window.setFramerateLimit(60);
//
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//            //if there is input/event happening, exits or skips if none found
//        {
//            if (event.type == sf::Event::Closed)
//            {
//                window.close();
//            }
//        }
//
//        window.clear();
//        for(Component* c : components)
//        {
//            window.draw(*c);
//        }
//
//
//
////        PokerProbability scoring (PokerScore::s);
////        window.draw(scoring);
//        window.display();
//    }

}

void POKER::Application::addComponent(Component &component)
{
    //components.push_back(&component);
}


void POKER::Application::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void POKER::Application::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(c1);
    window.draw(c2);
    window.draw(c3);
    window.draw(c4);
    window.draw(c5);
    window.draw(c6);
    window.draw(c7);
    window.draw(c8);
    window.draw(c9);
    window.draw(c10);
    window.draw(scoring);
}

POKER::Application::Application() : c1(ROYAL_FLUSH), c2(STRAIGHT_FLUSH), c3(FOUR_OF_A_KIND),
    c4(FULL_HOUSE), c5(FLUSH), c6(STRAIGHT), c7(THREE_OF_A_KIND), c8(TWO_PAIR),
    c9(ONE_PAIR), c10(HIGH_CARD)
{
    c2.setInitPos(132, 120);
    c3.setInitPos(132, 160);
    c4.setInitPos(132,200);
    c5.setInitPos(132,240);
    c6.setInitPos(132,280);
    c7.setInitPos(132, 320);
    c8.setInitPos(132,360);
    c9.setInitPos(132,400);
    c10.setInitPos(132,440);

    bool noRoyalFlush = true;


    while(noRoyalFlush){
//        keep iterating until a royal flush is obtained
        for (int j = 0; j < 5; j++) {
            dealtCard = deck.dealCard();
            theCards.addCard(dealtCard);
        }
        theCards.sortRank();
//        std::cout << theCards << std::endl;
        pokerScore += CardHandScorer::scorePokerHand(theCards, noRoyalFlush);
        deck.resetDeck();
        //Clear hand for a new check
        theCards.resetHand();
    }


    scoring.setPokerScore(PokerScore::s);
}
