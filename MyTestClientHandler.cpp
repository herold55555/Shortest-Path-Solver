//
// Created by sheina on 1/1/19.
//
/*
#include "MyTestClientHandler.h"

void MyTestClientHandler ::handleClient(int socketID) {
    string prob;
    do {
        char buffer[1024];
        bzero(&buffer, sizeof(buffer));
        read(socketID, &buffer, sizeof(buffer));
        string s = buffer;
        size_t pos = s.find('\n');
        prob = s.substr(0, pos);
        if (prob.empty() || prob == "end") {
            continue;
        }
        string sol;
        if (cacheManager->checkProblemExist("CManager.txt", prob)) {
            sol = cacheManager->getSolution(prob);
        } else {
            sol = solver->solve(prob);
            cacheManager->saveSolution(prob, sol);
        }
        this->set(sol, socketID);
    }
    while (prob != "end");
}

void MyTestClientHandler:: set (string sol, int socketID) {
    sol += '\n';
    const char *buffer = sol.c_str();
    if (::send(socketID, buffer, strlen(buffer), 0) < 0) {
        perror("ERROR writting to socket");
        exit(1);
    }
}
 */