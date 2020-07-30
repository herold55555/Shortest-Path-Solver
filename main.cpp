//
// Created by herold55 on 1/9/19.
//
#include <iostream>
#include "MyParallelServer.h"
#include "FileCacheManager.h"
#include "MyClientHandler.h"

int main(int argc, char* argv[]) {
        ClientHandler *testClientHandler = new MyClientHandler();
        MyParallelServer server;
        server.open(stoi(argv[1]), testClientHandler);
        server.stop();
        delete(testClientHandler);
        return 0;
}