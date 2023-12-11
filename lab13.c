#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pwd.h>
#include<grp.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>
void printFileInfo(const char *filename){
    struct stat fileStat;
    if(stat(filename,&fileStat)<0){
        perror("Error");
        exit(EXIT_FAILURE);
    }
    printf((S_ISDIR(fileStat.st_mode))?"d":"-");
    printf((fileStat.st_mode & S_IRUSR)?"r":"-");
    printf((fileStat.st_mode & S_IWUSR)?"w":"-");
    printf((fileStat.st_mode & S_IXUSR)?"x":"-");
    printf((fileStat.st_mode & S_IRGRP)?"r":"-");
    printf((fileStat.st_mode & S_IWGRP)?"w":"-");
    printf((fileStat.st_mode & S_IXGRP)?"x":"-");
    printf((fileStat.st_mode & S_IROTH)?"r":"-");
    printf((fileStat.st_mode & S_IWOTH)?"w":"-");
    printf((fileStat.st_mode & S_IXOTH)?"x":"-");

    printf("%2ld",fileStat.st_nlink);

    struct passwd *pw=getpwuid(fileStat.st_uid);
    struct group *gr=getgrgid(fileStat.st_gid);

    printf("%-8s %-8s",pw?pw->pw_name:"unknown",gr?gr->gr_name:"unknown");

    struct tm *timeinfo;
    char timeStar[20];
    timeinfo=localtime(&fileStat.st_mtime);
    strftime(timeStar,sizeof(timeStar),"%b %d %H-%M",timeinfo);
    printf("%s ",timeStar);
    printf("%s\n",filename);

}
int main(){
    DIR *dir;
    struct dirent *entry;
    dir=opendir(".");
    if(dir==NULL){
        perror("Their is error");
        exit(EXIT_FAILURE);

    }
    while((entry=readdir(dir))!=NULL){
        printFileInfo(entry->d_name);
    }
}