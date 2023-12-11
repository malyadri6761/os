#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void fcfs(){
    int n,reading,sum=0,head;
    printf("Enter the no.of Readings : ");
    scanf("%d",&n);

    printf("Enter ther Head Position : ");
    scanf("%d",&head);
    for(int i=0;i<n;i++){
        printf("\nEnter the reading : ");
        scanf("%d",&reading);

        printf("\nMomentum : %d",abs(head-reading));
        sum+=abs(head-reading);
        head=reading;
        
        
    }
    printf("Total Mometum : %d",sum);
}
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-1-i;j++)
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);

}
int indexOfElement(int arr[],int n,int head){
    int c=0;
    for(int i=0;i<n;i++){
        if(head>arr[i])
            c++;
    }
    return c;
}
void scan(){
    int n,reading,sum=0,head,st,end;
    printf("Enter the starting Postion : ");
    scanf("%d",&st);
    printf("Enter the end postion : ");
    scanf("%d",&end);

    printf("Enter the no.of Readings : ");
    scanf("%d",&n);

    printf("Enter ther Head Position : ");
    scanf("%d",&head);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("\n%d-Reading : ",(i+1));
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,n);
    int k=indexOfElement(arr,n,head);
    for(int i=k;i<n;i++){
        printf("\nMomentum %d",abs(head-arr[i]));
        sum+=abs(head-arr[i]);
        head=arr[i];
    }
    printf("\nMometum %d",(end-head));
    sum+=(end-head);
    head=end;
    printf("\nhead reaching end %d",end);
    for(int i=k-1;i>=0;i--){
        printf("\nMomentum %d",abs(head-arr[i]));
        sum+=abs(head-arr[i]);
        head=arr[i];
    }
    printf("\ntotal : %d",sum);

}
void cscan(){
    int n,reading,sum=0,head,st,end;
    printf("Enter the starting Postion : ");
    scanf("%d",&st);
    printf("Enter the end postion : ");
    scanf("%d",&end);

    printf("Enter the no.of Readings : ");
    scanf("%d",&n);

    printf("Enter ther Head Position : ");
    scanf("%d",&head);
    int x=head;
    int arr[n];
    for(int i=0;i<n;i++){
        printf("\n%d-Reading : ",(i+1));
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr,n);
    int k=indexOfElement(arr,n,head);
    for(int i=k;i<n;i++){
        printf("\nMomentum %d",abs(arr[i]));
        sum+=abs(head-arr[i]);
        head=arr[i];
    }
    printf("\nMometum %d",(head));
    sum+=(end-head);
    head=end;
    sum+=(end-st);
    head=st;
    
    printf("\nhead reaching end %d",end);
    printf("\nMomentum %d",(st));
    for(int i=0;i<k;i++){
        printf("\nMomentum %d",abs(arr[i]));
        sum+=abs(head-arr[i]);
        head=arr[i];
    }
    printf("\nMomentum : %d",x);
    sum+=abs(head-x);
    printf("\ntotal : %d",sum);
}
void main(){
    cscan();
}