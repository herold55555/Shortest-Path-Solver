//
// Created by herold55 on 1/14/19.
//

#ifndef PROJ2_RESULT_H
#define PROJ2_RESULT_H
#include <string>
#include <vector>
#include "State.h"
#include "Point.h"

class Result {
    std::string solution;
    double cost;
    std::vector<State<Point>*> myVector;
    double numOfStatesVisited;
public:
    Result(std::vector<State<Point>*> vect, double numStates) {
        this->myVector = vect;
        for(int i = 0; i < vect.size(); i++) {
            cost += vect.at(i)->getCost();
        }
        this->numOfStatesVisited = numStates;
    }
    Result(std::string sol, double cost, double numStates) {
        this->solution = sol;
        this->cost = cost;
        this->numOfStatesVisited = numStates;
    }
    Result(const Result &result) {
        this->cost = result.getCost();
        this->myVector = result.getVector();
        this->solution = result.getSolution();
        this->numOfStatesVisited = result.getNumOfStatesVisited();
    }
    double getCost() const;
    std::string findSolution();
    std::string getSolution() const {
        return this->solution;
    }
    void setSolution(std::string sol) {
        this->solution = sol;
    }
    double getNumOfStatesVisited() const {
        return this->numOfStatesVisited;
    }
    std::vector<State<Point>*> getVector() const {
        return this->myVector;
    }
};
#endif //PROJ2_RESULT_H
