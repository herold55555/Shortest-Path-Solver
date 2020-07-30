//
// Created by herold55 on 1/13/19.
//

#include "MyParallelServer.h"
void MyParallelServer :: open (int port, ClientHandler* c) {
    this->socketServer = createSocket(port);
    listen(this->socketServer,SOMAXCONN);
    start(this->socketServer, c);

}

void MyParallelServer :: stop() {
    for(vector<thread*>::iterator iterator1 = this->vectOfThread.begin(); iterator1 != this->vectOfThread.end(); iterator1++) {
        (*(iterator1))->join();
    }
    close(this->socketServer);
}

void MyParallelServer ::start(int socketID, ClientHandler *clientHandler) {
    bool is_running = true;
    int clientSock;
    bool secondConnection = false;
    while(is_running) {
        clientSock = connection(socketID, secondConnection);
        secondConnection = true;
        if(clientSock < 0) {
            if(errno == EWOULDBLOCK) {
                is_running = false;
                continue;
            }
            else {
                continue;
            }
        }
        vectOfThread.push_back(new thread(&openNewThread, clientSock, clientHandler));
    }
}

void MyParallelServer ::closeSock(int sockfd) {
    close(sockfd);
}

void MyParallelServer ::openNewThread(int clientSocket, ClientHandler *clientHandler) {
    clientHandler->handleClient(clientSocket);
    closeSock(clientSocket);
}

int MyParallelServer ::createSocket(int port) {
    int sockfd,portno;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }


    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);


    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    return sockfd;
}

int MyParallelServer ::connection(int sockfd, bool secondConnection) {
    int newsockfd, clilen;
    struct sockaddr_in cli_addr;
    clilen = sizeof(cli_addr);
    if (secondConnection) {
        struct timeval timeVal1;
        timeVal1.tv_sec = 1;
        timeVal1.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char*) &timeVal1, sizeof(struct timeval));
    }
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);
    return newsockfd;
}
