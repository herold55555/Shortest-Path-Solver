//
// Created by herold55 on 1/14/19.
//
#include "Result.h"

double Result ::getCost() const {
    double finalCost = 0;
    for(int i = 0; i < myVector.size(); i++) {
        finalCost += myVector.at(i)->getCost();
    }
    return cost;
}

std::string Result ::findSolution() {
    std::vector<std::string> solutionVect;
    std::string sol = "";
    std::string realSolution = "";
    for(int i = 0; i < myVector.size(); i++) {
        if (myVector.at(i)->getFather() == "DOWN") {
            sol = "Up,";
            solutionVect.push_back(sol);
        }
        else if (myVector.at(i)->getFather() == "UP") {
            sol = "Down,";
            solutionVect.push_back(sol);
        }
        else if (myVector.at(i)->getFather() == "RIGHT") {
            sol = "Left,";
            solutionVect.push_back(sol);
        }
        else if (myVector.at(i)->getFather() == "LEFT") {
            sol = "Right,";
            solutionVect.push_back(sol);
        }
        else {
            continue;
        }
    }
    for(int i = 1; i < solutionVect.size(); i++) {
        realSolution += solutionVect.at(i);
    }
    realSolution = realSolution.substr(0, realSolution.size() - 1);
    return realSolution;
}
