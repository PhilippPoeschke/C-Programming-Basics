/* Aufgabe 3)
Gegeben sind ein Filedescriptor fd* und ein (\0- terminierter) String char* buffer.
 Schreiben Sie eine Methode die eine pipe anlegt und buffer in die pipe schreibt und
 die Anzahl der gesendeten Zeichen zurückgibt.

1 Punkt (überprüft u.A., ob die richtige Anzahl Zeichen über die Pipe gesendet wurde)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

int anz_in_pipe(int *file,char *buffer);

int main(int argc, char const *argv[]) {

  int fd[2];
  char* buffer = "Hallo";
  int anz;

  anz = anz_in_pipe(fd, buffer);
  printf("Es wurden %d Zeichen über die Pipe gesendet\n",anz);

  return 0;
}


int anz_in_pipe(int *fd,char *buffer){

    int pp = pipe(fd);

    if(pp == -1){perror("Creating pipe did not work");return 0;}

  //  close(fd[0]);
    write(fd[1], buffer, strlen(buffer));

    return strlen(buffer);


}
