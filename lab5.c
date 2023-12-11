#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<pthread.h>
int full=0;
int x=0;
int mutex=1;
int empty=10;
void producer(){
    --mutex;
    ++full;
    --empty;
    ++x;
    printf("\n Producer producing item : %d",x);
    ++mutex;
}
void consumer(){
    --mutex;
    --full;
    ++empty;
    printf("\n Consumer consuming item : %d",x);
    --x;
    ++mutex;
}
void *threadFunction(void *arg){
    int ch;
    do{
        printf("\n+===========================+");
        printf("\n| PRODUCER CONSUMER PROBLEM |");
        printf("\n+===========================+");
        printf("\n| 1. PRODUCER               |");
        printf("\n+===========================+");
        printf("\n| 2. CONSUMER               |");
        printf("\n+===========================+");
        printf("\n|  3. EXIT                  |");
        printf("\n+===========================+");
        printf("\n\nEnter the choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 : if((empty!=0) && mutex==1)
                        producer();
                    else
                        printf("Buffer is Full");
                    break;
            case 2: if(mutex==1 && (full!=0))
                        consumer();
                    else
                        printf("Buffer is empty");
                    break;
            case 3:
                    printf("\n+===========================+");
                    printf("\n| Thank you !!!             |");
                    printf("\n+===========================+");
                     exit(0);
                    break;
            default:
                    printf("Invalid Option ");
                    break;
        }
    }while(true);
}
void main(){
    pthread_t tid;
    pthread_create(&tid,NULL,threadFunction,NULL);
    pthread_join(tid,NULL);
    return 0;
}