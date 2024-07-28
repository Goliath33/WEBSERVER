/**
 * Simple Web Server html + php
 * AUTHOR : GOLIATH
 * VERSION : 1.0.0
 */

#ifndef MAIN_H
#define MAIN_H

// Inclusions de bibliothèques standard
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Inclusions de bibliothèques supplémentaires
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <signal.h>
#include <limits.h>

// Definitions
#define PORT 80
#define WEB_ROOT "web"
#define BUFFER_SIZE 2048
#define MAX_FILE_SIZE 1048576

// Prototypes main
int main(int argc, char *argv[]);

// Prototypes server
int server_start();
int server_socket(int sockfd);
int server_loop(int serverSocket);
int server_stop(int sockfd);
int server_send(int sockfd, char *buffer);
int server_send_file(int sockfd, char *filename);
int server_recv(int sockfd, char *buffer, int size);
int server_recv_file(int sockfd, char *filename);

// Prototypes client
int client_connect();
int client_send(int sockfd, char *buffer);
int client_send_file(int sockfd, char *filename);
int client_recv(int sockfd, char *buffer, int size);
int client_recv_file(int sockfd, char *filename);

// Prototypes web
int web_send(int sockfd, char *buffer);
int web_send_file(int sockfd, char *filename);
int web_recv(int sockfd, char *buffer, int size);
int web_recv_file(int sockfd, char *filename);

// Prototypes misc
int is_dir(char *filename);
int is_file(char *filename);

// Prototypes signal
void signal_handler(int signum);

// Prototypes utils
void *thread_func(void *arg);

// Prototypes utils file
int sendfile(int sockfd, char *filename, char *buffer, int size);
int recvfile(int sockfd, char *filename, char *buffer, int size);

// Prototypes html
int html_send(int sockfd, char *buffer);
int html_send_file(int sockfd, char *filename);
int html_recv(int sockfd, char *buffer, int size);
int html_recv_file(int sockfd, char *filename);

// Prototypes php
int php_send(int sockfd, char *buffer);
int php_send_file(int sockfd, char *filename);
int php_recv(int sockfd, char *buffer, int size);
int php_recv_file(int sockfd, char *filename);


#endif // MAIN_H