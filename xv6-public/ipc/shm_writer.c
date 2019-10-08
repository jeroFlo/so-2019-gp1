#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>


int main(){
     int key = 27; //numero usado para generar el id del bloque de memoria
     int shmid = shmget(key,100,IPC_CREAT | 0666); // shmget hace el bloque de memoria. IPC_CREAT es una bandera
     char *word;

     word = (char *)shmat(shmid,NULL, 0);// el cero es para lectura y escritura y diferente de cero es para solo lectura
     //word ya tiene el tamano de 100 bytes

     //sprintf(word,"Hello world");//lo trata como un arreglo word[0] = H, word[1] = e ...
     word[0] = 'H';
     word[1] ='\0';
     while(word[0] == 'H'){
          sleep(1);
     }
     printf("Sali del ciclo infinito: %s\n",word);
     return 0;
}