#include <stdio.h>
#include <string.h>
#include <unistd.h>

char* datei = "fileIO.conf";

int main(void){
  FILE *fp;
  if((fp = fopen(datei, "r"))==NULL){
    return -1;
  }

  char buf[256];
  int *a;
  int *b;

  while((fgets(buf, strlen(buf),fp))!=NULL){
    if(strstr(buf,"a")){
      if(sscanf(buf, "%d", a)!=1){
        continue;
      } else {
          printf("%ls\n", a);
      }
    }
    if(strstr(buf,"b")){
      if(sscanf(buf, "%d", b)!=1){
        continue;
      }else {
          printf("%ls\n", b);
      }
    }

  }
  fclose(fp);
}
