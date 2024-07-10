//Sender
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int shmid;
    char *shared_memory;
    key_t key = 5678;
    char message[] = "Hello world";
    shmid = shmget(key,1024, IPC_CREAT | 0666);
    shared_memory = shmat(shmid,NULL,0);
    strcpy(shared_memory,message);
    exit(0);
}


//Reciever
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int shmid;
    char *shared_memory;
    key_t key = 5678;
    shmid = shmget(key,1024, IPC_CREAT | 0666);
    shared_memory = shmat(shmid,NULL,0);
    printf("The message read from shared memeory : %s\n",shared_memory);
    return 0;
}
