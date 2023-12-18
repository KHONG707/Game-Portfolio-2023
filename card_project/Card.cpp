//
// Created by Kristal Hong on 2/14/23.
//

#include "Card.h"
#include "Position.h"
CardProject::Card::Card () : Card(CARDPROJECT::ACE, CARDPROJECT::HEARTS)
{
}

CardProject::Card::Card(CARDPROJECT::Ranks rank, CARDPROJECT::Suits suit) : rank(rank), suit(suit)
{
    position();
}

void CardProject::Card::update(sf::RenderWindow &window, sf::Event event) {

}

void CardProject::Card::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(background);
    window.draw(rank);
    window.draw(suit);
}

void CardProject::Card::position()
{
    background.setPosition(325,100);
    sf::FloatRect bkgBounds = background.getGlobalBounds();
    rank.setTopPosition(bkgBounds.left + bkgBounds.width*.05, bkgBounds.top + bkgBounds.height * 0.05);
    rank.setBottomPosition (bkgBounds.left + bkgBounds.width - bkgBounds.width*.05, bkgBounds.top + bkgBounds.height - bkgBounds.height * 0.05);

    Position::center(background, suit);
}