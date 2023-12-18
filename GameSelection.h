//
// Created by Kristal Hong on 4/24/23.
//

#ifndef PORTFOLIO_GAMESELECTION_H
#define PORTFOLIO_GAMESELECTION_H
#include "MouseEvents.h"
#include "Button.h"
#include <iostream>
#include "drawable_project.h"
#include "green_circle/green_circle.h"
#include "card_project/Card.h"
#include "bouncing_ball/bouncing_ball.h"
#include "poker_analysis/Application.h"
#include "2D_array/SFMLGrid.h"
#include "phaser/Application.h"
#include "Font.h"
#include "space_invaders/Application.h"

class GameSelection : public MouseEvents, public sf::Drawable
{
private:
    Button left, right, select;
    sf::Text play;
    int projectIndex = 0;

    std::vector<DrawableProject*> projects;
    GreenCircle greenCircleProject;
    CardProject::Card cardProject;
    BouncingBall bouncingBall;
    SFMLGrid SFMLGrid;
    POKER::Application pokerAnalysis;
    Application_phaser phaser;
    SPACE::Application spaceInvaders;

    std::string labelProjects[7] = {"Green Circle", "Playing Card", "Bouncing Ball", "The 2D Grid", "Poker Analysis", "Phaser", "Space Invaders"};

public:
    GameSelection();
    void atIndexLoop();

    void eventHandler(sf::RenderWindow &window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();


};


#endif //PORTFOLIO_GAMESELECTION_H
