#include<stdio.h>

int main(){
    int nor,capacity,pageFound,fault = 0,hit =0,temp = 0;
    printf("Enter the number of reference strings : ");
    scanf("%d",&nor);
    int pages[nor];
    printf("Enter the refrence strings\n");
    for (int i = 0; i < nor; i++)
    {
        printf("reference string %d : ",i+1);
        scanf("%d",&pages[i]);
    }
    printf("Enter frame capacity : ");
    scanf("%d",&capacity);
    int frames[capacity];
    for (int i = 0; i < capacity; i++)
    {
        frames[i] = -1;
    }
    printf("The frames \n");
    for (int i = 0; i < nor; i++)
    {
        pageFound = 0;
        for (int j = 0; j < capacity; j++)
        {
            if (pages[i] == frames[j])
            {
                pageFound = 1;
                hit++;
                break;
            }
        }
        if (pageFound == 0)
        {
            fault++;
            for (int j = 0; j < capacity; j++)
            {
                if (frames[j] == -1)
                {
                    frames[j] = pages[i];
                    pageFound = 1;
                    break;
                }
            }
            if (pageFound == 0)
            {
                frames[temp] = pages[i];
                temp = (temp + 1) % capacity;
            }
        }
        printf("RS %d | ",pages[i]);
        for (int j = 0; j < capacity; j++)
        {
            if (frames[j] == -1)
            {
                printf("_ ");
            }
            else
            {
                printf("%d ",frames[j]);
            }
        }   
        printf("\n");
    }
    
    printf("Number of page faults : %d\n",fault);
    printf("Number of page hits : %d\n",hit);
    printf("page faults ratio : %d\n",(fault*100)/nor);
    printf("page hit ratio : %d\n",(hit*100)/nor);


    return 0;
}