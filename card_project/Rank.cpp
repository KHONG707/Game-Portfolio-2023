//
// Created by Kristal Hong on 2/14/23.
//

#include "Rank.h"
#include "Font.h"

Rank::Rank()
{

}

Rank::Rank(CARDPROJECT::Ranks rank)
{
    top.setFont(CardProject::Font::getFont());
    top.setString(getPath(rank));
    top.setFillColor(sf::Color(255,0,0));

    bottom.setFont(CardProject::Font::getFont());
    bottom.setString(getPath(rank));
    bottom.setFillColor(sf::Color(255,0,0));
}

void Rank::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(top);
    window.draw(bottom);
}


void Rank::setText(const std::string& text)
{
    top.setString(text);
    bottom.setString(text);
}

void Rank::setTopPosition(float x, float y)
{
    top.setPosition(x, y);
}
void Rank::setBottomPosition(float x, float y)
{
    bottom.setPosition(x, y);
    bottom.rotate(180.f);
}


std::string Rank::getPath(CARDPROJECT::Ranks rank) {
    switch (rank) {
        case CARDPROJECT::ACE:
            return "A";
        case CARDPROJECT::TWO:
            return "2";
        case CARDPROJECT::THREE:
            return "3";
        case CARDPROJECT::FOUR:
            return "4";
        case CARDPROJECT::FIVE:
            return "5";
        case CARDPROJECT::SIX:
            return "6";
        case CARDPROJECT::SEVEN:
            return "7";
        case CARDPROJECT::EIGHT:
            return "8";
        case CARDPROJECT::NINE:
            return "9";
        case CARDPROJECT::TEN:
            return "10";
        case CARDPROJECT::JACK:
            return "J";
        case CARDPROJECT::QUEEN:
            return "Q";
        case CARDPROJECT::KING:
            return "K";
        case CARDPROJECT::LAST_RANK:
            return "LAST_RANK";

    }
}

//ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING,