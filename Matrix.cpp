#include "Matrix.h"

State<Point>* Matrix ::getGoalState() {
    return this->goal;
}

State<Point>* Matrix ::getInitialState() {
    return this->initial;
}

vector<State<Point>*> Matrix :: getAllPossibleStates(State<Point>* s) {
    vector<State<Point>*> sol;
    if(s->getUp() != nullptr) {
        sol.push_back(s->getUp());
    }
    if(s->getDown() != nullptr) {
        sol.push_back(s->getDown());
    }
    if(s->getRight() != nullptr) {
        sol.push_back(s->getRight());
    }
    if(s->getLeft() != nullptr) {
        sol.push_back(s->getLeft());
    }
    return sol;
}


