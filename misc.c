#include "main.h"


int is_dir(char *filename){
    DIR *dir = opendir(filename);
    if (dir == NULL)
    {
        return 0;
    }
    else
    {
        closedir(dir);
        return 1;
    }
}

int is_file(char *filename) {
    struct stat st;
    return stat(filename, &st) == 0 && S_ISREG(st.st_mode);
    return 0;
}
