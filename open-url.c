#include <stdio.h>
#include "open-url.h"

void open_url(char *url){
  char launch[255];
  sprintf(launch, "cmd /c start %s", url);
  system(launch);
  sprintf(launch, "x-www-browser '%s' &", url);
  system(launch);
  sprintf(launch, "open '%s'", url);
  system(launch);
}


int main(){
  open_url("www.bing.com");
}
