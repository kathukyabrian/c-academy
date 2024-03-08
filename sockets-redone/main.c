#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PORT 11417
#define BUFFER_SIZE 1024

int main(){
    // step 1: create
    int server_socket;
    // domain, type, protocol
    // domain = AF_INET - IPV4
    // type = SOCK_STREAM - TCP
    // protocol = 0(TCP)
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1){
        perror("An error was encountered while creating server socket");
        exit(EXIT_FAILURE);
    }

    // step 2: bind
    // create socket address - set addr, family and port
    struct sockaddr_in server_address;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_family = AF_INET;
    // convert port to network byte order - htons
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_zero[8] = '\0';

    int status = bind(server_socket, (struct sockaddr*) &server_address, sizeof(struct sockaddr));
    if(status < 0){
        perror("An error was encountered while binding to address");
        exit(EXIT_FAILURE);
    }

    // step 3: listen
    status = listen(server_socket, 5);
    if(status < 0){
        perror("Error: couldn't listen for connections");
        exit(EXIT_FAILURE);
    }

    while(1){
        int client_socket = accept(server_socket, NULL, NULL);
        printf("Established a client connection....\n");

        if(client_socket < 0){
            perror("Could not establish connection with client");
            exit(EXIT_FAILURE);
        }

        char client_message[BUFFER_SIZE];
        read(client_socket, &client_message, sizeof(client_message));

        printf("message from client %s and size is %d", client_message, sizeof(client_message));
    }
}