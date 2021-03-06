//Übung http://www.c-howto.de/tutorial/dateiverarbeitung/uebungen/

#include <stdio.h>

void anzahl(char * dateipfad);
void copyFile(char* quelldatei, char* zieldatei);

int main(int argc, char const *argv[]) {
  //anzahl("test.txt");
  copyFile("test.txt", "test2.txt");

  return 0;
}

/* Teil 1: Schreibe eine Funktion, welche eine Datei öffnet und deren Text wie
folgt ändert. Fängt ein Wort mit einem Kleinbuchstaben an, so soll ein
Großbuchstabe daraus gemacht werden.  Beispiel: aus „Die schönen Dinge im Leben
sind umsonst.“ wird „Die Schönen Dinge Im Leben Sind Umsonst.“. Im Parameter
wird lediglich der Dateipfad übergeben.
void toUpperLetter(char *dateipfad){
  char temp;
  FILE *fp;
  fp = fopen(dateipfad, "r");
  if(fp==NULL){
    printf("ERROR: Datei nicht vorhanden\n");
  } else {
    while(temp = fgetc(fp)!=EOF){

    }
  }
}

*/

/* Teil 2: Schreibe eine Funktion, welche die Wörter des Textes in einer Datei
zählt. Der Dateiinhalt bleibt unverändert. Im Parameter wird lediglich der
Dateipfad übergeben. */

void anzahl(char * dateipfad){
  //Dateizeiger
  FILE *fp;
  //Temp für die angeschauten Chars
  char temp;
  //Wird raufgezählt, um zu kontrollieren wie viele Wörter im Text sind
  int zaehler = 0;
  //Datei öffnen
  fp = fopen(dateipfad, "r");

  //Abfangen, falls die Datei nicht gelesen werden konnte
  if(fp==NULL){
    printf("Datei konnte nicht gefunden werden\n");
  } else {
    //Solange nicht das Ende des Files (=EOF) erreicht wird, wird gelesen
    while ((temp = fgetc(fp))!=EOF) {
      printf("gelesen: %c\n", temp);
      //Wir zählen die Leerzeichen, um auf die ANzahl der Wörter zu kommen
      if(temp == ' '){
        zaehler++;
      }
    }
    //Da am Schluss kein Leerzeichen steht, sondern die Datei einfach zu ende ist
    zaehler++;
    printf("Die Datei enthält insgesamt %d Wörter\n", zaehler);
    fclose(fp);

  }
}


/* Teil 3: Schreibe eine Funktion, die eine Datei kopiert. Im Parameter wird
lediglich der Dateipfad der Quell- und Zieldatei übergeben. */
void copyFile(char* quelldatei, char* zieldatei){
  FILE *fp1;
  FILE *fp2;
  fp1 = fopen(quelldatei, "r");
  fp2 = fopen(zieldatei, "w");

  if(fp1==NULL && fp2 == NULL){
    printf("ERROR\n");
  } else {
    char temp;
    while((temp = fgetc(fp1))!=EOF){
      fprintf(fp2, "%c",temp);
    }
  }
}
