#include <stdio.h>
#include <stdlib.h>

int main() {
     fprintf(stderr, "Sending numbers...\n");
     for (int i = 2; i < 101; i++) {
          printf("%d\n", i);
     }
     printf("%d\n",-1);
}