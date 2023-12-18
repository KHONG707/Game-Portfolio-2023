//
// Created by Kristal Hong on 4/6/23.
//

#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
{
    AnimatedSprite phaser(Images::getImage(PHASER::PHASER), 4, 12);
    phaser.changeDirection(FORWARD);
    phaser.setTime(100);
    phaser.setSpeed(5);
}

AnimatedSprite::AnimatedSprite(sf::Texture &texture, int rows, int columns)
{
    setUp(texture, rows, columns);
    setUpIntRect(texture.getSize(), rows, columns);
//
//
//    AnimatedSprite phaser(Images::getImage(PHASER::PHASER), 4, 12);
//    phaser.changeDirection(FORWARD);
//    phaser.setTime(100);
//    phaser.setSpeed(5);
}



void AnimatedSprite::animate()
{
    if (clock.getElapsedTime().asMilliseconds() > time) {
        if (intRect.left >= width - intRect.width)
        {
            intRect.left = 0;
        } else {
            intRect.left += intRect.width;
        }
        clock.restart();
        setTextureRect(intRect);
    }

}


void AnimatedSprite::setUp(sf::Texture &texture, int rows, int columns)
{
    width = texture.getSize().x;
    height = texture.getSize().y;
    setTexture(texture);
    setUpIntRect(texture.getSize(), rows, columns);
//    sf::Vector2u imageSize = texture.getSize();
//    intRect.width = imageSize.x / columns;
//    intRect.height = imageSize.y / rows;
//    intRect.left = 0;
//    intRect.top = 0;
}

void AnimatedSprite::setUpIntRect(sf::Vector2u imageSize, int rows, int columns) {
    intRect.width = std::round(imageSize.x) / static_cast<float> (columns);
    intRect.height = imageSize.y / rows;
    intRect.left = 0;
    intRect.top = 0;

    setTextureRect(intRect);
}



int AnimatedSprite::getTime() const {
    return time;
}

void AnimatedSprite::setTime(int time) {
    AnimatedSprite::time = time;
}


void AnimatedSprite::update() {
    //animate only if moving
    if (checkState(MOVING)) {
        animate();
    }
}

void AnimatedSprite::eventHandler(sf::RenderWindow &window, sf::Event event)
{
//    float speed;
    sf::Vector2f velocity;
    if(sf::Keyboard::isKeyPressed(downKey)) {
        changeDirection(BACK);
//        speed = 0;
        velocity.x = 0;
        velocity.y = -speed;
    } else if (sf::Keyboard::isKeyPressed(leftKey)) {
        changeDirection(LEFT);
        velocity.x = -speed;
        velocity.y = 0;
    } else if (sf::Keyboard::isKeyPressed(forwardKey)) {
        changeDirection(FORWARD);
        velocity.x = 0;
        velocity.y = speed;
    } else if (sf::Keyboard::isKeyPressed(rightKey)) {
        changeDirection(RIGHT);
        velocity.x = speed;
        velocity.y = 0;
    }
    //else if space click -> toggle enable
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        toggleState(MOVING);
        while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
    }
    move(velocity);
}

void AnimatedSprite::draw (sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::Sprite s = (*this);
    target.draw(s);
}


void AnimatedSprite::changeDirection(directions direction)
{
    intRect.top = direction * intRect.height;
}

float AnimatedSprite::getSpeed() const {
    return speed;
}

void AnimatedSprite::setSpeed(float speed) {
    AnimatedSprite::speed = speed;
}




void AnimatedSprite::setForwardKey(const sf::Keyboard::Key &forwardKey) {
    AnimatedSprite::forwardKey = forwardKey;
}

void AnimatedSprite::setLeftKey(const sf::Keyboard::Key &leftKey) {
    AnimatedSprite::leftKey = leftKey;
}

void AnimatedSprite::setRightKey(const sf::Keyboard::Key &rightKey) {
    AnimatedSprite::rightKey = rightKey;
}

void AnimatedSprite::setDownKey(const sf::Keyboard::Key &downKey) {
    AnimatedSprite::downKey = downKey;
}
