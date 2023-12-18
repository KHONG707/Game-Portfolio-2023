//
// Created by Kristal Hong on 2/14/23.
//

#include "Background.h"
//#include "Position.h"

Background::Background()
{

    setPosition({200, 0});
    setFillColor(sf::Color::White);
    setSize(sf::Vector2f(340.0f,420.0f));
}





//template<typename T, typename S>
//void Background::rectangle(const T& rect, S& obj)
//{
//    sf::FloatRect bounds = rect.getGlobalBounds();
//    rect.setPosition
//            ({
//                     bounds.left + bounds.width/2 - obj.getGlobalBounds().width/2,
//                     bounds.top + bounds.height/2 - obj.getGlobalBounds().height/2
//             });
//}


//Background::Background() : sf::RectangleShape
//{
//    //
//}

//void Rank::draw(sf::RenderTarget& window, sf::RenderStates states) const
//{
//    window.draw(top);
//    window.draw(bottom);
//}