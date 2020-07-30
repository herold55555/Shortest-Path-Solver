//
// Created by herold55 on 1/1/19.
//

#ifndef PROJ2_MYSERIALSERVER_H
#define PROJ2_MYSERIALSERVER_H
#include "server_side.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <thread>
#include <unistd.h>
#include <condition_variable>
#include <chrono>
using namespace server_side;
class MySerialServer : public Server {
    bool* stopRun;
public :
    MySerialServer() {
    this->stopRun = new bool();
    *(stopRun) = false;
}
   void open(int port, ClientHandler* c);
   void stop();
   static int createSocket(int port);
   static int connection(int sockfd);
   static void closeSock(int sockfd);
};
#endif //PROJ2_MYSERIALSERVER_H
