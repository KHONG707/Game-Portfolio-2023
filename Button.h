//
// Created by Kristal Hong on 4/24/23.
//

#ifndef PORTFOLIO_BUTTON_H
#define PORTFOLIO_BUTTON_H
#include "MouseEvents.h"
#include <iostream>

class Button : public MouseEvents, public sf::Drawable {
private:
    sf::RectangleShape box;
    sf::Text label;
public:
    Button();
    Button (std::string text, int width, int height, sf::Vector2f position);

    sf::Text& getLabel();
    sf::RectangleShape& getBox();

    sf::Rect<float> getGlobalBounds();
    void setPosition(sf::Vector2f pos);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
};


#endif //PORTFOLIO_BUTTON_H
