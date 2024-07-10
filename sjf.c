#include<stdio.h>

struct process
{
    int pid,at,bt,ct,tat,wt;
};

void print(int nop, struct process *sjf){
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < nop; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",sjf[i].pid,sjf[i].at,sjf[i].bt,sjf[i].ct,sjf[i].tat,sjf[i].wt);
    }  
}

void swap(struct process *a, struct process *b){
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

void sort_at(struct process *sjf,int nop){
    for (int i = 0; i < nop; i++)
    {
        for (int j = 0; j < nop - i - 1; j++)
        {
            if (sjf[j].at > sjf[j + 1].at)
            {
                swap(&sjf[j], &sjf[j+1]);
            }
        }  
    }
}

void sort_bt(struct process *sjf,int nop){
    int min = 0,k = 1, btime = 0;
    for (int i = 0; i < nop; i++)
    {
        btime += sjf[i].bt;
        min = sjf[k].bt;
        for (int j = k; j < nop; j++)
        {
            if (btime >= sjf[j].at && sjf[j].bt < min)
            {
                swap(&sjf[j], &sjf[j-1]);
            }   
        }
        k++;
    }
    
}

void sort_pid(struct process *sjf,int pid){
    for (int i = 0; i < pid - 1; i++)
    {
        for (int j = 0; j < pid - i -1; j++)
        {
            if (sjf[j].pid > sjf[j + 1].pid)
            {
                swap(&sjf[j], &sjf[j+1]);
            }
        }
    }
}

void main(){
    int nop;
    float avwt,avtat;
    printf("Enter the number of process : ");
    scanf("%d",&nop);
    struct process sjf[nop];
    printf("Enter process details\n");
    for (int i = 0; i < nop; i++)
    {
        printf("process %d\n", i+1);
        sjf[i].pid = i+1;
        printf("Enter arrival time : ");
        scanf("%d",&sjf[i].at);
        printf("Enter burst time : ");
        scanf("%d",&sjf[i].bt);
    }

    sort_at(sjf,nop);
    sort_bt(sjf,nop);
    int current_time = 0;
    sjf[0].ct = 0;

    for (int i = 0; i < nop; i++)
    {
        if (sjf[i].at > current_time)
        {
            current_time = sjf[i].at;
        }
        sjf[i].ct = current_time + sjf[i].bt;
        current_time = sjf[i].ct;
        sjf[i].tat = sjf[i].ct - sjf[i].at;
        sjf[i].wt = sjf[i].tat - sjf[i].bt;

        avtat += sjf[i].tat;
        avwt += sjf[i].wt;
    }

    
    avwt /= nop;
    avtat /= nop;

    sort_pid(sjf,nop);

    print(nop,sjf);
    printf("Average waiting time = %f\nAverage turn around time = %f\n",avwt,avtat);
}