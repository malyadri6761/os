// #include<stdio.h>
// #include<stdbool.h>
// int main()
// {
// 	int at[10];
// 	int bt[10];
// 	int ct[10],tat[10],wt[10];
// 	int pid[10],f[10];
// 	int i,j,n,st=0,tot=0;
// 	float avgwt=0,avgta=0;
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
// 	while(true)
// 	{
// 		int c=n,min=999;
// 		if(tot==n)
// 			break;
// 		for(int i=0;i<n;i++)
// 		{
// 			if((at[i]<=st) && (f[i]==0)&& (bt[i]<min))
// 			{
// 				min=bt[i];
// 				c=i;
// 			}
// 		}
// 		if(c==n)
// 			st++;
// 		else
// 		{
// 			ct[c]=st+bt[c];
// 			st+=bt[c];
// 			tat[c]=ct[c]-at[c];
// 			wt[c]=tat[c]-bt[c];
// 			f[c]=1;
// 			tot++;
// 		}
// 	}
// 	printf("==================================\n");
// 	printf("|  Shortest Job First            |\n");
// 	printf("==================================\n");
// 	printf("|  PID | AT | BT | CT | TAT | WT |\n");
// 	printf("==================================\n");
// 	for(i=0;i<n;i++){
// 	printf("|  %d  | %d | %d | %d | %d  | %d |\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
// 	}
// 	printf("===================================\n");
// 	for(i=0;i<n;i++)
// 	{
// 		avgwt+=wt[i];
// 		avgta+=tat[i];
// 	}
// 	printf("Avg TAT : %.4f",(float)avgwt/n);
// 	printf("Avg WT : %.4f",(float)avgta/n);
// 	return 0;
// }
		
#include<stdio.h>
#include<stdbool.h>

int main() {
    int n;
    printf("Enter the number of Jobs: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], f[n];
    int t1 = 0, w1 = 0;

    for(int i = 0; i < n; i++) {
        printf("AT BT: ");
        scanf("%d %d", &at[i], &bt[i]);
        f[i] = 0;
    }

    int tot = 0, st = 0, c = 0;

    // while (1) {
    //     int min = 999;
    //     if (tot == n)
    //         break;

    //     for (int i = 0; i < n; i++) {
    //         // Fix: Use bt[i] < min instead of bt[i] > min
    //         if (at[i] <= st && f[i] == 0 && bt[i] < min) {
    //             c = i;
    //             min = bt[i];
    //         }
    //     }

    //     if (c == n)
    //         st++;
    //     else {
    //         ct[c] = st + bt[c];
    //         st += bt[c];
    //         tat[c] = ct[c] - at[c];
    //         t1 += tat[c];
    //         wt[c] = tat[c] - bt[c];  // Fix: Use bt[c] instead of at[c]
    //         w1 += wt[c];
    //         f[c] = 1;  // Fix: Mark the job as completed
    //         tot++;
    //     }
    // }
	while(1){
		int min=999;
		if(tot==n)
			break;
		for(int i=0;i<n;i++){
			if( f[i]==0 && bt[i]<min && at[i]<=st){
				min=bt[i];
				c=i;
			}
		}
		if(c==n)
			st++;
		else{
			ct[c]=st+bt[c];
			st+=bt[c];
			tat[c]=ct[c]-at[c];
			t1+=tat[c];
			wt[c]=tat[c]-bt[c];
			w1+=wt[c];
			f[c]=1;
			tot++;
		}
	}

    printf("\nATRT: %.4f", (float)t1 / n);
    printf("\nAWT : %.4f", (float)w1 / n);

    return 0;
}
