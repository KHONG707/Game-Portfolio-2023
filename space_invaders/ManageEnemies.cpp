//
// Created by Kristal Hong on 4/24/23.
//

#include "ManageEnemies.h"


ManageEnemies::ManageEnemies()
{
    float y = 220;
    for (int i = 0; i < 4; i++) {
        float x = 200;
        for (int j = 0; j < 5; j++) {
            enemies.push_back(Enemy({x, y}, 10, {1024, 720}));

            x += 40;
        }
        y += 40;
    }
}


void ManageEnemies::update() {
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i].move();
        enemies[i].update();
    }
}


void ManageEnemies::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (int i = 0; i < enemies.size(); i++) {
            window.draw(enemies[i]);
    }
}


int ManageEnemies::size() {
    return _size;
}

Enemy &ManageEnemies::operator[](unsigned int index) {
    return enemies[index];
}


bool ManageEnemies::hit(sf::Rect<float> attacker) {

    for (int i = 0; i < enemies.size(); i++) {
        for(int j = 0; j < enemies[i].getBullets().size(); j++)
        {
//            if(Collision::PixelPerfectCollision(enemies[i].getBullets()[j], ))
            if ((enemies[i].getBullets()[j].getVisible() && (enemies[i].getBullets()[j].getGlobalBounds().intersects(attacker)) || enemies[i].getGlobalBounds().intersects(attacker))) {
                enemies[i].getBullets()[j].setVisible(false);
                return true;
            }
        }
    }
    return false;
}

bool ManageEnemies::hit(sf::Sprite& attacker) {
    for (int i = 0; i < enemies.size(); i++) {
        for(int j = 0; j < enemies[i].getBullets().size(); j++)
        {

           //sf::Image img1 = enemies[i].getBullets()[j].getTexture()->copyToImage(), img2 = attacker.getTexture()->copyToImage();
           if(Collision::PixelPerfectTest(enemies[i].getBullets()[j], attacker)){
               // if ((enemies[i].getBullets()[j].getVisible() && (enemies[i].getBullets()[j].getGlobalBounds().intersects(attacker.getGlobalBounds())) || enemies[i].getGlobalBounds().intersects(attacker))) {
                    //            std::cout << "Size: " << enemies.size();
                    enemies[i].getBullets()[j].setVisible(false);
                    std::swap(enemies[i].getBullets()[j], enemies[i].getBullets()[enemies[i].getBullets().size()-1]);
                    enemies[i].getBullets().pop_back();
                    return true;
                }
        }
    }
    return false;
}
