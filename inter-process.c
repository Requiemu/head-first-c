//#include "open-url.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void open_url(char *url){
  char launch[255];
  sprintf(launch, "cmd /c start %s", url);
  system(launch);
  sprintf(launch, "x-www-browser '%s' &", url);
  system(launch);
  sprintf(launch, "open '%s'", url);
  system(launch);
}

void error(char *msg){
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(1);
}

int main(){
  int fd[2];
  if(pipe(fd)==-1) error("can't creat pipe");
  pid_t pid = fork();
  if(pid==-1) error("can't fork process");
  if(pid==0){
    close(fd[0]);
    dup2(fd[1], 1);
    printf("%s","www.bing.com");
/*    printf("%s", "www.baidu.com");*/
  }else{
    close(fd[1]);
    dup2(fd[0],0);
    char site[20];
    fgets(site,20,stdin);
    open_url(site);
/*    fgets(site,20,stdin);*/
/*    open_url(site);*/
    return 1;
  }
}
