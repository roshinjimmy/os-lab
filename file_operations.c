#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){

    char *filename = "my_file.txt";
    int fd = open(filename, O_CREAT | O_WRONLY, 0644);

    if(fd == -1){
        perror("file creation failed");
        exit(1);
    }

    const char *data = "Hello,world!";
    ssize_t bytes_written = write(fd,data,strlen(data));
    if(bytes_written > 0){
        printf("Wrote %ld bytes to the file\n",bytes_written);
    }

    close(fd);

    fd = open(filename, O_RDONLY);
    if(fd == -1){
        perror("Error opening the file");
        exit(1);
    }

    char buffer[100];
    ssize_t bytes_read = read(fd,buffer,sizeof(buffer));
    if(bytes_read > 0 ){
        printf("Read %ld bytes from the file:%s\n",bytes_read,buffer); 
    }

    close(fd);

}
