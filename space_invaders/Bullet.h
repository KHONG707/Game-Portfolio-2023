//
// Created by Kristal Hong on 4/20/23.
//

#ifndef FINALPROJECT_GAME_BULLET_H
#define FINALPROJECT_GAME_BULLET_H
#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite
{
private:
    sf::Vector2f velocity;
public:
    const sf::Vector2f &getVelocity() const;

    void setVelocity(const sf::Vector2f &velocity);

    bool isFire() const;

    void setFire(bool fire);

    void setVisible(bool visible);
    bool getVisible() const;


private:
    bool fire = false;

    bool visible = true;

    sf::IntRect intRect;
    void setUp (sf::Texture& texture);
    void setUpIntRect(sf::Vector2u textureSize);

    float width, height;

public:
    Bullet();
    Bullet(sf::Texture& texture, sf::Vector2f velocity);

    Bullet (sf::Texture& texture);


    void update(); // while bullet been fired, make bullet move

};

#endif //FINALPROJECT_GAME_BULLET_H
