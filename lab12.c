#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
    char buffer[1024];
    size_t s,d;
    char sourceFile[30],destFile[30];
    printf("Enter source file : ");
    scanf("%s",sourceFile);
    printf("Enter Destination file :");
    scanf("%s",destFile);
    int source=open(sourceFile,O_RDONLY,S_IRUSR|S_IWUSR);
    int dest=open(destFile,O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);

    if(source==-1||dest==-1){
        perror("open a file error. copy of file Invalid");
        close(source);
        close(dest);
        exit(EXIT_FAILURE);
    }
    
    s=read(source,buffer,sizeof(buffer));
    d=write(dest,buffer,s);
    if(d==-1){
        perror("Invalid");
        close(source);
        close(dest);
        exit(EXIT_FAILURE);
    }
    printf("Successfully copied");    
}