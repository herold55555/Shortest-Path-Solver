//
// Created by herold55 on 1/1/19.
//

#ifndef PROJ2_MYPARALLELSERVER_H
#define PROJ2_MYPARALLELSERVER_H
#include "server_side.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <thread>
#include <unistd.h>
#include <condition_variable>
#include <chrono>
#include <vector>

using namespace server_side;
class MyParallelServer : public Server {
    vector<thread*> vectOfThread;
    int socketServer;
    bool secondConnection;
public :
    MyParallelServer() {
    this->secondConnection = false;
}
    void open(int port, ClientHandler* c);
    void stop();
    void start(int socketID, ClientHandler* clientHandler);
    static void openNewThread(int clientSocket, ClientHandler* clientHandler);
    static int createSocket(int port);
    static int connection(int sockfd, bool secondConnection);
    static void closeSock(int sockfd);
    ~MyParallelServer() {
        for(int i = 0; i < vectOfThread.size(); i++) {
            delete(vectOfThread.at(i));
        }
    }
};
#endif //PROJ2_MYPARALLELSERVER_H
