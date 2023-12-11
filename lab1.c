#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
void createFile(char *filename){
    // char *filename="Malyadri.txt";
    int file=open(filename,O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
    if(file==-1){
        perror("Unable to open the file.");
        exit(EXIT_FAILURE);
    }
    printf("Successfully created the file. ");
    close(file);
}
void openFile(char *filename){
    // char *filename="Malyadri.txt";
    int file=open(filename,O_CREAT|O_RDWR,S_IRUSR|S_IWUSR);
    if(file==-1){
        perror("Unable to open the file.");
        exit(EXIT_FAILURE);
    }
    printf("Successfully created the file. ");
    close(file);
}
void writeFile(char *filename){
    // const char *filename="Malyadri.txt";
    int file=open(filename,O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
    if(file==-1){
        perror("File opening due to errors in your program.");
        exit(EXIT_FAILURE); 
    }
    char *data=(char *)malloc(1024);
    if(data==NULL){
        perror("The Memory not created.");
        close(file);
        exit(EXIT_FAILURE);

    }
    
    printf("Enter the data : ");
    scanf("%1024s",data);
    ssize_t value=write(file,data,strlen(data));
    if(value==-1){
        perror("Writing data in the file is not working.");
        close(file);
        exit(EXIT_FAILURE);
     
    }
    printf("Sucessfully writing the file. %s",data);
    close(file);
}
void readFile(char *filename){
    // const char *filename="Malyadri.txt";
    int file=open(filename,O_RDONLY);
    if(file==-1){
        printf("Open a file error");
        exit(EXIT_FAILURE);
    }
    char buffer[1024];
    ssize_t file1=read(file,buffer,1023);
    if(file1==-1){
        perror("Reading a file error");
        close(file);
        exit(EXIT_FAILURE);
    }
    printf("%s",buffer);
    close(file);
}
int main(){
    // wirteFile();
    // readFile();
    char *file;
    printf("Enter the name of the file : ");
    scanf("%s",file);
    int choose;
    
    
    printf("1. CREAT\n");
    printf("2. OPEN\n");
    printf("3. READ\n");
    printf("4. WRITE\n");
    printf("Enter the choice.\n");
    scanf("%d",&choose);
    switch(choose){
        case 1:printf("Creating a file.\n");
                createFile(file);
                break;
        case 2: printf("The file content. \n");
                openFile(file);
                break;
        case 3: readFile(file);
                break;
        case 4: writeFile(file);
                break;
        default:printf("Invalid option.");
            break;
    

    }
    

    
}