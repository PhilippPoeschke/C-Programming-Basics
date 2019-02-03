#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

//Länge von die BÜF festsetzen
#define BUFLEN 64

//Kleines Beispiel zur Bentzung von Pipes in C
int main(){
  //Buffer der zum Beschreiben der Pipe benutzt wird
  char buffer[BUFLEN];
  //Der File-Descriptor für die Pipe
  int pipefd[2];
  //Erstellen der Pipe und Überprüfung auf Fehler
  if(pipe(pipefd)<0){
    printf("ERROR beim erstellen der Pipe\n");
  }
  //Die ID der Prozesse
  pid_t pid;
  if((pid=fork())<0){
    printf("ERROR: Fork fehlgeschlagen\n");
  } else if(pid == 0){
    //Child Prozess
    //Leseseite schließen
    close(pipefd[0]);
    write(pipefd[1], "Hallo!\n", 7);
    printf("Child: Nachricht erfolgreich versendet\n");

  } else if(pid > 0){
    //Parent Prozess

    //Schreibseite schließen
    close(pipefd[1]);
    wait(NULL);
    read(pipefd[0],buffer,BUFLEN);
    printf("Parent: Die Nachricht ist: %s  \n",buffer);
  }
}
