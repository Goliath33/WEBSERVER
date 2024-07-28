#include "main.h"

int client_connect()
{
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0)
    {
        perror("Error creating socket");
        return -1;
    }
    struct sockaddr_in clientAddr;
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(PORT);
    clientAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(clientSocket, (struct sockaddr *)&clientAddr, sizeof(clientAddr)) < 0)
    {
        perror("Error connecting to server");
        return -1;
    }
    return clientSocket;
}

int client_send(int sockfd, char *buffer)
{
    int n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
    {
        perror("Error writing to socket");
        return -1;
    }
    return 0;
}

int client_send_file(int sockfd, char *filename)
{
    return sendfile(sockfd, filename, NULL, BUFFER_SIZE);
    return 0;
}

int client_recv(int sockfd, char *buffer, int size)
{
    int n = read(sockfd, buffer, size);
    if (n < 0)
    {
        perror("Error reading from socket");
        return -1;
    }
    return 0;
}

int client_recv_file(int sockfd, char *filename)
{
    return recvfile(sockfd, filename, NULL, BUFFER_SIZE);
    return 0;
}