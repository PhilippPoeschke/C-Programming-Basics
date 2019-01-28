#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void spielfeldAusgeben(int *spielfeld);
int anzahlNachbarn(int *spielfeld, int position);
void spielrunde(int *neuesFeld, int *altesFeld);
int vergleicheFeld(int *feld1, int *feld2);
void kopiereFeld(int *neuesFeld, int *altesFeld);
/*Die Dichte der Zellen auf dem Feld von 0 bis 100.
  Dichte 100 bedeutet, dass auf jedem Feld eine Zelle vorkommt
  Dichte 0 bedeutet, dass überhaupt keine Zellen gesetzt werden
*/
int dichte = 0;

//Die Standardgröße des Spielfeldes beträgt 16
int groesse = 16;

/*Argumente die übergeben werden können sind:
  -d Dichte des Spielfeldes
  -g größe des Spielfeldes
*/


int main(int argc, char *argv[]){
  //Die Anzahl der Durchläufe
  int runde = 1;

  //Zumindest die Dichte des Spielfeldes MUSS eingegeben werden
  if(argc <3){
    printf("ERROR: Es wurde keine Dichte gewählt. Schliesse Programm\n");
    return 0;
  } else {
    int c;
    //Durch getopt werden die Kommandozeilenargumente eingelesen
    while((c = getopt(argc, argv, "d:g:"))!=-1){
      switch (c) {
        case 'd':
          dichte = strtol(optarg, NULL, 10);
          break;
        case 'g':
          groesse = strtol(optarg, NULL, 10);
          break;
        case '?':
          printf("ERROR: Falsche Eingabe durch die Kommandozeile. Schliesse Programm");
          return 0;
      }
    }
  }

  //Erzeugen des Spielfeldes
  int *spielfeld = (int*) malloc(groesse*groesse*sizeof(int));
  //Damit wieder eine neue zusallfzahl erzeugt wird muss srand() aufgerufen werden
  srand(time(NULL));

  //Initialisierung des Feldes
  for(int i = 0; i<groesse; i++){
    for(int j = 0; j<groesse; j++){
      //Erzeuge zufallszahl zwischen 0 und 99
      int zufallszahl = rand()%100;
      //Wenn die Zufallszahl kleiner der Dichte ist, dann wird eine lebendige Zelle gesetzt
      if(zufallszahl<dichte){
      *(spielfeld + i*groesse + j) = 1;
      //Ansonsten werden tote Zellen gesetzt
    } else {
      *(spielfeld + i*groesse + j) = 0;
      }
    }
  }

  printf("----Anfangsfeld----\n");
  spielfeldAusgeben(spielfeld);
  printf("\n\n");
  int abbruch = 0;
  int *neuesFeld = (int*) malloc(groesse*groesse*sizeof(int));

  do{
    //Verändere das neue Spielfeld anhand der Regeln des Game of lifes
    spielrunde(neuesFeld,spielfeld);
    //Wenn das Feld gleich ist, wird es der neue Standard für nächste Runde
    if(!vergleicheFeld(spielfeld,neuesFeld)){
      kopiereFeld(spielfeld, neuesFeld);
      //Ansonsten abbruch
    } else {
      abbruch = 1;
    }
    printf("\n");
    //Ausgeben der aktuellen gespielten Runde
    for(int i = 0; i < groesse/2+2; i++){
      printf("+");
    }
    printf("%d.Runde", runde);
    for(int i = 0; i < groesse/2+2; i++){
      printf("+");
    }
    printf("\n");
    spielfeldAusgeben(spielfeld);
    runde++;

  }while(!abbruch);

  free(spielfeld);
  free(neuesFeld);
  return 0;
}

