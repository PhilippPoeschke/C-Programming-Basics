// Aufgabe 4)
// Gegeben sind eine IP-Adresse "12. ... . ." sowie ein Parameter int port für einen TCP-Port des Servers
// (bzw. hostname "12. ... . :<port>" ?).
// Schreiben Sie eine Methode, die Verbindung zu dem Server aufbaut und einen
// Socket (int) zurückgibt bei Erfolg, sonst -1.
// Schreiben Sie eine zweite Methode (mit Parameter int sock),
// die einen (\0-terminierten ?) String der Länge BUF = 256 vom Server empfängt,
// diesen sofort wieder zurückschickt und die Verbindung schließt.
//
// 2 Punkte - einen für Verbindungsaufbau (erste Methode)
// und einen für den String richtig hin und her gesendet (2. Methode)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444


int getconnection(char* get_inet_addr, int get_port);
void recvsend(int sock);

int main(int argc, char const *argv[]) {

  int socket;
  char *inet = "127.0.0.1";

  socket = getconnection(inet, PORT);
  recvsend(socket);


  return 0;
}


int getconnection(char* get_inet_addr, int get_port){

  int retsocket;
  struct sockaddr_in serverAddr;

  retsocket = socket(PF_INET, SOCK_STREAM, 0);
  if(retsocket==-1){return -1;}

  memset(&serverAddr, '\0', sizeof(serverAddr));
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(get_port);
  serverAddr.sin_addr.s_addr = inet_addr(get_inet_addr);

  connect(retsocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

  return retsocket;
}

void recvsend(int sock){

  int n;
  char buffer[1024];

  n = recv(sock, buffer, 1024, 0);
  printf("[+]Data Recv: %s\n", buffer);
  strcat(buffer, " Darling");
  printf("[+]Data Recv: %s\n", buffer);
  n = send(sock, buffer, 1024, 0);

}
