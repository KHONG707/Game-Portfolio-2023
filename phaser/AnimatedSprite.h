//
// Created by Kristal Hong on 4/6/23.
//

#ifndef SFML_TUTORIAL_ANIMATEDSPRITE_H
#define SFML_TUTORIAL_ANIMATEDSPRITE_H
#include <SFML/Graphics.hpp>
#include "Component.h"
//#include "EventHandlable.h"
//#include "Updatable.h"
#include <cmath>
#include "Images.h"
//#include "../drawable_project.h"

enum directions {
    FORWARD, LEFT, RIGHT, BACK
};


class AnimatedSprite : public PHASER::Component, public sf::Sprite//, public EventHandlable, public Updatable
{
public:
    AnimatedSprite();
    AnimatedSprite(sf::Texture& texture, int rows, int columns);

    void animate();

    void setTime(int time);
    int getTime() const;

    void changeDirection(directions direction);

    void update();

    void eventHandler(sf::RenderWindow &window, sf::Event event) override;
//    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

private:
//    sf::Texture texture;
    sf::IntRect intRect;
    sf::Clock clock;
    int time = 250;
    float width, height;
    float speed;
    sf::Keyboard::Key leftKey = sf::Keyboard::Left, rightKey = sf::Keyboard::Right, downKey = sf::Keyboard::Up, forwardKey = sf::Keyboard::Down;
public:
    void setForwardKey(const sf::Keyboard::Key &forwardKey);

    void setLeftKey(const sf::Keyboard::Key &leftKey);

    void setRightKey(const sf::Keyboard::Key &rightKey);

    void setDownKey(const sf::Keyboard::Key &downKey);

    float getSpeed() const;

    void setSpeed(float speed);

    void setUp(sf::Texture& texture, int rows, int columns);

private:
    sf::Sprite sprite;


    void setUpIntRect(sf::Vector2u imageSize, int rows, int columns);
protected:
    void draw (sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //SFML_TUTORIAL_ANIMATEDSPRITE_H
