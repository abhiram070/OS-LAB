#include<stdio.h>
void main(){
    int nor,tot = 0,seek=0;
    float avseek;
    printf("Enter the number of requests : ");
    scanf("%d",&nor);
    int ioq[nor+1];
    printf("Enter the intial head position : ");
    scanf("%d",&ioq[0]);
    printf("Enter the requests\n");
    for (int i = 1; i <= nor; i++)
    {
        printf("request %d : ",i);
        scanf("%d",&ioq[i]);
    }
    printf("Order of request served :\n");
    for (int i = 0; i < nor; i++)
    {
        tot = ioq[i+1] - ioq[i];
        if (tot < 0)
        {
            tot *= -1;
        }
        seek += tot;
        printf("%d-->",ioq[i]);
    }
    printf("%d",ioq[nor]);
    avseek = seek / nor;
    printf("\nTotal seek time : %d\n",seek);
    printf("Average seek time : %.2f\n",avseek);
    
}