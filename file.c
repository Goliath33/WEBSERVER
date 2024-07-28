#include "main.h"

int sendfile(int sockfd, char *filename, char *buffer, int size){
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return -1;
    }
    int n;
    while ((n = read(fd, buffer, size)) > 0)
    {
        if (write(sockfd, buffer, n) < 0)
        {
            perror("Error writing to socket");
            return -1;
        }
    }
    close(fd);
    return 0;
}

int recvfile(int sockfd, char *filename, char *buffer, int size){
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd < 0)
    {
        perror("Error opening file");
        return -1;
    }
    int n;
    while ((n = read(sockfd, buffer, size)) > 0)
    {
        if (write(fd, buffer, n) < 0)
        {
            perror("Error writing to socket");
            return -1;
        }
    }
    close(fd);
    return 0;
}