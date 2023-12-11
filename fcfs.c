// #include<stdio.h>
// #include<unistd.h>
// #include<stdbool.h>
// void swap(int* xp, int* yp)
// {
//     int temp = *xp;
//     *xp = *yp;
//     *yp = temp;
// } 
// void bubbleSort(int pid[],int at[],int bt[], int n)
// {
//     int i, j;
//     bool swapped;
//     for (i = 0; i < n - 1; i++) 
//     {
//         swapped = false;
//         for (j = 0; j < n - i - 1; j++) 
//         {
//             if (bt[j] > bt[j + 1]) 
//             {
//                 swap(&bt[j],&bt[j+1]);
//                 swap(&at[j],&at[j+1]);
//                 swap(&pid[j],&pid[j+1]);
//                 swapped = true;
//             }
//         }
  
//        if (swapped == false)
//             break;
//     }
// }
// // int sum(int bt[],int n)
// // {
// // 	int t=0;
// // 	for(int i=0;i<=n;i++)
// // 	{
// // 		t=t+bt[i];
// // 	}
// // 	return t;
// // }
// int main(){
	
// 	int at[10];
// 	int bt[10];
// 	int ct[10],tat[10],wt[10];
// 	int pid[10];
// 	int i,j,n;
// 	printf("Enter the number of jobs : ");
// 	scanf("%d",&n);
// 	for(i=0;i<n;i++)
// 	{
// 		printf("PID : ");
// 		scanf("%d",&pid[i]);
// 		printf("AT : ");
// 		scanf("%d",&at[i]);
// 		printf("BT : ");
// 		scanf("%d",&bt[i]);
// 	}
		
// 	int temp;
// 	//print_array(pid,at,bt);
// 	bubbleSort(pid,bt,at,n);
	
// 	for(i=0;i<n;i++)
// 	{
// 		if(i==0)
// 		{
// 			ct[i]=bt[i];
// 		}
// 		else
// 		{
// 			if(at[i]>ct[i-1])
// 				ct[i]=at[i]+bt[i];
// 			else
// 				ct[i]=ct[i-1]+bt[i];
// 		}
// 		tat[i]=ct[i]-at[i];
// 		wt[i]=tat[i]-bt[i];
// 	}
	
// 	for(i=0;i<n;i++)
// 	{
// 		printf("%d %d %d %d %d \n",at[i],bt[i],ct[i],tat[i],wt[i]);
// 	}
// 	int s1=0,s2=0;
// 	for(i=0;i<n;i++)
// 	{
// 		s1+=tat[i];
// 		s2+=wt[i];
// 	}
// 	printf("Total Turnaround time : %d\n Total waiting time : %d",s1,s2);
// 	double r1=(float)s1/n;
// 	double r2=(float)s2/n;
// 	printf("\nAverage Turnaround time ; %.2f\n Average waiting time : %.2f",r1,r2);


	
			
	
// 	return 0;
// }

#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
}
void bubbleSort(int arr[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
}
void main(){
	int pid;
	printf("Enter the no.of Jobs : ");
	scanf("%d",&pid);

	int at[pid],bt[pid],ct[pid],tat[pid],wt[pid];
	for(int i=0;i<pid;i++){
		at[i]=0;
		bt[i]=0;
		ct[i]=0;
		tat[i]=0;
		wt[i]=0;
	}
	printf("\nEnter the arrival time and burst time \n");
	for(int i=0;i<pid;i++){
		printf("\nArrival Time  P%d : ",i+1);
		scanf("%d",&at[i]);
		printf("\nBurst    Time P%d : ",i+1);
		scanf("%d",&bt[i]);
	}
	bubbleSort(at,pid);
	
	for(int i=0;i<pid;i++){
		if(i==0)
			ct[i]=bt[i];
		else{
			if(at[i]>ct[i-1])
				ct[i]=at[i]+bt[i];
			else
				ct[i]=ct[i-1]+bt[i];
		}
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
	}
	int t1=0;
	int w1=0;
	for(int i=0;i<pid;i++){
		t1+=tat[i];
		w1+=wt[i];
	}
	printf("ATT : %.4f\n",(float)t1/pid);
	printf("AWT : %.4f",(float)w1/pid);

}