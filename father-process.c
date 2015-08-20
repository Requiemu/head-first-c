#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

void error(char *msg){
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(1);
}

int main(int argc,char *argv[]){
  int i;
  FILE *log = fopen("log.txt","w");
  //if (dup2(fileno(log),1)==-1) error("can't redirect Standard Output");
  for(i=1;i<argc;i++){
    pid_t pid = fork();
    if(pid == -1) error("can't fork process");
    if(pid == 0){
      //if (dup2(fileno(log),1)==-1) error("can't redirect Standard Output");
      if(execl("./son-process","./son-process", argv[i], NULL)==-1){
        puts("execute failed");
      }
      fclose(log);
    }
    int pid_status;
    if(waitpid(pid, &pid_status, 0)==-1){ 
      printf("%s%d\n","error occured while waiting for process:", pid);
    }
    else{
    //execl("sleep", "sleep", 5, NULL);
    //if (dup2(fileno(log),1)==-1) error("can't redirect Standard Output");
    fprintf(stdout,"%s, %d\n","I'm from the father process", pid);
    }
    //fclose(log);
  }
} 
