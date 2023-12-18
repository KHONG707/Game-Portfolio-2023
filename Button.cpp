//
// Created by Kristal Hong on 4/24/23.
//

#include "Button.h"

Button::Button() {
    //
}


Button::Button(std::string text, int width, int height, sf::Vector2f position)
{
    label.setString(text);
    box.setScale(width, height);
    box.setPosition(position);
    label.setPosition(position);

    //color here
//    box.setFillColor(sf::Color::Black);
}

sf::Text &Button::getLabel() {
    return label;
}

sf::RectangleShape &Button::getBox() {
    return box;
}



void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
    window.draw(label);
}

void Button::update() {

}

void Button::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents::isClicked(box, window))
    {
        std::cout << "Button is clicked\n";
    }
}

sf::Rect<float> Button::getGlobalBounds() {
    return box.getGlobalBounds();
}

void Button::setPosition(sf::Vector2f pos) {
    box.setPosition(pos);
    label.setPosition(pos);
}
