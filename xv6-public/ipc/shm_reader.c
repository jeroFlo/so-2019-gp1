#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>

int main(){
     int key = 27; //numero usado para generar el id del bloque de memoria
     int shmid = shmget(key,100,IPC_CREAT); // shmget hace el bloque de memoria. IPC_CREAT es una bandera
     char *word;

     word = (char *)shmat(shmid,NULL, 0);
     printf("Lo que hay en la memoria es: %s\n",word);
     word[0] = '*';

     return 0;
}