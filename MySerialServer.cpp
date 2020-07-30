//
// Created by herold55 on 1/1/19.
//

#include "MySerialServer.h"


void MySerialServer :: open (int port, ClientHandler* c) {
    thread serverThread;
    int sock = createSocket(port);
    serverThread = thread([](int sock, ClientHandler* c, bool* stopR) {
        int clientSocket;
        while (!*(stopR)) {
            clientSocket = connection(sock);
            if (clientSocket < 0) {
                perror("ERRROR on accept");
                exit(1);
            }
            c->handleClient(clientSocket);
            closeSock(clientSocket);
        }
        closeSock(sock);
    }, sock, c, stopRun);
    serverThread.join();
}

void MySerialServer :: stop() {
   *stopRun = true;
}

void MySerialServer ::closeSock(int sockfd) {
    close(sockfd);
}

int MySerialServer ::createSocket(int port) {
    int sockfd,portno ,newsockfd, clilen;
    struct sockaddr_in serv_addr;
    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd,5);
    return sockfd;
}

int MySerialServer ::connection(int sockfd) {
    int newsockfd, clilen;
    struct sockaddr_in cli_addr;
    clilen = sizeof(cli_addr);
    struct timeval timeVal1;
    timeVal1.tv_sec = 60;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &timeVal1, sizeof(struct timeval));
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeVal1, sizeof(struct timeval));
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);
    if (newsockfd < 0) {
        exit(1);
    }
    return newsockfd;
}