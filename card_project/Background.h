//
// Created by Kristal Hong on 2/14/23.
//

#ifndef SFML_CARDPROJECT_BACKGROUND_H
#define SFML_CARDPROJECT_BACKGROUND_H
#include <SFML/Graphics.hpp>


class Background : public sf::RectangleShape
{
public:
    Background();

};






//class Rank : public sf::Drawable
//{
//public:
//    Rank();
//    Rank(Ranks rank);
//    void setText(const std::string& text); //write this - the rank - switch case
//    void setTopPosition(float x, float y); //write this
//    void setBottomPosition(float x, float y); //write this
//    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
//private:
//    sf::Text top, bottom;
//};

//Class background : sf::RectangleShape
#endif //SFML_CARDPROJECT_BACKGROUND_H
