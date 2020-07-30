//
// Created by herold55 on 1/9/19.
//

#ifndef PROJ2_BOOT_H
#define PROJ2_BOOT_H

#include "MySerialServer.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
namespace boot {
    class Main {
    public :
        int main(int argc, char* argv[]) {
        MyTestClientHandler* testClientHandler;
        MySerialServer server;
        server.open(stoi(argv[0]), testClientHandler);
        return 0;
    }
    };
}
#endif //PROJ2_BOOT_H
