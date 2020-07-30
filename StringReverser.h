//
// Created by herold55 on 1/1/19.
//

#ifndef PROJ2_STRINGREVERSER_H
#define PROJ2_STRINGREVERSER_H
#include "Solver.h"
#include "string.h"
using namespace std;
class StringReverser : public Solver<string, string> {
public:
    string solve(string problem);
};
#endif //PROJ2_STRINGREVERSER_H
