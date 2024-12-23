//
// Created by moezgen on 12/23/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

short socket_create(void) {
    short hsocket;
    printf("Creating socket...\n");
    hsocket = socket(AF_INET, SOCK_STREAM, 0);
    return hsocket;
}

int socket_connect(int hsocket) {
    int iRetVal = -1;
    int server_port = 12345;
    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr("127.0.0.1");
    remote.sin_port = htons(server_port);
    remote.sin_family = AF_INET;
    iRetVal = connect(hsocket, (struct sockaddr *) &remote, sizeof(remote));
    return iRetVal;
}

int socket_send(int hsocket, char* Rqst, int lenRqst) {
    int iRetVal = -1;
    struct timeval timeout = {0};
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    if (setsockopt(hsocket, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        perror("setsockopt timeout");
        return -1;
    }
    iRetVal = send(hsocket, Rqst, lenRqst, 0);
    return iRetVal;
}

int socket_receive(int hsocket, char* Rsp, int lenRsp) {
    int iRetVal = -1;
    struct timeval timeout = {0};
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    if (setsockopt(hsocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
        perror("setsockopt timeout");
        return -1;
    }
    iRetVal = recv(hsocket, Rsp, lenRsp, 0);
    printf("Received %s bytes\n", Rsp);
    return iRetVal;
}

int main(void) {
    int hsocket = 0, read_size = 0;

    struct sockaddr_in server = {0};
    char send_to_server[1024] = {0};
    char server_reply[1024] = {0};

    hsocket = socket_create();

    if (hsocket == -1) {
        perror("socket_create failed");
        return 1;
    }

    printf("Socket created\n");

    if (socket_connect(hsocket) == -1) {
        perror("connect failed");
        return 1;
    }
    printf("Connect done\n");
    printf("Enter the message...\n");
    fgets(send_to_server, 1024, stdin);

    socket_send(hsocket, send_to_server, strlen(send_to_server));
    read_size = socket_receive(hsocket, server_reply, sizeof(server_reply));
    printf("Received %s bytes\n", server_reply);
    close(hsocket);
    return 0;
}
