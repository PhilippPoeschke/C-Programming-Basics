/* Kleines Beispiel wie man Kommandozeilenparameter einlesen kann
   In disem Beispiel sollen über die Kommandozeile mindestens eine
   Zahl mitgegeben werden, maximal sind drei Params möglich*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*Die mindestanzahl an Params die vom User gesetzt werden sollen +1,
  da der Programmname von argc mitgerechnet wird. */
int minParams = 2;
int a;
int b;
int c;


int main(int argc, char* argv[]){
  if(argc < minParams){
    printf("ERROR: Nicht genügend Parameter eingegeben\n");
    return -1;
  } else {
    //Temp variable um mit getopt zu arbeiten
    int temp;
    //getopt liefert uns den gewünschten wert im string optarg
    //a:b:c sind die verschiedenen params die übergeben werden können
    while((temp = getopt(argc, argv, "a:b:c:"))!=-1){
      switch(temp){
        case 'a':
          a = atoi(optarg);
          break;
        case 'b':
          b = atoi(optarg);
          break;
        case 'c':
          c = atoi(optarg);
          break;
        case '?':
          printf("ERROR\n");
          return -1;
      }
    }
  }
  printf("a: %d, b: %d, c: %d \n",a,b,c );
}
