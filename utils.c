#include "main.h"

void *thread_func(void *arg){
    while(1){
        sleep(1);
    }
    return NULL;
}