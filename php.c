#include "main.h"

int php_send(int sockfd, char *buffer)
{
    return send(sockfd, buffer, strlen(buffer), 0);
    return 0;
}
int php_send_file(int sockfd, char *filename)
{
    return sendfile(sockfd, filename, NULL, BUFFER_SIZE);
    return 0;
}
int php_recv(int sockfd, char *buffer, int size)
{
    int n = read(sockfd, buffer, size);
    if (n < 0)
    {
        perror("Error reading from socket");
        return -1;
    }
    return 0;
}

int php_recv_file(int sockfd, char *filename)
{
    return recvfile(sockfd, filename, NULL, BUFFER_SIZE);
    return 0;
}