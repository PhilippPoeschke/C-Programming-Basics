#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char* datei = "fileIO.conf";


int main(void){
  FILE *fp;
  if((fp = fopen(datei, "r"))==NULL){
    printf("ERROR: FILE NOT FOUND\n" );
    return -1;
  }

  char buf[256];

  int countA = 0;
  int countB = 0;

  int *a;
  a = (int*) malloc(sizeof(int));
  int *b;
  b = (int*) malloc(sizeof(int));

  char c[20];
  char d[20];
  int temp;
  while(fgets(buf, 256,fp)!=NULL){
    printf("%s",buf );

    if(strstr(buf,"a")){
      if(sscanf(buf, "%s %s %d ", c, d, &temp)!=1){
        a[countA] = temp;
        countA++;
        realloc(a, sizeof(int)*countA);
        printf("Es wurde %d eingelesen\n",temp );
        continue;
      }
    }
    if(strstr(buf,"b")){

      if(sscanf(buf, "%s %s %d", &temp)!=1){
        b[countB] = temp;
        countB++;
        realloc(b, sizeof(int)*countB);
        printf("Es wurde %d eingelesen\n",temp );
        continue;
      }
    }
  }
  printf("Array A: ");
  for(int i = 0; i < countA; i++){
    printf("%d ",a[i]);
  }
  printf("\nArray B: ");
  for(int i = 0; i < countB; i++){
    printf("%d ",b[i]);
  }


  fclose(fp);
  return 0;
}
