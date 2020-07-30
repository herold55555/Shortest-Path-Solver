
//
// Created by sheina on 1/1/19.
//
/*
#ifndef PROJ2_MYTESTCLIENTHANDLER_H
#define PROJ2_MYTESTCLIENTHANDLER_H
#include "Solver.h"
#include "CacheManager.h"
#include "ClientHandler.h"
#include "FileCacheManager.h"
#include "StringReverser.h"
#include <strings.h>
#include <unistd.h>
#include <sys/socket.h>
class MyTestClientHandler : public ClientHandler {
    Solver<string, string>* solver;
    CacheManager<string, string>* cacheManager;
public:
    MyTestClientHandler() {
//        this->cacheManager = new FileCacheManager();
        this->solver = new StringReverser();
    }
    void handleClient(int socketID);
    void set(string sol, int socketID);
};
#endif //PROJ2_MYTESTCLIENTHANDLER_H

*/