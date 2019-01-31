#include <stdio.h>

int main(int argc, char const *argv[])
{

  int array[5] = {2,7,4,3,1};
  int cash;
  int size = sizeof(array) / sizeof(int);

  int i = 0;
  while (i < size)
  {
    int j= 0;
    while (j < size-1)
    {
      if (array[j] > array[j+1])
      {
        cash = array[j];
        array[j] = array[j+1];
        array[j+1] = cash;
      }
      j++;
    }
    i++;
  }

  int k = 0;
  while (k < size)
  {
    printf("%d\n", array[k] );
    k++;
  }
  printf("\n");

  return 0;
}
