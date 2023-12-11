#include<stdio.h>
#include<stdlib.h>
struct MemoryBlock{
    int size;
    int start;
};
void initialize(struct MemoryBlock memory[],int block){
    for(int i=0;i<block;i++){
        memory[i].size=0;
    }
}
void display(struct MemoryBlock memory[],int block){
    for(int i=0;i<block;i++){
        printf(" \nBlock : %d  size : %d",i+1,memory[i].size);
    }
}
void firstFit(struct MemoryBlock memory[],int block,int request){
    for(int i=0;i<block;i++){
        if(memory[i].size>=request && memory[i].size>0){
            memory[i].size=memory[i].size-request;
            printf("\nMemory allocation successfully. Block %d.",i+1);
            return ;
        }
    }
    printf("\nMemory allocation failed");
}
int smallestInternallFragment(struct MemoryBlock memory[], int block, int request) {
    int small = 99999, index = -1;
    for (int i = 0; i < block; i++) {
        if (memory[i].size - request >= 0 && (memory[i].size - request) <= small) {
            // Update index before modifying memory[index].size
            index = i;
            small = (memory[i].size - request);
            
        }
    }
    return index;
}

void bestFit(struct MemoryBlock memory[], int block, int request) {
    int index = smallestInternallFragment(memory, block, request);
    
    if (index != -1) {
        memory[index].size = memory[index].size - request;
        printf("\nMemory allocation successfully. Block %d.", index + 1);
    } else {
        printf("\nMemory allocation failed.");
    }
}
int largerInternallFragment(struct MemoryBlock memory[], int block, int request) {
    int small = 0, index = -1;
    
    for (int i = 0; i < block; i++) {
        if(memory[i].size<request)
            return -1;
    
        if (memory[i].size - request >= 0 && (memory[i].size - request) >= small) {
            // Update index before modifying memory[index].size
            index = i;
            small = (memory[i].size - request);
            
        }
    }
    return index;
}
void worstFit(struct MemoryBlock memory[], int block, int request) {
    int index = largerInternallFragment(memory, block, request);
    if(index==-1)
    {
        printf("\nMemory allocation failed.");
        return ;
    }
    
    memory[index].size = memory[index].size - request;
    
    printf("\nMemory allocation successfully. Block %d.", index + 1);
    
        
    
}

void main(){
    
    
    int request,block,n;

    printf("Enter the no.of Blocks : ");
    scanf("%d",&block);
    
    struct MemoryBlock memory[block];
    initialize(memory,block);

    printf("\nEnter the size of the Blocks : ");
    for(int i=0;i<block;i++){
        printf("\nEnter the starting of the Block %d : ",i+1);
        scanf("%d",&memory[i].start);
        printf("\nEnter the End of the Block %d : ",i+1);
        scanf("%d",&memory[i].size);
        memory[i].size-=memory[i].start;
    }
    
    printf("No of requests : ");
    scanf("%d",&n);
    display(memory,block);

    for(int i=0;i<n;i++){
        printf("\n\nEnter the request : ");
        scanf("%d",&request);
        
        firstFit(memory,block,request);
        display(memory,block);
     
    }
    
        
    
}