//
// Created by herold55 on 1/1/19.
//

#ifndef PROJ2_SERVER_SIDE_H
#define PROJ2_SERVER_SIDE_H
#include "ClientHandler.h"
namespace server_side {
    class Server {
    public :
        virtual void open(int port, ClientHandler* c) = 0;
        virtual void stop() = 0;
        // maybe more functions
    };
}
#endif //PROJ2_SERVER_SIDE_H
