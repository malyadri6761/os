#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, m, i, j, k;
    printf("Enter the no.of process : ");
    scanf("%d", &n);
    printf("Enter the no.of Resources : ");
    scanf("%d", &m);
    int alloc[n][m], max[n][m], avail[m], need[n][m], ans[n], f[n], ind = 0;
    printf("\nEnter the allocation :");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("\nEnter the MaxNeed : ");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    printf("\nEnter the availability resources : ");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    int y = 0;
    for (i = 0; i < n; i++) {
        f[i] = 0;
    }
    for (k = 0; k < n; k++) { // Use n instead of a constant value
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++) {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }
    int deadlock = 0;
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            deadlock = 1;
            printf("Deadlock is occur");
            break;
        }
    }
    if (deadlock == 0) {
        printf("Safe sequence is: ");
        for (int i = 0; i < n - 1; i++) {
            printf("P%d -> ", ans[i]);
        }
        printf("P%d\n", ans[n - 1]);
    }

    return 0;
}
