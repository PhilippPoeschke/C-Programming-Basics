#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>

#define SHSIZE 100
int main(){
  int shmID;
  //Referenz zum shared-memory
  char *shmPtr;
  key_t key = 4444; //muss vierstelliger int-wert sein

  //erstellen
  if((shmID = shmget(key, SHSIZE, IPC_CREAT|0666))==-1){
    printf("ERROR\n");
    return -1;
  }
  //attach
  shmPtr = shmat(shmID,0,0);
  if(shmPtr == (char*)-1){
    printf("ERROR\n");
    return -1;
  }

  //-- Mach was mit shared Memory --

  //Detach
  shmdt(shmPtr);
  //Löschen
  shmctl(shmID,IPC_RMID, 0);

}
