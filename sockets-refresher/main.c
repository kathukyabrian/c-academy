#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080
#define BUFFER_SIZE 1024
int main()
{
    printf("system|creating server socket on port: %d\n", PORT);

    printf("system|about to create the server socket, creating file descriptor\n");
    int fd;
    fd = socket(AF_INET, SOCK_STREAM, 0);
    printf("system|file descriptor returned with id: %d\n", fd);
    if (fd == -1)
    {
        perror("system|error|an error was encountered while creating server socket\n");
        exit(EXIT_FAILURE);
    }

    printf("system|about to create socket address, this will contain port and address\n");
    /**
     * struct sockaddr_in {
           sa_family_t     sin_family;
           in_port_t       sin_port;
           struct in_addr  sin_addr;
       };
     */
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;
    printf("system|created server address, about to bind on port: %d\n", PORT);

    int bind_status = bind(fd, (struct sockaddr *)&server_address, sizeof(server_address));
    if (bind_status < 0)
    {
        perror("system|error|an error was encountered while binding\n");
        exit(EXIT_FAILURE);
    }

    int listen_status = listen(fd, 5);
    if (listen_status == -1)
    {
        perror("system|error|encountered an error while listening on connections\n");
        exit(EXIT_FAILURE);
    }
    printf("system|bind complete|listening on port: %d|waiting on client connections....\n", PORT);

    while (1)
    {
        struct sockaddr_in client_address;

        int client_socket = accept(fd, NULL, NULL);
        if (client_socket < 0)
        {
            perror("system|error|encountered an error while accepting client connections\n");
            exit(EXIT_FAILURE);
        }

        printf("system|got client connection from file descriptor %d\n", client_socket);

        char client_buffer[BUFFER_SIZE];
        read(client_socket, &client_buffer, sizeof(client_buffer));

        printf("client message = %s\n", client_buffer);

        char *response = "hello from me, I am writing on the network";

        write(client_socket, response, strlen(response));

        printf("written back on the socket: %s....\n", response);

        close(client_socket);

        close(fd);

    }
    return 0;
}