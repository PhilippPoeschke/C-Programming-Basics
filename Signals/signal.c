/* Signale sind dazu da Kommunikation zwischen einem Parent und einem Child herzustellen.
   Dafür muss ein signalhandler eingerichtet werden bei dem spezifiziert wird, wie auf
   die Signale reagiert werden soll. Mögliche signale, die vom User verändert werden dürfen
   sind SIGUSR1 und SIGUSR2. Mit kill(prozssID, signalhandler) wird ein signal verschickt.
  Wait wir beim parent benutzt, sodass gewartet wird bis ein signal ankommt.

*/

#include <signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int receivedSignal = 0;

//Signalhandler beschreibt wie auf signale reagiert werden soll.
void signalhandler(int signum){
  if(signum == SIGUSR1){
     printf("Received SIGUSR1\n");
  }
  if(signum == SIGUSR2){
    printf("Received SIGUSR2\n");
    receivedSignal = 1;
  }

}

int main(void){
  pid_t pid;
  //signal(SIGNALNAME, FUNKTION) spezifiziert welche Funktion bei welchem Signal aufgerufen wird.
  signal(SIGUSR1, signalhandler);
  signal(SIGUSR2, signalhandler);

  //Erstelle zwei Prozesse
  if((pid = fork())==-1){
    printf("ERROR: FORKING FAILED\n" );
    return EXIT_FAILURE;

    //Child
  } else if(pid == 0){

      //Signal an Parent schicken.
      kill(getppid(), SIGUSR1);
      while(!receivedSignal);

    //Parent
  } else if(pid >0){
      //Warte bis ein Signal ankommt
      kill(pid, SIGUSR2);
      wait(NULL);
    }
    return 1;
}
