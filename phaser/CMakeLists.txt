cmake_minimum_required(VERSION 3.23)
project(SFML_Tutorial)

set(CMAKE_CXX_STANDARD 14)

add_executable(SFML_Tutorial Application.cpp Application.h Component.h Card.cpp Card.h Ranks.h Suits.h MouseEvents.cpp MouseEvents.h RowOfCards.cpp RowOfCards.h AnimatedSprite.cpp AnimatedSprite.h EventHandlable.h Updatable.h Images.cpp Images.h States.cpp States.h Bullet.cpp Bullet.h Shooter.cpp Shooter.h Gun.cpp Gun.h)

target_link_libraries(SFML_Tutorial sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
