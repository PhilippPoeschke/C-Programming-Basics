//Implementierung der Aufgabe 3.8 von den Übungsaufgaben

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

int istPrim(unsigned long long p, unsigned long long anfang,unsigned long long ende);
int pipefd[2];
unsigned long long p;

int main(int argc, char *argv[]){

  //Die eingegebene Zahl wird in p gespeichert
  if(argc < 3){
    printf("ERROR: Es wurde keine Zahl zum überprüfen eingegeben\n");
    return EXIT_FAILURE;
  } else {
    int c = 0;
    while((c = getopt(argc, argv, "z:"))  != -1){
      if(c == 'z'){
        p = atoll(optarg);
      }
      if(c == '?'){
        printf("ERROR: Beim einlesen der Zahl ist ein Fehler aufgetreten\n");
        return EXIT_FAILURE;
     }
   }

   //Die bedein Intervalle [anfang,mitte] und [mitte, ende] werden errechnet
   long long anfang = 2;
   long long ende = ceil(sqrt(p));
   long long mitte = ceil(sqrt(p)/2);

   //Erstelle Pipe zur kommunikation zwischen den Prozessen
   if(pipe(pipefd)<0){
     printf("ERROR: Creation of the Pipe failed\n");
     return EXIT_FAILURE;
   }
   pid_t pid;
   if ((pid = fork()) < 0){
     printf("ERROR: Forking the process failed\n");
     return EXIT_FAILURE;
   }
   //Der Child-Process hat die pid 0
   else if(pid == 0){

     //Schließe die Leseseite
     close(pipefd[0]);

     char buf[2];
     //Errechne die Lösung vom Teilintervall und schreibe sie in die Pipe
     int ergebnis1 = istPrim(p,anfang,mitte);
     sprintf(buf, "%d", ergebnis1 );
     write(pipefd[1], buf, strlen(buf));
   }

   //Eltern-Prozess
   else if(pid > 0){
     //Schließe die Schreibseite
     close(pipefd[1]);
     char buf[2];
     //Errechne die andere Lösung vom Teilintervall
     int ergebnis2 = istPrim(p,mitte,ende);

     //Lese die Teillösung vom Kind aus der Pipe
     read(pipefd[0], buf, 2);
     printf("Gelesen %s\n", buf);

     //Setze beide Ergebnisse zusammen
     if(ergebnis2 == 1 && atoi(buf) == 1){
       printf("%llu ist eine Primzahl\n", p);
     } else {
       printf("%llu ist keine Primzahl\n", p);
     }
   }
 }
 return EXIT_SUCCESS;

}

//Es wird geschaut ob im Invertvall [anfang, ende] ein Teiler der Zahl vorhanden ist.
int istPrim(unsigned long long p, unsigned long long anfang,unsigned long long ende){
  do{
    //Für 2 und 3 braucht es einen Sonderfall
    if(p == 2 || p == 3){
      return 1;
    }

    //Ansonsten überprüfe ob x.zahl im intervall teilt
    if(p % anfang == 0){
      return 0;
    }
    if(anfang!=ende){
      //Das Intervall wird stück für stück verkleinert
      anfang++;
    }
    //Bis wir am Ende angekommen sind
  } while(anfang != ende);
  return 1;
}
