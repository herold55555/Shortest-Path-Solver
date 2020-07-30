//
// Created by sheina on 1/1/19.
//

#ifndef PROJ2_CACHEMANAGER_H
#define PROJ2_CACHEMANAGER_H
#include <string>
#include <vector>

using namespace std;

template <class Problem, class Solution> class CacheManager {
public:
    virtual bool checkProblemExist(Problem problem) = 0;
    virtual Solution getSolution(Problem problem) = 0;
    virtual void saveSolution(Problem problem, Solution solution) = 0;
};
#endif //PROJ2_CACHEMANAGER_H