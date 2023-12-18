cmake_minimum_required(VERSION 3.23)
project(FinalProject_Game)

set(CMAKE_CXX_STANDARD 14)

add_executable(FinalProject_Game main.cpp Alien.cpp Alien.h Player.cpp Player.h Images.cpp Images.h States.cpp States.h Component.h Bullet.cpp Bullet.h Gun.cpp Gun.h Application.cpp Application.h Enemy.cpp Enemy.h ManageEnemies.cpp ManageEnemies.h Font.cpp Font.h Collision.cpp Collision.h)

target_link_libraries(FinalProject_Game sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)