#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char** argv){
     if (argc<4){
          printf("sintax error\n");
     }
     char * filename = argv[1]; //nombre del archivo a leer
     char * newWord = argv[2];
     char * oldWord = argv[3];
     char * fileTemp = "temp201";
     char word[100];
     char c;
     unsigned char i=0; 

     int fd = open(filename, O_RDONLY);
     int fdTemp = open(fileTemp, O_WRONLY|O_CREAT,0666);

     while (read(fd,&c,1)) {
          if(c!=' '){
               word[i++] = c;
          }else{
               word[i] = '\0';
               i=0;
               if(!(strcmp(word, oldWord))){
                    write(fdTemp,newWord, strlen(newWord));
                    write(fdTemp," ",1);
                    continue;
               }
               write(fdTemp, word, strlen(word));
               write(fdTemp," ",1);   
          }
     }
     word[i] = '\0';
     if(!(strcmp(word, oldWord))){
          write(fdTemp,newWord, strlen(newWord));
     }else {
          write(fdTemp, word, strlen(word)); 
     }
     write(fdTemp," ",1); 

     close(fd);
     close(fdTemp);
     unlink(filename);
     link(fileTemp, filename);
     unlink(fileTemp);
     return 0;
}