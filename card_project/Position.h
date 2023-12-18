//
// Created by Kristal Hong on 2/15/23.
//

#ifndef SFML_CARDPROJECT_POSITION_H
#define SFML_CARDPROJECT_POSITION_H
#include <SFML/Graphics.hpp>

class Position {
public:
    template<typename T, typename S>
    static void center(const T& constObj, S& obj);
};

#include "Position.cpp"
#endif //SFML_CARDPROJECT_POSITION_H
