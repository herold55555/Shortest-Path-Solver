//
// Created by herold55 on 1/1/19.
//

#include "StringReverser.h"
 string StringReverser::solve(string problem) {
     int n = problem.length();
     string temp = problem;
     for (int i = 0; i < n / 2; i++)
         swap(temp[i], temp[n - i - 1]);
     return temp;
 }