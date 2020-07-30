#ifndef PROJ2_DFS_H
#define PROJ2_DFS_H
#include "Searcher.h"
#include <iostream>
#include <queue>
#include <stack>
#include "algorithm"
using namespace std;
template<class T> class DFS : public Searcher<T> {
    vector<State<T>*> result;
    int numberOfNodesEvaluated;
public:
    Result search(Searchable<T>* searchable);
    int getNumberOfNodesEvaluated();
};

template<class T> Result DFS<T> :: search(Searchable<T>* searchable) {
    string setFather = "";
    double cost = 0;
    std::stack<State<T>*> newStack;
    std::vector<State<T>*> explored;
    State<T>* initial = searchable->getInitialState();
    State<T>* goal = searchable->getGoalState();
    State<T>* current;
    this->result.push_back(initial);
    initial->setFather("");
    if (initial->equals(goal)) {
        Result res("", initial->getCost(), 1);
        return res;
    }
    newStack.push(initial);
    explored.push_back(initial);
    while(!newStack.empty()) {
        current = newStack.top();
        newStack.pop();
        if(current->equals(goal))
            break;
        if(current->getUp() != NULL && current->getUp()->getFather() == "NOTHING") {
            current->getUp()->setFather("Down");
            newStack.push(current->getUp());
        }
        if(current->getDown() != NULL && current->getDown()->getFather() == "NOTHING") {
            current->getDown()->setFather("Up");
            newStack.push(current->getDown());
        }
        if(current->getLeft() != NULL && current->getLeft()->getFather() == "NOTHING") {
            current->getLeft()->setFather("Right");
            newStack.push(current->getLeft());
        }
        if(current->getRight() != NULL && current->getRight()->getFather() == "NOTHING") {
            current->getRight()->setFather("Left");
            newStack.push(current->getRight());
        }
        this->numberOfNodesEvaluated++;
    }
    if(!current->equals(goal)) {
        Result res("NO PATH", -1, -1);
        return res;
    }
    bool initialState = false;
    vector<string> path;
    cost += current->getCost();
    while(!initialState) {
        if(current == initial) {
            cost += current->getCost();
            initialState = true;
        }
        if(current->getFather() == "Up") {
            current = current->getUp();
            path.push_back("Down,");
            cost += current->getCost();
        }
        else if(current->getFather() == "Down") {
            current = current->getDown();
            path.push_back("Up,");
            cost += current->getCost();
        }
        else if(current->getFather() == "Right") {
            current = current->getRight();
            path.push_back("Left,");
            cost += current->getCost();
        }
        else if(current->getFather() == "Left") {
            current = current->getLeft();
            path.push_back("Right,");
            cost += current->getCost();
        }
    }
    string solution = "";
    for (int i = path.size() - 1; i >= 0; i--) {
        solution += path.at(i);
    }
    solution = solution.substr(0, solution.size() - 1);
    Result res(solution, cost, this->getNumberOfNodesEvaluated());
    return res;
}

template<class T> int DFS<T> :: getNumberOfNodesEvaluated() {
    return this->numberOfNodesEvaluated;
}
#endif //PROJ2_DFS_H
