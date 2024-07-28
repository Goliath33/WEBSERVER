#include "main.h"

int html_send(int sockfd, char *buffer)
{
    return send(sockfd, buffer, strlen(buffer), 0);
    return 0;
}
int html_send_file(int sockfd, char *filename)
{
    return sendfile(sockfd, filename, NULL, BUFFER_SIZE);
    return 0;
}
int html_recv(int sockfd, char *buffer, int size)
{
    return recv(sockfd, buffer, size, 0);
    return 0;
}
int html_recv_file(int sockfd, char *filename)
{
    return recvfile(sockfd, filename, NULL, BUFFER_SIZE);
    return 0;
}