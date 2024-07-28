#include "main.h"

void signal_handler(int signum){
    if(signum == SIGINT){
        printf("Signal received. Exiting...\n");
        exit(0);
    }
}
