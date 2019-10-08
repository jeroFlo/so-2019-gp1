/******************************************************************************
* FILE: hello.c
* DESCRIPTION:
*   A "hello world" Pthreads program.  Demonstrates thread creation and
*   termination.
* AUTHOR: Blaise Barney
* LAST REVISED: 08/09/11
******************************************************************************/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	1000
int saldo = 0;
pthread_mutex_t locksaldo;

void *PrintHello(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);
   pthread_mutex_lock(&locksaldo);//mi lock para proteger mi region critica
   saldo += 100; //esta linea es mi region critica
   pthread_mutex_unlock(&locksaldo);

   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   //pthread_mutex_init(&locksaldo, );
   for(t=0;t<NUM_THREADS;t++){
     printf("In main: creating thread %ld\n", t);

     rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
     if (rc){
       printf("ERROR; return code from pthread_create() is %d\n", rc);
       exit(-1);
       }
     }
     for(t=0;t<NUM_THREADS;t++){ //es para esperar que todos los hilos terminen
          pthread_join(threads[t], NULL);
     }
     printf("Espero 2000 dolares, tengo: %d\n",saldo);
   /* Last thing that main() should do */
   pthread_exit(NULL); // para indicar que este proceso tiene que parar y esperar a que todos los hijos terminen

}