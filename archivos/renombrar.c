#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char** argv){
      if (argc < 3){
          printf("error, follow the format: rn nameOldfile nameNewFile\n");
          return 0;
     }
     char* oldfile = argv[1]; 
     char* newfile = argv[2]; 

     char* pwd = getcwd(NULL,0); //directorio actual

     char oldpath[strlen(oldfile)+strlen(pwd)+2];
     char newpath[strlen(newfile)+strlen(pwd)+2];

     sprintf(oldpath,"%s/%s",pwd,oldfile); 
     sprintf(newpath, "%s/%s",pwd,newfile);

     link(oldpath,newpath);
     unlink(oldpath);
}