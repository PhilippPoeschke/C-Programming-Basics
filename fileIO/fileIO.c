#include <stdio.h>
#include <stdlib.h>

int main(void) {
   FILE *quelle, *fehler;
   int c;
   char datei[20];
   long pos = 0;

   printf("Welche Datei wollen Sie oeffnen : ");
   scanf("%s",datei);
   fflush(stdin);

   if( (quelle=fopen(datei,"a+")) == NULL) {
      if((fehler=fopen("fehler.log","a+")) != NULL) {
         fprintf(fehler,"Konnte %s nicht oeffnen\n",datei);
         fprintf(stderr,"Konnte %s nicht oeffnen\n",datei);
         return EXIT_FAILURE;
      }
      fprintf(stderr,"Konnte %s nicht oeffnen\n",datei);
      return EXIT_FAILURE;
   }

   /* Das Zeichen '*' soll das Ende unserer Eingabe markieren. */
   printf("Eingabe machen und mit '*' beenden\n");
   while( (c=getc(stdin)) != '*')
      putc(c,quelle);

   /* Sie setzen den Zeiger quelle an den Anfang der Datei. */
   fseek(quelle, 0L, SEEK_SET);

   /* Sie geben die ganze Datei auf dem Bildschirm aus. */
   printf("\nAusgabe der kompletten Datei : \n");
   while( (c=getc(quelle)) != EOF)
      putc(c,stdout);

   /* Zur Demonstration gehen Sie von der aktuellen Position
    * 10 Zeichen zurück und geben die letzten 10 Zeichen aus. */
   printf("\nDie letzten 10 Zeichen : ");
   fseek(quelle, -13L, SEEK_CUR);
   while( (c=getc(quelle)) != EOF)
      putc(c,stdout);

   /* Sie legen selbst fest, wie viele Zeichen wir vom Start aus
    * einrücken wollen. */
   printf("\nAnzahl der Stellen einruecken (vom Anfang): ");
   scanf("%ld",&pos);
   fflush(stdin);

   fseek(quelle, 0L, SEEK_SET);
   fseek(quelle, pos,SEEK_CUR);

   while( (c=getc(quelle)) != EOF)
      putc(c,stdout);
   return EXIT_SUCCESS;
}
