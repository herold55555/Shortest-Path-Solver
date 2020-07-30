//
// Created by herold55 on 1/1/19.
//

#ifndef PROJ2_SOLVER_H
#define PROJ2_SOLVER_H
#include <string>
using namespace std;

template <class Problem, class Solution> class Solver {
public :
    virtual Solution solve(Problem problem) = 0;
};
#endif //PROJ2_SOLVER_H
