cmake_minimum_required(VERSION 3.23)
project(SFML_CardProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(SFML_CardProject Background.cpp Background.h Suit.cpp Suit.h Rank.cpp Rank.h Card.cpp Card.h Font.cpp Font.h Images.cpp Images.h Suits.h Ranks.h Position.cpp Position.h)
target_link_libraries(SFML_CardProject sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)