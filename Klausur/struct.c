#include <stdio.h>

typedef struct{
  int x;
  int y;
  int flächeninhalt;
} rechteck;


int main(int argc, char const *argv[]) {

  rechteck rechteck;
  /* code */
  rechteck.x = 5;
  rechteck.y = 6;
  int i;

 i = rechteck.flächeninhalt = rechteck.x * rechteck.y;

  printf("%d\n",  i);


  return 0;
}
