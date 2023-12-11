#include<stdio.h>
#include<stdbool.h>
int que[100];
int front=0;
int rear=0;
int Miss=0;
int Hit=0;
int size=0;
 void insert(int data){
    if(front==rear){
        que[front]=data;
        rear++;
    }
    else{
        que[rear++]=data;
        
    }
    size++;
}
void deque(){
    front++;
    size--;
}
void display(){
    printf("[");
    for(int i=front;i<rear;i++){
        printf("%d,",que[i]);
    }
    printf("]");
}
bool contains(int data){
    for(int i=front;i<rear;i++){
        if(data==que[i]){
            return true;
        }
    }
    return false;
}
void fcfsPageReplace(int frame,int data){
    if(data==-1)
        return ;
    if(frame<=size){
        if(contains(data)){
            Hit++;
        }
        else{
            deque();
            insert(data);
            Miss++;
        }
    }
    else{
        if(contains(data)){
            Hit++;
        }
        else{
            insert(data);
            Miss++;
        }
    }
}
void swapInOrderToLast(int data){
    int index=0;
     for(int i=front;i<=rear;i++){
        if(data==que[i]){
            index=i;
            break;
        }
    }
    for(int i=index+1;i<rear;i++){
            int temp=que[i-1];
            que[i-1]=que[i];
            que[i]=temp;
        
    }
}
void LRUPageReplace(int frame,int data){
    if(data==-1)
        return ;
    if(frame<=size){
        if(contains(data)){
            swapInOrderToLast(data);
            Hit++;
        }
        else{
            deque();
            insert(data);
            Miss++;
        }
    }
    else{
        if(contains(data)){
            swapInOrderToLast(data);
            Hit++;
        }
        else{
            insert(data);
            Miss++;
        }
    }
}
void fcfs(){
    int frame,data=0;
    printf("Enter the no.of Frames : ");
    scanf("%d",&frame);
    do{
        printf("\nEnter the data : (-1 Halt)\n");
        scanf("%d",&data);
        fcfsPageReplace(frame,data);
        display();
        printf("\nHits : %d",Hit);
        printf("\tMiss : %d",Miss);
    }while(data!=-1);
    printf("\nHit Ratio : %.4f",(float)(Hit)/(float)(Hit+Miss));
    printf("\tMiss Ratio : %.4f",(float)(Miss)/(float)(Hit+Miss));
}
void lru(){
    int frame,data=0;
    printf("Enter the no.of Frames : ");
    scanf("%d",&frame);
    do{
        printf("\nEnter the data : (-1 Halt)\n");
        scanf("%d",&data);
        LRUPageReplace(frame,data);
        display();
        printf("\nHits : %d",Hit);
        printf("\tMiss : %d",Miss);
    }while(data!=-1);
    printf("\nHit Ratio : %.4f",(float)(Hit)/(float)(Hit+Miss));
    printf("\tMiss Ratio : %.4f",(float)(Miss)/(float)(Hit+Miss));
}
void main(){
    int choice;
    printf("\n1. FCFS");
    printf("\n2. LRU");
    printf("\nEnter the choice");
    scanf("%d",&choice);
    switch(choice){
        case 1: fcfs(); 
                break;
        case 2: lru();
                break;
        default: printf("Invalid Option ");
        break;
    }
}