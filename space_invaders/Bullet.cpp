//
// Created by Kristal Hong on 4/20/23.
//

#include "Bullet.h"

Bullet::Bullet()
{
    //
}

Bullet::Bullet (sf::Texture& texture) {
    setUp(texture);
    setUpIntRect(texture.getSize());
}

Bullet::Bullet(sf::Texture& texture, sf::Vector2f velocity) : velocity(velocity)
{
    setUp(texture);
    setUpIntRect(texture.getSize());
}

void Bullet::setUp (sf::Texture& texture)
{
    setScale(.08,.08);
    width = texture.getSize().x;
    height = texture.getSize().y;
    setTexture(texture);
};

void Bullet::setUpIntRect(sf::Vector2u textureSize) {
    intRect.width = textureSize.x;
    intRect.height = textureSize.y;
    intRect.left = 0;
    intRect.top = 0;
    setTextureRect(intRect);
}

void Bullet::update() {
    if (fire)
    {
        move(velocity);
    }
}



const sf::Vector2f &Bullet::getVelocity() const {
    return velocity;
}

void Bullet::setVelocity(const sf::Vector2f &velocity) {
    Bullet::velocity = velocity;
}

bool Bullet::isFire() const {
    return fire;
}

void Bullet::setFire(bool fire) {
    Bullet::fire = fire;
}


void Bullet::setVisible(bool visible) {
    this->visible = visible;
}

bool Bullet::getVisible() const {
    return visible;
}
