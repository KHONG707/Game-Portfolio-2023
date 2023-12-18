//
// Created by Kristal Hong on 4/11/23.
//

#ifndef SFML_TUTORIAL_STATES_H
#define SFML_TUTORIAL_STATES_H
#include <map>

enum stateEnum {
    MOVING, LAST_STATE
};


class States
{
private:
    std::map<stateEnum, bool> states;
public:
    States();
    void enableState(stateEnum state);
    void disableState(stateEnum state);

    void toggleState(stateEnum state);//don't know state - will simply turn on and off state

    bool checkState(stateEnum state);

};


#endif //SFML_TUTORIAL_STATES_H
