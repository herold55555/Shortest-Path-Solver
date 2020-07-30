
//
// Created by sheina on 10/01/19.
//

#ifndef PROJ2_MYCLIENTHANDLER_H
#define PROJ2_MYCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "Searchable.h"
#include "SearcherSolver.h"
#include "FileCacheManager.h"
#include <strings.h>
#include <unistd.h>
#include <sys/socket.h>
#include <vector>
#include <sstream>
#include <cstring>
#include "Matrix.h"
#include "Point.h"


class MyClientHandler : public ClientHandler{
    Solver<Searchable<Point>*, Result>* solver;
    CacheManager<string, string>* cacheManager;
    vector<State<Point>*> deleteVect;
public:
    MyClientHandler() {
        this->cacheManager = new FileCacheManager<string, string>();
    }
    void handleClient(int socketID);
    void set(string sol, int socketID);
    ~MyClientHandler() {
        delete (this->cacheManager);
        delete (this->solver);
        for(int i = 0; i < deleteVect.size(); i++) {
            delete(deleteVect.at(i));
        }
    }
};
vector<string> split(string line, char c);
#endif //PROJ2_MYCLIENTHANDLER_H
