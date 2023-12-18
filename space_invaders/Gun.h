//
// Created by Kristal Hong on 4/20/23.
//

#ifndef FINALPROJECT_GAME_GUN_H
#define FINALPROJECT_GAME_GUN_H
#include "Bullet.h"
#include "Component.h"
#include "Images.h"
#include <vector>
#include <iostream>
#include "ManageEnemies.h"
#include "Font.h"



class Gun : public SPACE::Component
{
private:
    float speed;
    std::vector<Bullet> bullets;
    sf::Sprite gun;
    bool fireMode = false;
    int numBullets = 3;
    sf::Vector2u windowSize;
    std::vector<Bullet>::iterator iter;
    void positionNextBullet();

    sf::Clock clock;
    int fireRate = 1000;


    sf::Keyboard::Key leftKey = sf::Keyboard::Left, rightKey = sf::Keyboard::Right;

    bool loseGame = false;
    bool winGame = false;

    sf::Text playerLives;
    int player_lifeSize = 3;
    sf::Text gameOverText;
    sf::Text gameWinText;

public:
    Gun();
    Gun(int numBullets, sf::Vector2u windowSize);

    void update();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void reload();
    void setPosition(sf::Vector2f position);


    float get_y() const;
    float get_x() const;

    void setTime(int time);
    int getTime() const;

    int getPlayerLife();

    bool gameOver();
    bool gameWin();


    void setLeftKey(const sf::Keyboard::Key &leftKey);
    void setRightKey(const sf::Keyboard::Key &rightKey);

    float getSpeed() const;
    void setSpeed(float speed);


    void hit(ManageEnemies& enemies);
    bool isHit(ManageEnemies& enemies);
    sf::Rect<float> getGlobalBounds();

    void reset();

};

#endif //FINALPROJECT_GAME_GUN_H
