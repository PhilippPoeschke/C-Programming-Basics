#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct linkedlist {
  int val;
  struct linkedlist *next;
} linkedlist_t;

void addElement(linkedlist_t* list, int val){
  linkedlist_t * current = list;
  while(current -> next != NULL){
    current = current -> next;
  }
  current -> next = malloc(sizeof(linkedlist_t));
  current -> next -> val = val;
  current -> next -> next = NULL;
}

void printElements(linkedlist_t* list){
  linkedlist_t* current = list;
  while(current != NULL){
    printf("%d\n", current -> val );
    current = current -> next;
  }
}

void freeList(linkedlist_t* list){
  linkedlist_t* tmp;
  while(list!=NULL){
    tmp = list;
    list = list -> next;
    free(tmp);
  }
}

int countList(linkedlist_t* list) {
  int count = 0;
  linkedlist_t* current = list;
  while (current != NULL) {
    count++;
    current = current -> next;
  }
  return count;
}

void copyListToArray(linkedlist_t* list, int* array, int length){
  int i = 0;
  linkedlist_t * current = list;
  while(i<length){
    array[i] = current -> val;
    current = current -> next;
    i++;
  }
}
