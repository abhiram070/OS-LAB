#include<stdio.h>

struct process{
    int id,size,allc;
}process[10],block[10];

void print(int nob){
    printf("block_no\tblock_size\tprocess_id\tprocess_size\tremaining\n");
    for (int i = 0; i < nob; i++)
    {
        printf("%d\t\t%d\t\t",block[i].id,block[i].size);
        if (block[i].allc == -1)
        {
            printf("NOT ALLOCATED\n");
        }
        else
        {
            int temp = block[i].allc - 1;
            printf("%d\t\t%d\t\t%d\n",process[temp].id,process[temp].size,(block[i].size - process[temp].size));
        }
    }
}

void main(){
    int nop,nob;
    printf("Enter the number of blocks\n");
    scanf("%d",&nob);
    for (int i = 0; i < nob; i++)
    {
        printf("Enter the size of the blocks %d : ",i+1);
        scanf("%d",&block[i].size);
        block[i].id = i+1;
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
        int remaining = -1;
        int max_index = -1;
        for (int j = 0; j < nob; j++)
        {
            if (block[j].allc == -1 && process[i].size <= block[j].size)
            {
                int temp = block[j].size - process[i].size;
                if (temp > remaining)
                {
                    remaining = temp;
                    max_index = j;
                }
            }
            
        }
        if (max_index != -1)
        {
            block[max_index].allc = i+1;
        }
        
    }
    print(nob);    

}