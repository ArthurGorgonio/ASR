#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <time.h>

#define PORTANUMERO 2343

int main(int argc, char* argv[])
{
  char buffer[100];

  // recebe o tamanho da estrutura sockarrd_in
  int sockettamanho;

  // descritor do socket da escuta
  int meusocket;

  // descritor do socket da conexao
  int socketconexao;

  // informações do cliente
  struct sockaddr_in endereco_cliente;

  // informações do servidor
  struct sockaddr_in endereco_servidor;

  // armazena a hora
  time_t ticks;

  // tamanho da estrutura de endereco do socket usado
  sockettamanho = sizeof(struct sockaddr_in);

  // AF_INET - Comunicacao_IP
  // SOCK_STREAM - Tráfego confiável (TCP)
  // SOCK_DGRAM - Datagrama não confiável (UDP)
  meusocket = socket(AF_INET, SOCK_STREAM, 0);
  endereco_servidor.sin_family = AF_INET;

  // define qualquer ip da interface de rede
  endereco_servidor.sin_addr.s_addr = INADDR_ANY;

  // define a porta de escuta do servidor
  endereco_servidor.sin_port = htons(PORTANUMERO);

  // zera o resto da estrutura
  memset(&(endereco_servidor.sin_zero), '\0', sizeof(endereco_servidor.sin_zero));

  //liga o socket ao enderecamento do servidor
  bind (meusocket, (struct sockaddr *)&endereco_servidor, sizeof(struct sockaddr));

  //habilita a escuta de conexoes
  listen(meusocket,  1);

  printf("Servidor escutando conexoes TCP na porta: %d\n", PORTANUMERO);

  while(1)
  {
    // espera por uma conexao
    socketconexao = accept(meusocket, (struct sockaddr *)&endereco_cliente, &sockettamanho);
    printf("Uma conexão do endereço %s foi estabelecida - informando a hora certa\n", inet_ntoa(endereco_cliente.sin_addr));
    ticks = time(NULL);
    snprintf(buffer, sizeof(buffer), "%.24s ", ctime(&ticks));
    send(socketconexao, buffer, strlen(buffer), 0);
    close(socketconexao);
  }
  close(meusocket);
  return 0;
}
