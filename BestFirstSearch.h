//
// Created by adi on 08/01/19.
//

#ifndef PROJECT2_BESTFIRSTSEARCH_H
#define PROJECT2_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include <queue>
#include "Compare.h"



template <class T>
class BestFirstSearch : public Searcher<T>{
    int numberOfNodesEvaluated;
public:
    Result search(Searchable<T> *searchable);
};
template <class T> Result BestFirstSearch<T> ::search(Searchable<T> *searchable) {
    State<T>* goal, *initial, *current;
    double cost;
    goal = searchable->getGoalState();
    initial = searchable->getInitialState();
    std::priority_queue<State<T>*, std::vector<State<T>*>, Compare<T>> priorityQueue;
    initial->setFather("THIS IS THE START");
    priorityQueue.push(initial);
    while (!priorityQueue.empty())
    {
        current = priorityQueue.top();
        priorityQueue.pop();
        if (current->equals(goal))
        {
            break;
        }
        if (current->getUp() != NULL && current->getUp()->getFather() == "NOTHING") {
            current->getUp()->setFather("Down");
            priorityQueue.push(current->getUp());
        }
        if (current->getDown() != NULL && current->getDown()->getFather() == "NOTHING") {
            current->getDown()->setFather("Up");
            priorityQueue.push(current->getDown());
        }
        if (current->getLeft() != NULL && current->getLeft()->getFather() == "NOTHING") {
            current->getLeft()->setFather("Right");
            priorityQueue.push(current->getLeft());
        }
        if (current->getRight() != NULL && current->getRight()->getFather() == "NOTHING") {
            current->getRight()->setFather("Left");
            priorityQueue.push(current->getRight());

        }
        this->numberOfNodesEvaluated++;
    }

    if (!current->equals(goal)){
        Result res("NO PATH", -1, -1);
        return res;
    }

    bool initialState = false;
    std::vector<std::string> path;
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
    std::string solution = "";
    for (int i = path.size() - 1; i >= 0; i--) {
        solution += path.at(i);
    }
    solution = solution.substr(0, solution.size() - 1);
    Result res(solution, cost, this->numberOfNodesEvaluated);
    return res;
}
#endif //PROJECT2_BESTFIRSTSEARCH_H