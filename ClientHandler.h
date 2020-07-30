//
// Created by herold55 on 1/1/19.
//

#ifndef PROJ2_CLIENTHANDLER_H
#define PROJ2_CLIENTHANDLER_H

#include <istream>
using namespace std;
class ClientHandler {
public:
    virtual void handleClient(int sockID) = 0;
};
#endif //PROJ2_CLIENTHANDLER_H
