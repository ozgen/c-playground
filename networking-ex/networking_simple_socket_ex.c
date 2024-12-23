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

int bind_socket(int hsocket) {
    int iRetVal = -1;
    int client_port = 12345;
    printf("Binding socket...\n");

    struct sockaddr_in remote = {0};
    remote.sin_family = AF_INET;
    remote.sin_addr.s_addr = htonl(INADDR_ANY);
    remote.sin_port = htons(client_port);
    iRetVal = bind(hsocket, (struct sockaddr *) &remote, sizeof(remote));
    return iRetVal;
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


int main(void) {
    int socket_desc = 0, sock = 0, client_len = 0;
    struct sockaddr_in client;
    char client_message[1024];
    char message[1024];

    socket_desc = socket_create();
    if (socket_desc == -1) {
        perror("socket_create failed");
        return 1;
    }
    printf("Socket created\n");

    if (bind_socket(socket_desc) == -1) {
        perror("bind failed");
        return 1;
    }
    printf("Bind done\n");

    listen(socket_desc, 3); // max 3 clients can connect

    while (1) {
        printf("Waiting for incoming connections...\n");
        client_len = sizeof(struct sockaddr_in);
        sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t *) &client_len);
        if (sock == -1) {
            perror("accept failed");
            return 1;
        }

        printf("Connection accepted\n");

        // initialize the messages buffers
        memset(client_message, 0, 1024);
        memset(message, 0, 1024);

        if (recv(sock, client_message, 1024, 0) < 0) {
            perror("recv failed");
            return 1;
        }

        printf("client reply: %s\n", client_message);

        strcpy(message, "Hi there!!!");

        if (send(sock, message, strlen(message), 0) < 0) {
            perror("send failed");
            return 1;
        }
        close(sock);
        sleep(1);
    }
    return 0;
}
