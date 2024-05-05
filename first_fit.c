#include<stdio.h>
struct process{
    int id,size,allc;
}proces[10];

struct block
{
    int id,size,allc;
}blk[10];

void print(int n){
    printf("block no\t size\t\t process_no\t process_size\t remaining\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t %d\t\t ",blk[i].id,blk[i].size);
        if (blk[i].allc == -1)
        {
            printf("NOT allocated\t 0\t\t %d\n",blk[i].size);
        }
        else
        {

            int temp = blk[i].allc - 1;
            printf("%d\t\t %d\t\t %d\n",blk[i].allc,proces[temp].size,blk[i].size - proces[temp].size);
        }
    }
}

void main(){

    int n,m;
    printf("Enter the no of memory blocks\n");
    scanf("%d",&m);
    for (int i = 0; i < m; i++)
    {
        blk[i].id = i+1;
        printf("Enter the size of the memory block %d\n",blk[i].id);
        scanf("%d",&blk[i].size);
        blk[i].allc = -1;
    }

    printf("Enter the no of process\n");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        proces[i].id = i+1;
        printf("Enter the size of the process %d\n",proces[i].id);
        scanf("%d",&proces[i].size);
        proces[i].allc = -1;
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (blk[j].allc == -1 && proces[i].size <= blk[j].size)
            {
                proces[i].allc =1;
                blk[j].allc = i+1;
                break;
            }
            
        }
        
    }
    
    print(m);

}

//blk[i].allc,(proces[blk[i -1].allc]),(blk[i].size - proces[blk[i -1].allc])