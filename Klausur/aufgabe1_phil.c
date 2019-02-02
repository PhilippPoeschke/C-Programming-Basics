#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>



int main()
{

  FILE *file;
  file = fopen("fileIO.conf","r");

  char line[256];
  char *zeichen;
  char *endzahl;
  char a[] = "a";
  char b[] = "b";
  char zahlen[] = "1234567890";

  int eins[256];
  int countereins = 0;
  int i = 0;
  int zwei[256];
  int counterzwei = 0;
  int j = 0;


  while(fgets(line, 256, file) != NULL)
  {
    if(a == (zeichen = strpbrk(a, line)))
    {
      countereins = atoi(endzahl = strpbrk(line, zahlen));
      eins[i] = countereins;
      i++;
      printf("%s = %d\n", zeichen, countereins);
    }
    else if(b == (zeichen = strpbrk(b, line)))
    {
      counterzwei = atoi(endzahl = strpbrk(line, zahlen));
      zwei[j] = counterzwei;
      j++;
      printf("%s = %d\n", zeichen, counterzwei);
    }
  }

printf("A: ");
for (int x = 0; x < i; x++) {
  printf("%d ",eins[x]);
}
printf("\nB: ");
for (int y = 0; y < j; y++) {
  printf("%d ",zwei[y]);
}
printf("\n" );

  return 0;
}
