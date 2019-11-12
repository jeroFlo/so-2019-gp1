#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv){
     if (argc < 2){
          printf("error, follow the format: rm namefile\n");
          return 0;
     }
     char* file = argv[1]; //nombre del archivo a borrar
     char* pwd = getcwd(NULL,0); //directorio actual

     char oldpath[strlen(file)+strlen(pwd)+2];
     sprintf(oldpath,"%s/%s",pwd,file); 
     unlink(oldpath);
}   