/* Aufgabe 3)
Gegeben sind ein Filedescriptor fd* und ein (\0- terminierter) String char* buffer.
 Schreiben Sie eine Methode die eine pipe anlegt und buffer in die pipe schreibt und
 die Anzahl der gesendeten Zeichen zurückgibt.

1 Punkt (überprüft u.A., ob die richtige Anzahl Zeichen über die Pipe gesendet wurde)
*/

int pipeAnlegen(int *fd, char* buffer);

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

int main(void){
  int fd[2];
  char* buffer = "Wer des list is a depp ;)";
  int count = pipeAnlegen(fd,buffer);
  printf("Es wurden %d Zeichen in die Pipe geschrieben\n",count);
}

int pipeAnlegen(int *fd, char* buffer){
  if((pipe(fd))==-1){
    return 0;
  } else {
    write(fd[1],buffer, strlen(buffer));
  }
  return strlen(buffer);
}
