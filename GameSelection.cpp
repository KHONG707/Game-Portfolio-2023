//
// Created by Kristal Hong on 4/24/23.
//

#include "GameSelection.h"
//GameSelection::GameSelection() {
//    //
//}


GameSelection::GameSelection()
{
    left.getLabel().setFont(Font::getFont());
    right.getLabel().setFont(Font::getFont());
    select.getLabel().setFont(Font::getFont());
    play.setFont(Font::getFont());

    left.getLabel().setString("<");
    right.getLabel().setString(">");
    select.getLabel().setString("SELECT");

    play.setPosition(418, 13);


    left.getLabel().setPosition(65,290);
    right.getLabel().setPosition(915, 290);
//    play.getLabel().setPosition(915, 270);
    select.getLabel().setPosition(441, 622);

    right.getLabel().setCharacterSize(80);
    left.getLabel().setCharacterSize(80);
    select.getLabel().setCharacterSize(35);
//    play.getLabel().setCharacterSize(25);
//    right_label.setString(">");

    sf::Vector2f size = {80,80};
    left.getBox().setSize(size);
    right.getBox().setSize(size);
    select.getBox().setSize({200,50});

    left.getBox().setPosition({50,300});
    right.getBox().setPosition({895, 300});
    select.getBox().setPosition({400, 620});

    left.getBox().setFillColor(sf::Color::Black);
    right.getBox().setFillColor(sf::Color::Black);
    select.getBox().setFillColor(sf::Color(54,69,79));

    left.getLabel().setFillColor(sf::Color::White);
    right.getLabel().setFillColor(sf::Color::White);
    select.getLabel().setFillColor(sf::Color::White);

    //load game data

    projects.push_back(&greenCircleProject);
    projects.push_back(&cardProject);

    projects.push_back(&bouncingBall);
    projects.push_back(&SFMLGrid);
    projects.push_back(&pokerAnalysis);
    projects.push_back(&phaser);
    projects.push_back(&spaceInvaders);

//    for (auto &p : projects) {
//        p->setScale({.25, .25});
//    }
}


void GameSelection::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(left);
    window.draw(right);
    window.draw(play);
    window.draw(select);
    window.draw(*projects[projectIndex]);
}

void GameSelection::update() {
    atIndexLoop();
    play.setString(labelProjects[projectIndex]);
}

void GameSelection::eventHandler(sf::RenderWindow &target, sf::Event event) {
    if (MouseEvents::isClicked(left, target))
    {
        projectIndex--;
        update();

    } else if (MouseEvents::isClicked(right, target)) {
        projectIndex++;
        update();

    } else if (MouseEvents::isClicked(select, target)) {
        sf::RenderWindow window({1024, 720, 32}, labelProjects[projectIndex]);
        window.setFramerateLimit(60);

        while(window.isOpen())
        {
            while(window.pollEvent(event))
            {
                if (sf::Event::Closed == event.type)
                    window.close();

                projects[projectIndex]->eventHandler(window, event);

            }

            projects[projectIndex]->update(window, event);
            update();
            window.clear();
            window.draw(*projects[projectIndex]);
            window.display();
        }
        update();
    }
}

void GameSelection::atIndexLoop() {
    if(projectIndex < 0) {
        projectIndex = projects.size() - 1;
    }
    if(projectIndex >= projects.size()) {
        projectIndex = 0;
    }

}

