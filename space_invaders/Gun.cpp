//
// Created by Kristal Hong on 4/20/23.
//

#include "Gun.h"


Gun::Gun() : Gun(3, {720, 420})
{
    std::string lifePoint = "Player lives left: " + std::to_string(player_lifeSize);
//
    playerLives.setFont(SPACE::Font::getFont());
    playerLives.setString(lifePoint);
    playerLives.setFillColor(sf::Color::White);
    playerLives.setCharacterSize(2);
}

Gun::Gun(int numBullets, sf::Vector2u windowSize)
        : numBullets(numBullets), bullets(numBullets, Bullet(SPACE::Images::getImage(SPACE::LASER), {0,-5})), windowSize(windowSize), player_lifeSize(3)
{
    reset();

}

void Gun::update() {
    std::string lifePoint = "Player lives left: " + std::to_string(player_lifeSize);
    playerLives.setString(lifePoint);


    if(player_lifeSize == 0) {
        gameOverText.setString("GAME OVER");
    }

    positionNextBullet();
    for (Bullet& b : bullets)
    {
        b.update();
        if (b.getPosition().x < 0 || b.getPosition().x >= windowSize.x || b.getPosition().y < 0 || b.getPosition().y >= windowSize.y)//// here
        {
            b.setFire(false);
        }
    }
    sf::Vector2f velocity;
    speed = 5;


    if(sf::Keyboard::isKeyPressed(leftKey)) {
        velocity.x = -speed;
        velocity.y = 0;
    } else if (sf::Keyboard::isKeyPressed(rightKey)) {
        velocity.x = speed;
        velocity.y = 0;
    }
    gun.move(velocity);


    if (clock.getElapsedTime().asMilliseconds() > fireRate) {
        iter->setFire(true);
        ++iter;
        clock.restart();
    }

    if (iter == bullets.end()) //reach end of vector, then tells iter to go back to beginning
    {
        iter = bullets.begin();
    }




}

void Gun::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Gun::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(playerLives);
    window.draw(gameOverText);
    window.draw(gun);
    for (const Bullet& b : bullets)
    {
        if (b.isFire() && b.getVisible()) {
            window.draw(b);
        }
    }
}

void Gun::reload() {
    for (int i = 0; i < numBullets - bullets.size(); i++)
    {
        bullets.push_back(Bullet());
    }
}

void Gun::positionNextBullet() {

    if (!iter->isFire())
    {
        iter->setVisible(true);
        //this shoots it diagonally
        //need iterator pointing at the gun if need to shoot more than once at a time
        //goes all the way through the vectors
        iter->setPosition({
            static_cast<float>(gun.getGlobalBounds().left + (gun.getGlobalBounds().width * .5) - bullets.back().getGlobalBounds().width/2),
            gun.getPosition().y - bullets.back().getGlobalBounds().height
                          });
    }


    ////if you only want to shoot once at a time
//    if (!bullets.back().isFire())
//    {
//        //this shoots it diagonally
//        //need iterator pointing at the gun if need to shoot more than once at a time
//            //goes all the way through the vectors
//        bullets.back().setPosition({
//            gun.getPosition().x,
//            gun.getPosition().y - bullets.back().getRadius()
//        });
//    }
}


void Gun::setPosition(sf::Vector2f position) {
    gun.setPosition(position);
}


void Gun::setLeftKey(const sf::Keyboard::Key &leftKey) {
    Gun::leftKey = leftKey;
}

void Gun::setRightKey(const sf::Keyboard::Key &rightKey) {
    Gun::rightKey = rightKey;
}

float Gun::getSpeed() const {
    return speed;
}

void Gun::setSpeed(float speed) {
    Gun::speed = speed;
}

float Gun::get_y() const {
    return gun.getPosition().y;
}
float Gun::get_x() const {
    return gun.getPosition().x;
}



void Gun::hit(ManageEnemies& enemies) {

    for (int i = 0; i < bullets.size(); i++) {
        for(int j = 0; j < enemies.size(); j++){
            if (bullets[i].getGlobalBounds().intersects(enemies[j].getGlobalBounds()) && !enemies[j].getDead() && bullets[i].getVisible()) {
                enemies[j].setDead(true);
                bullets[i].setVisible(false);
                if (enemies.size() == 0) {
                    winGame = true;
                    gameWin();
                }
            }
            if (isHit(enemies)) {
                player_lifeSize--;
                if (player_lifeSize == 0) {
                    loseGame = true;
                    gameOver();
                }
                break;
            }
        }
    }
}

sf::Rect<float> Gun::getGlobalBounds() {
    return gun.getGlobalBounds();
}

bool Gun::isHit(ManageEnemies& enemies) {
    return enemies.hit(gun);
}


void Gun::reset() {

    gun.setTexture(SPACE::Images::getImage(SPACE::SPACESHIP));
    gun.setScale({0.05,0.05});
    iter = bullets.begin();
    //iterator - built in object that goes through vector//pointer pointing to the beginning and goes through the vector

    std::string lifePoint = "Player lives left: " + std::to_string(player_lifeSize);
    playerLives.setFont(SPACE::Font::getFont());
    playerLives.setString(lifePoint);
    playerLives.setPosition(200, 180);
    playerLives.setFillColor(sf::Color::White);
    playerLives.setCharacterSize(15);

    gameOverText.setFont(SPACE::Font::getFont());
    gameOverText.setPosition(365,300);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setCharacterSize(50);
}

int Gun::getPlayerLife() {
    return player_lifeSize;
}


bool Gun::gameOver() {
    return loseGame;
}

bool Gun::gameWin() {
    return winGame;
}




