//
// Created by herold55 on 1/16/19.
//

#ifndef PROJ2_COMPARE_H
#define PROJ2_COMPARE_H

#include "State.h"

template <class T>
class Compare
{
public:
    bool operator() (State<T> *state1, State<T> *state2)
    {
        return state1->getCost() > state2->getCost();
    }
};
#endif //PROJ2_COMPARE_H
