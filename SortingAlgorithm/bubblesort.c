//Implementation of bubble sort in c
//Used the wikipedia pseudocode as reference

#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

void bubblesort(int* array, int len);
void swap(int* array, int src, int dest);
void printArray(int* array, int len);

int main(void){
  int array[7] = {6,3,65,2,4,7,1};
  printf("Before: ");
  printArray(array, 7);
  bubblesort(array, 7);
  printf("After: ");
  printArray(array, 7);
  return 0;
}


void bubblesort(int* array, int len){
  bool swapped;
  //Repeat swapping until nothing was swapped -> sorted
  do{
    swapped = false;
    int i = 1;
    //Iterate through the whole array
    while(i<len+1){
      //Check if there is something to swap
      if(array[i-1]>array[i]){
        //Swap and set swap to true -> another iteration needed
        swap(array, i, (i-1));
        swapped = true;
      }
      i++;
    }
  }while(swapped);
}

void swap(int* array, int src, int dest){
  int temp;
  temp = array[src];
  array[src] = array[dest];
  array[dest] = temp;
}

void printArray(int* array, int len){
  int i = 0;
  printf("{");
  while(i<len){
    printf("%d ", array[i]);
    i++;
  }
  printf("}\n");

}
