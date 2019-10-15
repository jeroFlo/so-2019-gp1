#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define NUM_FILOS 5
pthread_mutex_t forks[NUM_FILOS]; //ARREGLO DE LOCKS

void actions(){
     sleep(1+rand()%5);
}

void *life(void *ptId){
     long tid;
     tid = (long)ptId;
     srand(time(NULL)+tid);//POR SI CORREN EN PARALELO SE LE SUMA EL id para hacer la semilla diferente

     while(1){
          //pensar
          printf("Estoy pensando...%ld\n",tid);
          actions();
          printf("Me dio hambre %ld\n",tid);
          if(tid%2==0){//pares impares
               pthread_mutex_lock(&forks[tid]);//TENEDOR derecho
               pthread_mutex_lock(&forks[(tid+1)%NUM_FILOS]);//TENEDOR izquierdo
               //comer
               printf("Estoy comiendo...%ld\n",tid);
               actions();
               pthread_mutex_unlock(&forks[tid]);//TENEDOR 1
               pthread_mutex_unlock(&forks[(tid+1)%NUM_FILOS]);//TENEDOR 2
          }else{
               pthread_mutex_lock(&forks[(tid+1)%NUM_FILOS]);//TENEDOR izquierdo
               pthread_mutex_lock(&forks[tid]);//TENEDOR derecho
               //comer
               printf("Estoy comiendo...%ld\n",tid);
               actions();
               pthread_mutex_unlock(&forks[(tid+1)%NUM_FILOS]);//TENEDOR 1
               pthread_mutex_unlock(&forks[tid]);//TENEDOR 2
          }
     }

}
int main(int argc, char *argv[])
{
   pthread_t threads[NUM_FILOS];
   int rc;
   long t;

   for(t=0;t<NUM_FILOS;t++){
     printf("In main: creating thread %ld\n", t);

     rc = pthread_create(&threads[t], NULL, life, (void *)t);
     if (rc){
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
       }
     }
     pthread_exit(NULL);
}