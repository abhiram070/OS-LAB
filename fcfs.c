#include<stdio.h>

struct process
{
    int pid,at,bt,ct,tat,wt;
};

void print(int nop, struct process *prcs){
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < nop; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",prcs[i].pid,prcs[i].at,prcs[i].bt,prcs[i].ct,prcs[i].tat,prcs[i].wt);
    }  
}

void swap(struct process *a, struct process *b){
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

void sort_pid(struct process *prcs,int pid){
    for (int i = 0; i < pid - 1; i++)
    {
        for (int j = 0; j < pid - i -1; j++)
        {
            if (prcs[j].pid > prcs[j + 1].pid)
            {
                swap(&prcs[j], &prcs[j+1]);
            }
        }
    }
}

void main(){
    int nop;
    float avwt,avtat;
    printf("Enter the number of process : ");
    scanf("%d",&nop);
    struct process prcs[nop];
    printf("Enter process details\n");
    for (int i = 0; i < nop; i++)
    {
        printf("process %d\n", i+1);
        prcs[i].pid = i+1;
        printf("Enter arrival time : ");
        scanf("%d",&prcs[i].at);
        printf("Enter burst time : ");
        scanf("%d",&prcs[i].bt);
    }
    sort_pid(prcs,nop);
    int current_time = 0;
    prcs[0].ct = 0;

    for (int i = 0; i < nop; i++)
    {
        if (prcs[i].at > current_time)
        {
            current_time = prcs[i].at;
        }
        prcs[i].ct = current_time + prcs[i].bt;
        current_time = prcs[i].ct;
        prcs[i].tat = prcs[i].ct - prcs[i].at;
        prcs[i].wt = prcs[i].tat - prcs[i].bt;

        avtat += prcs[i].tat;
        avwt += prcs[i].wt;
    }
    
    avwt /= nop;
    avtat /= nop;



    print(nop,prcs);
    printf("Average waiting time = %f\nAverage turn around time = %f\n",avwt,avtat);
}