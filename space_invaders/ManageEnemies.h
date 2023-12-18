//
// Created by Kristal Hong on 4/24/23.
//

#ifndef FINALPROJECT_GAME_MANAGEENEMIES_H
#define FINALPROJECT_GAME_MANAGEENEMIES_H
#include <iostream>
#include "Enemy.h"
#include <algorithm>
#include "Font.h"
#include "Collision.h"




class ManageEnemies : public sf::Drawable
{
public:
    ManageEnemies();

    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    Enemy& operator [] (unsigned int index);
    int size();

    bool hit(sf::Rect<float> attacker);
    bool hit (sf::Sprite& attacker);


    int _size = 20;

private:
    std::vector<Enemy> enemies;

    sf::Text gameOverText;
};

#endif //FINALPROJECT_GAME_MANAGEENEMIES_H
