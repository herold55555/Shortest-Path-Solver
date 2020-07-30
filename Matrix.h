//
// Created by herold55 on 1/10/19.
//

#ifndef PROJ2_MATRIX_H
#define PROJ2_MATRIX_H
#include <vector>
#include <list>
#include "Searchable.h"
#include "Point.h"

using namespace std;
class Matrix : public Searchable<Point> {
    vector<vector<State<Point>*>> matrix;
    vector<State<Point>*> vectorOfStates;
    State<Point>* initial;
    State<Point>* goal;
public:
    Matrix(vector<vector<State<Point>*>> matrixS, State<Point>* start, State<Point>* goalState) {
        this->matrix = matrixS;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix.at(i).size(); j++) {
                this->vectorOfStates.push_back(matrix.at(i).at(j));
            }
        }
        for(int i = 0; i < vectorOfStates.size(); i++) {
            if(vectorOfStates.at(i)->getCost() == -1)
                continue;
            for(int j = 0; j < vectorOfStates.size(); j++) {
                if (vectorOfStates.at(j)->getStateData().getX() == vectorOfStates.at(i)->getStateData().getX()
                    && vectorOfStates.at(j)->getStateData().getY() + 1 == vectorOfStates.at(i)->getStateData().getY()) {
                    if (vectorOfStates.at(i)->getCost() != -1 && vectorOfStates.at(j)->getCost() != -1)
                        vectorOfStates.at(i)->setLeft(vectorOfStates.at(j));
                }
                else  if (vectorOfStates.at(j)->getStateData().getX() == vectorOfStates.at(i)->getStateData().getX()
                          && vectorOfStates.at(j)->getStateData().getY() - 1 == vectorOfStates.at(i)->getStateData().getY()) {
                    if (vectorOfStates.at(i)->getCost() != -1 && vectorOfStates.at(j)->getCost() != -1)
                        vectorOfStates.at(i)->setRight(vectorOfStates.at(j));
                }
                else  if (vectorOfStates.at(j)->getStateData().getX() + 1 == vectorOfStates.at(i)->getStateData().getX()
                          && vectorOfStates.at(j)->getStateData().getY() == vectorOfStates.at(i)->getStateData().getY()) {
                    if (vectorOfStates.at(i)->getCost() != -1 && vectorOfStates.at(j)->getCost() != -1)
                        vectorOfStates.at(i)->setUp(vectorOfStates.at(j));
                }
                else  if (vectorOfStates.at(j)->getStateData().getX() - 1 == vectorOfStates.at(i)->getStateData().getX()
                          && vectorOfStates.at(j)->getStateData().getY() == vectorOfStates.at(i)->getStateData().getY()) {
                    if (vectorOfStates.at(i)->getCost() != -1 && vectorOfStates.at(j)->getCost() != -1)
                        vectorOfStates.at(i)->setDown(vectorOfStates.at(j));
                }
            }
        }
        for(int i = 0; i < vectorOfStates.size(); i++) {
            if(start->equals(vectorOfStates.at(i))) {
                this->initial = vectorOfStates.at(i);
                break;
            }
        }
        for(int i = 0; i < vectorOfStates.size(); i++) {
            if(goalState->equals(vectorOfStates.at(i))) {
                this->goal = vectorOfStates.at(i);
                break;
            }
        }
    }
    State<Point>* getInitialState();
    State<Point>* getGoalState();
    vector<State<Point>*> getAllPossibleStates(State<Point>* s);
};
#endif //PROJ2_MATRIX_H
