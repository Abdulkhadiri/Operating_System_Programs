#include <stdio.h>
int main()
{
    int pr_id[15];
    int bt[15];
    int n,i,j;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
 
    printf("Enter process id of all the processes: \n");
    for(i=0;i<n;i++)
    {
    	printf("For-%d--: ",i);
        scanf("%d",&pr_id[i]);
    }
 
    printf("Enter burst time of all the processes: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
 
    int wt[n];
    wt[0]=0;
    for(i=1; i<n; i++)
    {
        wt[i]= bt[i-1]+ wt[i-1];
    }
 
    printf("Process ID     Burst Time     Waiting Time     TurnAround Time\n");
    float twt=0.0;
    float tat= 0.0;
    for(i=0; i<n; i++)
    {
        printf("%d\t\t", pr_id[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);
        printf("%d\t\t", bt[i]+wt[i]);
        printf("\n");
        twt += wt[i];
        tat += (wt[i]+bt[i]);
    }
    float att,awt;
    awt = twt/n;
    att = tat/n;
    printf("Avg. waiting time= %f\n",awt);
    printf("Avg. turnaround time= %f",att);
}
