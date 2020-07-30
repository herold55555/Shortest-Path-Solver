//
// Created by sheina on 10/01/19.
//

#ifndef PROJ2_STATE_H
#define PROJ2_STATE_H

#include <string>
#include <vector>

template <class T> class State {
    T state; // the state represented by a string
    double cost; // cost to reach this state (set by a setter)
    std::string cameFrom; // the state we came from to this state (setter)
    State<T>* up;
    State<T>* down;
    State<T>* left;
    State<T>* right;
    bool visited;
public:
    // CTOR
    State(T state, double cost) {
        this->state = state;
        this->cost = cost;
        this->up = nullptr;
        this->down = nullptr;
        this->right = nullptr;
        this->left = nullptr;
        this->visited = false;
        this->cameFrom = "NOTHING";
    }
    State(const State<T> &state2) {
        this->cost = state2.getCost();
        this->visited = state2.getVisited();
        this->state = state2.getStateData();
        this->cameFrom = state2.getFather();
        this->right = state2.getRight();
        this->left = state2.getLeft();
        this->up = state2.getUp();
        this->down = state2.getDown();
    }
    void doVisit() {
        this->visited = true;
    }
    bool getVisited() const {
        return this->visited;
    }
    // we overload Object's Equals method
    bool equals(State<T> *s) {
        return state == (s->state);
    }

    T getStateData() const {
        return state;
    }
    void setFather(std::string father) {
        this->cameFrom = father;
    }
    std::string getFather() const {
        return this->cameFrom;
    }
    void setUp(State<T>* state1) {
        this->up = state1;
    }
    void setDown(State<T>* state1) {
        this->down = state1;
    }
    void setRight(State<T>* state1) {
        this->right = state1;
    }
    void setLeft(State<T>* state1) {
        this->left = state1;
    }
    State<T>* getUp() const {
        return this->up;
    }
    State<T>* getDown() const {
        return this->down;
    }
    State<T>* getRight() const {
        return this->right;
    }
    State<T>* getLeft() const {
        return this->left;
    }
    double getCost() const {
        return this->cost;
    }
    State& operator=(State state2) {
        this->cost = state2.getCost();
        this->visited = state2.getVisited();
        this->state = state2.getStateData();
        this->cameFrom = state2.getFather();
        this->right = state2.getRight();
        this->left = state2.getLeft();
        this->up = state2.getUp();
        this->down = state2.getDown();
    }
    std::vector<State<T>*> getNeighboors() const {
        std::vector<State<T>*> vectOfNeighboors;
        if(this->getUp() != NULL)
            vectOfNeighboors.push_back(this->getUp());
        if(this->getDown() != NULL)
            vectOfNeighboors.push_back(this->getDown());
        if(this->getRight() != NULL)
            vectOfNeighboors.push_back(this->getRight());
        if(this->getLeft() != NULL)
            vectOfNeighboors.push_back(this->getLeft());
        return vectOfNeighboors;
    }
};

#endif //PROJ2_STATE_H