#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>

#define MEMORYVALUE 24
#define SHMKEY 4444

int main(int argc, char const *argv[]) {

  int shmID; //shared Memory ID
  char *shmPtr; // Shared Memory Pointer
  int i = 0; //counter


//Shared Memory erzeugen
  shmID = shmget(SHMKEY, MEMORYVALUE, IPC_CREAT | 0666);
  //storing the created shm in shmid with
  //key SHMKEY, size MEMORYVALUE, and flag IPC_CREAT or 0666
  if (shmID > -1){
      shmctl(shmID, IPC_RMID, 0);
      } else { perror("shmget went wrong");}



  return 0;
}
