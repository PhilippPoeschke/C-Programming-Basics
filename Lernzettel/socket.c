#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 4444

int main(){

  char buffer[256];

  int socketfd;
  struct sockaddr_in adress;
  //erstellen des Sockets
  socketfd = socket(AF_INET, SOCK_STREAM, 0);

  memset(&adress, 0, sizeof(adress));
  adress.sin_family = AF_INET;
  adress.sin_port = htons(PORT);
  //alternativ: getaddrinfo() falls Adresse unbekannt
  //Falls IP unbekannt kann gehostbyname() verwendet werden
  adress.sin_addr.s_addr = inet_addr("127.0.0.1");

  connect(socketfd, (struct sockaddr*)&adress,sizeof(adress));

  //Empfangen/Senden
  recv(socketfd, buffer, strlen(buffer), 0);

  send(socketfd, buffer, strlen(buffer),0);

  close(socketfd);

}
