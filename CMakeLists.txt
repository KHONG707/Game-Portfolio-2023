cmake_minimum_required(VERSION 3.23)
project(Portfolio)

set(CMAKE_CXX_STANDARD 14)

add_executable(Portfolio main.cpp drawable_project.h
               green_circle/green_circle.cpp green_circle/green_circle.h
               card_project/Card.cpp card_project/Background.cpp card_project/Font.cpp card_project/Images.cpp card_project/Position.cpp card_project/Rank.cpp card_project/Suit.cpp GameSelection.cpp GameSelection.h Button.cpp Button.h MouseEvents.cpp MouseEvents.h bouncing_ball/bouncing_ball.cpp bouncing_ball/bouncing_ball.h
               bouncing_ball/bouncing_ball.cpp bouncing_ball/bouncing_ball.h
                poker_analysis/Application.cpp poker_analysis/Application.h poker_analysis/Card.cpp poker_analysis/Card.h poker_analysis/CardHand.cpp poker_analysis/CardHand.h poker_analysis/CardHandScorer.cpp poker_analysis/CardHandScorer.h poker_analysis/CardSet.cpp poker_analysis/CardSet.h poker_analysis/Component.h poker_analysis/Deck.cpp poker_analysis/Deck.h poker_analysis/Font.cpp poker_analysis/Font.h poker_analysis/OpenSans-Bold.ttf poker_analysis/PlayingCardImages.png poker_analysis/PokerProbability.cpp poker_analysis/PokerProbability.h poker_analysis/PokerScore.cpp poker_analysis/PokerScore.h poker_analysis/Ranks.h poker_analysis/SFMLCard.cpp poker_analysis/SFMLCard.h poker_analysis/Suits.h
        2D_array/SFMLGrid.cpp 2D_array/SFMLGrid.h
                phaser/AnimatedSprite.cpp phaser/AnimatedSprite.h phaser/Application.cpp phaser/Application.h phaser/Component.h phaser/Images.cpp phaser/Images.h phaser/phaser.png phaser/States.cpp phaser/States.h Font.cpp Font.h
        space_invaders/Alien.png space_invaders/Application.h space_invaders/Application.cpp space_invaders/Background.jpeg space_invaders/Bullet.cpp space_invaders/Bullet.h space_invaders/Collision.cpp space_invaders/Collision.h space_invaders/Component.h space_invaders/Enemy.cpp space_invaders/Enemy.h space_invaders/Font.h space_invaders/Font.cpp space_invaders/Gun.cpp space_invaders/Gun.h space_invaders/Images.h space_invaders/Images.cpp space_invaders/laser.png space_invaders/ManageEnemies.cpp space_invaders/ManageEnemies.h space_invaders/OpenSans-Bold.ttf space_invaders/spaceship.png)
target_link_libraries(Portfolio sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)