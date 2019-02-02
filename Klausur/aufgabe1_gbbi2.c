#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFLEN 256
char* datei = "fileIO.conf";


int main(void){
  FILE *fp;
  if((fp = fopen(datei, "r"))==NULL){
    printf("ERROR: FILE NOT FOUND\n" );
    return -1;
  }

  char buf[BUFLEN];
  int flagA = 0;
  int flagB = 0;
  int *a = (int*)malloc(sizeof(int));
  int *b = (int*)malloc(sizeof(int));
  int i = 0;
  int j = 0;

  char *ptr;
  while(fgets(buf, BUFLEN, fp)!=NULL){
    ptr = strtok(buf," ");
    while(ptr!=NULL){
      printf("ABSCHNITT GEFUNDEN: %s\n", ptr);
      if(strcmp(ptr, "a")==0){
        flagA = 1;
      } else
      if(strcmp(ptr, "b")==0){
        flagB = 1;
      } else

      if(strcmp(ptr, " ")==0){

      } else
      if (strcmp(ptr, "=")==0) {

      } else {
        if(flagA){
          i++;
          flagA = 0;
          realloc(a, i*sizeof(int));
          a[i-1] = atoi(ptr);
          printf("A: %s\n", ptr);
        }
        if(flagB){
          j++;
          flagB = 0;
          realloc(b, j*sizeof(int));
          b[j-1] = atoi(ptr);
          printf("B: %s\n", ptr);

        }

      }


      ptr = strtok(NULL, " ");
    }
  }
  printf("Array A: ");
  for(int x = 0; x < i; x++){
    printf("%d ",a[x]);
  }
  printf("\nArray B: ");
  for(int y = 0; y < j; y++){
    printf("%d ",b[y]);
  }



}
