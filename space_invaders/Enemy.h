//
// Created by Kristal Hong on 4/24/23.
//

#ifndef FINALPROJECT_GAME_ENEMY_H
#define FINALPROJECT_GAME_ENEMY_H
#include <SFML/Graphics.hpp>
#include "Bullet.h"


class Enemy : public sf::Drawable
{
public:
    Enemy();
    Enemy(sf::Vector2f position, int numBullets, sf::Vector2u windowSize);

	float get_x() const;
    float get_y() const;

	void move();

	void update();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const override;

    void setPosition(sf::Vector2f position);

    void reload();

    sf::Rect<float> getGlobalBounds();

    std::vector<Bullet>& getBullets();


    void erase();

    void setDead(bool dead);
    bool getDead();

private:
    int x, y;
    sf::Vector2f velocity = {2, 0};


    sf::Vector2f position;

    bool dead = false;

    sf::Sprite enemy;
    sf::Clock clock;
    int fireRate = 1000;

    std::vector<Bullet>::iterator iter;
    void positionNextBullet();

    std::vector<Bullet> bullets;

    bool fireMode = false;
    int numBullets = 10;
    sf::Vector2u windowSize;
};

#endif //FINALPROJECT_GAME_ENEMY_H