//gibt die Anzahl der Nachbarn einer Zelle zurück
int anzahlNachbarn(int *spielfeld, int position){
  int anzahlNachbarn = 0;

  /*Es werden hier alle Positionen um eine Zelle herum geprüft:
     - Erst ob sie out of bount ist
     - Dann ob dort eine tote oder lebendige Zelle ist
  */
  if(position-1 >= 0){
    if(*(spielfeld + position -1)==1){
      anzahlNachbarn++;
    }
  }
  if(position+1 < groesse*groesse){
    if(*(spielfeld + position +1)==1){
      anzahlNachbarn++;
    }

  }
  if(position-groesse>=0){
    if(*(spielfeld + position - groesse)==1){
      anzahlNachbarn++;
    }

  }
  if(position - groesse -1 >= 0){
    if(*(spielfeld + position - groesse -1)==1){
      anzahlNachbarn++;
    }

  }
  if(position - groesse +1 >=0){
    if(*(spielfeld + position - groesse +1)==1){
      anzahlNachbarn++;
    }

  }
  if(position+groesse < groesse*groesse){
    if(*(spielfeld + position + groesse)==1){
      anzahlNachbarn++;
    }

  }
  if(position+groesse-1 < groesse*groesse){
    if(*(spielfeld + position + groesse - 1)==1){
      anzahlNachbarn++;
    }

  }
  if(position+groesse+1 < groesse*groesse){
    if(*(spielfeld + position + groesse + 1)==1){
      anzahlNachbarn++;
    }

  }
  return anzahlNachbarn;
}

void kopiereFeld(int *neuesFeld, int *altesFeld){
  //Lege eine Kopie des alten Spielfeldes an
  for(int i = 0; i<groesse; i++){
    for(int j = 0; j<groesse; j++){
       neuesFeld[i * groesse + j] = *(altesFeld + i * groesse + j);
     }
  }

}

void spielrunde(int *neuesFeld, int *altesFeld){
  //Lege eine Kopie des alten Spielfeldes an
  for(int i = 0; i<groesse; i++){
    for(int j = 0; j<groesse; j++){
       neuesFeld[i * groesse + j] = *(altesFeld + i * groesse + j);
     }
  }
  int nachbarn;
  //Es wird durch das gesamte array iteriert.
  for(int i = 0; i<groesse; i++){
    for(int j = 0; j<groesse; j++){

      int position = i*groesse + j;
      //Die Anzahl der Nachbarn wird gezählt
      nachbarn = anzahlNachbarn(neuesFeld, position);
      //Es wird überprüft ob eine Zelle gerade lebendig ist
      int lebendig = *(neuesFeld + position);
      //Folgende Cases ergeben sich wenn die Zelle am leben ist.
      if(lebendig){
        //Eine Zelle mit weniger als zwei Nachbarn stirbt
        if(nachbarn<2){
          *(neuesFeld + position) = 0;
          //Eine Zelle mit mehr als drei Nachbarn stirbt
        } else if(nachbarn>3){
          *(neuesFeld + position) = 0;
        } else {
          //Eine Zelle mit zwei oder drei Nachbarn bleibt am Leben
          *(neuesFeld + position) = 1;
        }
        //Falls sie tot ist gibt es nur einen case.
      }else{
        //Bei genau drei Nachbarn wird eine Zelle wiedergeborgen
        if(nachbarn==3){
          *(neuesFeld + position) = 1;
        }
      }
    }
  }
}

void spielfeldAusgeben(int *spielfeld){
  for(int k = 0; k < groesse +1; k++){
    printf("--");
  }
  printf("\n");
  for(int i = 0; i<groesse; i++){
    printf("|");
    for(int j = 0; j<groesse; j++){
      if(*(spielfeld + i*groesse + j)==1){
        printf("O ");
      } else {
        printf("  ");
      }
    }
    printf("|");
    printf("\n");
  }
  for(int l = 0; l < groesse +1; l++){
    printf("--");
  }
  printf("\n");

}

int vergleicheFeld(int *feld1, int *feld2){

  for(int i = 0; i<groesse; i++){
    for(int j = 0; j<groesse; j++){
      if(*(feld1 + i*groesse + j) != *(feld2 + i*groesse + j)){
        return 0;
      }
    }
  }
  return 1;
}
