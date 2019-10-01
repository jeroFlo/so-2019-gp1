#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

unsigned forever = 1;
void signalHandler(int signal){
     printf("Received signal\n");
     forever = 0;
}
int main(){
     int pid;
     signal(10,signalHandler);
     pid = fork();
     if(pid==0){
          //soy el hijo

          printf("Soy el hijo\n");
          //codigo que quiero que haga el hijo
          while(forever);
          printf("Ya sali\n");
     }else{
          printf("Soy tu padre y mi hijo es: %d\n",pid);
          sleep(5);
          kill(pid,10);
          //codigo del padre
          for(;;);
     }
     return 0;
}