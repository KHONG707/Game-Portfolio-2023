//
// Created by Kristal Hong on 4/24/23.
//

#include "Enemy.h"
#include "Images.h"
#include "Bullet.h"

Enemy::Enemy()
{
    //
}

Enemy::Enemy(sf::Vector2f position, int numBullets, sf::Vector2u windowSize)
        : numBullets(numBullets), bullets(numBullets, Bullet(SPACE::Images::getImage(SPACE::LASER), {0,5})), windowSize(windowSize),  position(position) {

    enemy.setTexture(SPACE::Images::getImage(SPACE::ALIEN));
    enemy.setScale({0.03,0.03});
    enemy.setPosition(position);
    iter = bullets.begin();
}


float Enemy::get_x() const {
    return enemy.getPosition().x;
}

float Enemy::get_y() const {
    return enemy.getPosition().y;
}

void Enemy::move() {

    if(enemy.getPosition().x >= (840 - enemy.getGlobalBounds().width) || enemy.getPosition().x <= 195)//if alien reaches right or left
    {
        velocity.x = -velocity.x;

        enemy.move(0,10.f);
    }

    enemy.move(velocity);

}









void Enemy::positionNextBullet() {
    if (!iter->isFire()) {

        iter->setVisible(true);

        //this shoots it diagonally
        //need iterator pointing at the gun if need to shoot more than once at a time
        //goes all the way through the vectors
        iter->setPosition({
                                  enemy.getGlobalBounds().left + (enemy.getGlobalBounds().width / 2) -
                                  bullets.back().getGlobalBounds().height,
//
                                  enemy.getPosition().y + enemy.getGlobalBounds().height - bullets.back().getGlobalBounds().height
                          });
    }
}

void Enemy::reload() {
    for (int i = 0; i < numBullets - bullets.size(); i++)
    {
        bullets.push_back(Bullet());
    }
}



void Enemy::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(!dead) {
        window.draw(enemy);
        for (const Bullet& b : bullets)
        {
            if (b.isFire() && b.getVisible()) {

                window.draw(b);
            }
        }
    }

}


void Enemy::setPosition(sf::Vector2f position) {
    enemy.setPosition(position);
}

void Enemy::update() {
    positionNextBullet();
    for (Bullet &b: bullets) {
        b.update();
        if (b.getPosition().x < 0 || b.getPosition().x >= windowSize.x || b.getPosition().y < 200 ||
            b.getPosition().y >= 800) {
            b.setFire(false);
        }
    }

    int random = rand() % 30;


    if (clock.getElapsedTime().asMilliseconds() > fireRate) {
        if (random == 0) {
            for (int i = 0; i < bullets.size(); i++) {
                iter->setFire(true);
            }
            ++iter;
            clock.restart();
        }


        if (iter == bullets.end()) //reach end of vector, then tells iter to go back to beginning
        {
            iter = bullets.begin();
        }

    }
}


sf::Rect<float> Enemy::getGlobalBounds() {
    return enemy.getGlobalBounds();
}

std::vector<Bullet>& Enemy::getBullets() {
    return bullets;
}


void Enemy::setDead(bool dead) {
    this->dead = dead;
}

bool Enemy::getDead() {
    return dead;
}
