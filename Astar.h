//
// Created by herold55 on 1/15/19.
//

#ifndef PROJ2_ASTAR_H
#define PROJ2_ASTAR_H

#include <map>
#include <algorithm>
#include "PriorityQueueA.h"
#include "Searcher.h"

template <class T>
class Astar : public Searcher<T> {
    int numberOfNodesEvaluated;
public:
    Astar() {
        this->numberOfNodesEvaluated = 0;
    }
    Result search(Searchable<T>* searchable);
    bool isUnBlocked(Searchable<T>* searchable, State<T>* state) {
        if (searchable->getAllPossibleStates(state).size() == 0)
            return false;
        return true;
    }
    int heuristic(State<T>* current, State<T>* destination) {
        return ((std::abs)(current->getStateData().getX() - destination->getStateData().getX())
        + (std::abs) (current->getStateData().getY() - destination->getStateData().getY()));
    }
};
template <class T> Result Astar<T> ::search(Searchable<T> *searchable) {
    std::vector<State<T>*> path;
    std::map<State<T>*, State<T>*> fatherMap;
    std::map<State<T>*, double> mapOfCost;
    vector<std::string> temp;
    std::string solution;
    PriorityQueueA<State<T>*, double> priorityQueueA;
    State<T>* initial = searchable->getInitialState();
    State<T>* goal = searchable->getGoalState();
    State<T>* current;
    double finalCost = 0;
    if(!isUnBlocked(searchable, goal) || !isUnBlocked(searchable, initial)) {
        Result res("Destination or Initial state is blocked", -1, -1);
        return res;
    }
    if (initial->equals(goal)) {
        Result res(" ", goal->getCost(), 0);
        return res;
    }
    priorityQueueA.put(initial, 0);
    fatherMap[initial] = initial;
    mapOfCost[initial] = 0;
    while(!priorityQueueA.is_empty()) {
        current = priorityQueueA.get();
        if(goal->equals(current)) {
            break;
        }
        for(State<T>* nextState : current->getNeighboors()) {
            double newCost = mapOfCost[current] + nextState->getCost();
            if(mapOfCost.find(nextState) == mapOfCost.end() || newCost < mapOfCost[nextState]) {
                mapOfCost[nextState] = newCost;
                double priority = newCost + heuristic(nextState, goal);
                priorityQueueA.put(nextState, priority);
                fatherMap[nextState] = current;
                this->numberOfNodesEvaluated++;
            }
        }
    }
    if(!goal->equals(current)) {
        Result res(" ", -1, -1);
        return res;
    }
    while(!current->equals(initial)) {
        path.push_back(current);
        current = fatherMap[current];
        finalCost += current->getCost();
    }
    path.push_back(initial);
    std::reverse(path.begin(), path.end());
    for(auto it = path.begin(); it != path.end() && it + 1 != path.end(); it++) {
        if((*(it+1))->getStateData().getY() > (*(it))->getStateData().getY()) {
            temp.push_back("Right,");
        }
        if((*(it+1))->getStateData().getY() < (*(it))->getStateData().getY()) {
            temp.push_back("Left,");
        }
        if((*(it+1))->getStateData().getX() > (*(it))->getStateData().getX()) {
            temp.push_back("Down,");
        }
        if((*(it+1))->getStateData().getX() < (*(it))->getStateData().getX()) {
            temp.push_back("Up,");
        }
    }
    for(int i = 0; i < temp.size(); i++) {
        solution += temp.at(i);
    }
    solution = solution.substr(0, solution.size() - 1);
    Result res(solution, finalCost, this->numberOfNodesEvaluated);
    return res;
}
#endif //PROJ2_ASTAR_H
