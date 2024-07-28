#include "main.h"

int server_start()
{
    int serverSocket = server_socket(-1);
    if (serverSocket < 0)
    {
        perror("Error creating socket");
        return -1;
    }
    server_loop(serverSocket);
    server_stop(serverSocket);
}

int server_socket(int sockfd)
{
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
    {
        perror("Error creating socket");
        return -1;
    }
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("Error binding socket");
        return -1;
    }
    if (listen(serverSocket, 5) < 0)
    {
        perror("Error listening");
        return -1;
    }
    return serverSocket;
}

int server_loop(int serverSocket)
{
    struct sockaddr_in clientAddr;
    socklen_t clientAddrSize = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrSize);
    if (clientSocket < 0)
    {
        perror("Error accepting connection");
        return -1;
    }
    while (1)
    {
        char buffer[BUFFER_SIZE];
        int size = server_recv(clientSocket, buffer, BUFFER_SIZE);
        if (size < 0)
        {
            perror("Error receiving data");
            return -1;
        }
        if (size == 0)
        {
        }
        if (strcmp(buffer, "GET / HTTP/1.1") == 0)
        {
        }
    }
}

int server_stop(int sockfd)
{
    close(sockfd);
    return 0;
}

int server_send(int sockfd, char *buffer){
    return send(sockfd, buffer, strlen(buffer), 0);
    return 0;
}

int server_send_file(int sockfd, char *filename){
    return sendfile(sockfd, filename, NULL, BUFFER_SIZE);
    return 0;

}

int server_recv(int sockfd, char *buffer, int size){
    return recv(sockfd, buffer, size, 0);
    return 0;
}

int server_recv_file(int sockfd, char *filename){
    return recvfile(sockfd, filename, NULL, BUFFER_SIZE);
    return 0;
}