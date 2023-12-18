//
// Created by Kristal Hong on 4/11/23.
//

#include "States.h"


States::States() {
    for (int i = 0; i < LAST_STATE; ++i) {
        states[(stateEnum)i] = false;
    }
}


void States::enableState(stateEnum state) {
    states[state] = true;
}

void States::disableState(stateEnum state) {
    states[state] = false;
}

void States::toggleState(stateEnum state) {
    states[state] = !states[state];
}

bool States::checkState(stateEnum state) {
    return states[state];
}
