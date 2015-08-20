#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void diediedie(int sig){
  puts("Goodbye cruel world...\n");
  exit(1);
}
int catch_signal(int sig, void (*handler)(int)){
  struct sigaction action;
  action.sa_handler = handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags=0;
}

int main(){
  int i = 0;
  struct sigaction action;
  action.sa_handler = diediedie;
  sigemptyset(&action.sa_mask);
  action.sa_flags=0;
  sigaction(SIGINT, &action, NULL);
  //raise(SIGINT);
}
