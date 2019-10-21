#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
     int n = 0,p = 0;

     scanf("%d\n",&p);
     fprintf(stderr, "%d\n",p);

     while(1){
     scanf("%d\n",&n);
          if(n==-1){
               printf("%d\n",-1);
               break;
          }
          if(n%p){
               printf("%d\n",n);
          }
     }
}