//el pathname va a ser relativo

#include <unistd.h> //para el pwd
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char** argv){
     if (argc < 3){
          printf("error, follow the format: cp fileSource fileDestination\n");
          return 0;
     }
     char* file1 = argv[1];
     char* file2 = argv[2];
     char* pwd = getcwd(NULL,0);

     char path1[strlen(file1)+strlen(pwd)+2];
     path1[strlen(path1)-1]='\0';

     char path2[strlen(file2)+strlen(pwd)+2];
     path2[strlen(path2)-1]='\0';

     sprintf(path1,"%s/%s",pwd,file1);
     sprintf(path2, "%s/%s", pwd,file2);

     int fd1 = open(path1, O_RDONLY); //SOURCE
     int fd2 = open(path2, O_WRONLY|O_CREAT,0666); //DESTINATION

     char buffer[100];
     int b;
     while((b = read(fd1,buffer,100))!= 0 ){
          write(fd2, buffer, b);
     }
     close(fd1);
     close(fd2);

     return 0;
}

