#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    char *filename = "new_file.txt";
    int fd = open(filename, O_CREAT | O_WRONLY, 0644);

    if(fd == -1){
        perror("file creation failed");
        exit(1);
    }

    printf("file %s created successfully\n",filename);
    close(fd);
    return 0;
}