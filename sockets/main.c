#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

// has socket functions
#include <sys/socket.h>

// has sockaddr ds
#include <netinet/in.h>

// configurations - port and buffer size
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(){
    // create the server socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // define server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    listen(server_socket, 5);

    int client_socket;
    char server_message[BUFFER_SIZE];

    printf("waiting for client connections on port %d...\n", SERVER_PORT);

    while(1){
        client_socket = accept(server_socket, NULL, NULL);
        printf("established a client connection...\n");
        char client_message[BUFFER_SIZE];

        read(client_socket, &client_message, sizeof(client_message));

        printf("client message received %s\n", client_message);
        strcpy(server_message, "I am the server responding");
        write(client_socket, &server_message, sizeof(server_message));
        close(client_socket);
    }

    return 0;
}