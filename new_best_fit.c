#include<stdio.h>

struct block{
    int bid,size,allc;
}block[10];

struct process{
    int id,size;
}process[10];

struct table
{
    int pid,psize,remaining,bid,bsize;
}table[10];

void print(int nob){
    printf("block_no\tsize\tprocess_no\tprocess_size\tremaining\n");
    for (int i = 0; i < nob; i++)
    {
        printf("%d\t\t%d\t\t",table[i].bid,table[i].bsize);     
        printf("%d\t\t%d\t\t%d\n", table[i].pid, table[i].psize, table[i].remaining);
         
    }
    
}


void main(){
    int nop,nob,k = 0;
    printf("Enter the number of blocks\n");
    scanf("%d",&nob);
    for (int i = 0; i < nob; i++)
    {
        printf("Enter the size of the blocks %d : ",i+1);
        scanf("%d",&block[i].size);
        table[i].bid = i+1;
        table[i].bsize = block[i].size;
        block[i].allc = -1;
    }

    printf("Enter the number of process\n");
    scanf("%d",&nop);
    for (int i = 0; i < nop; i++)
    {
        printf("Enter the size of the process %d : ",i+1);
        scanf("%d",&process[i].size);
        process[i].id = i+1;
    }

    for (int i = 0; i < nop; i++)
    {
        int remaining = 10000;
        int best_index = -1;
        for (int j = 0; j < nob; j++)
        {
            if (process[i].size <= block[j].size && block[j].allc == -1)
            {
                int temp_size = block[j].size - process[i].size;
                if (temp_size < remaining)
                {
                    remaining = temp_size;
                    best_index = j;
                }
            }
            else
            {
                /* code */
            }
            
            
        }
        if (best_index != -1)
        {
            table[k].pid = process[i].id;
            table[k].psize = process[i].size;
            table[k].remaining = remaining;
            block[best_index].allc = 0;
            k++;
        }
        else
        {
            k++;
        }
        
        
    }
    

    print(nob);
}