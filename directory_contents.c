#include <dirent.h>
#include <stdio.h>

int main(){
    DIR *dir = opendir(".");

    if(dir){

    printf("Contents of current working directory are:\n");
    struct dirent *entry;
    while((entry = readdir(dir)) != NULL){
        printf("%s\n",entry->d_name);
    }
    closedir(dir);
    return 0;
    }
}