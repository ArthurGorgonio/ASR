#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "functions.h"

#define MAXIMOMSG 9999

char * getIp(char * host)
{
  struct hostent *host_info;
  host_info = gethostbyname(host);
  if (host_info == NULL)
    return NULL;
  return inet_ntoa(*((struct in_addr *) host_info -> h_addr));
}

char * getPage(char * ss)
{
  char buffer[MAXIMOMSG + 1]; // para incluir o terminador nulo
  int tamanho, meusocket;
  struct sockaddr_in destinatario;

  char aux_s [600] = "POST /sensors/scan/Token HTTP/1.1\r\nHost: "; // mais o aux 2

  char * aux_m = ss;
  strcat(aux_m, "\r\nContent-type: application/json\r\nContent-length: 65\r\n\r\n");
  char * aux_e = "{\"timestamp\":535653656,\"devices\":\"5C:3E:2A:10:43:23\"}\r\n";

  strcat(aux_s, aux_m); // requisicao = start + ip
  strcat(aux_s, aux_e); // requisicao = requisicao + end

  printf(aux_s);
  meusocket = socket(AF_INET, SOCK_STREAM, 0);

  destinatario.sin_family = AF_INET;

  // ip do servidor - 127.0.0.1 se estiver rodando na sua mesma maquina
  destinatario.sin_addr.s_addr = inet_addr(ss);

  // porta do servidor
  destinatario.sin_port = htons(5000);

  printf(ss);
  //printf((int *)destinatario.sin_port);
  
  // zerando o resto da estrutura
  memset(&(destinatario.sin_zero), '\0', sizeof(destinatario.sin_zero));

  connect(meusocket, (struct sockaddr *)&destinatario, sizeof(struct sockaddr));


  send(meusocket, aux_s, strlen(aux_s), 0);

  tamanho = recv(meusocket, buffer, MAXIMOMSG, 0);

  // terminando a mensagem
  buffer[tamanho] = '\0';

  printf("%s\n", buffer);

  // termina o socket
  close(meusocket);

  return 0;
}
