#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAXIMOMSG 40000

/**
 * programa cliente
 */
int main(int argc, char *argv[])
{
    char buffer[MAXIMOMSG + 1]; // para incluir o terminador nulo
    int tamanho, meusocket;
    struct sockaddr_in destinatario;

    char * requisicao = "GET / HTTP/1.1\r\nHost:10.3.160.7\r\n\r\n\0";
    meusocket = socket(AF_INET, SOCK_STREAM, 0);

    destinatario.sin_family = AF_INET;

    // ip do servidor - 127.0.0.1 se estiver rodando na sua mesma maquina
    // destinatario.sin_addr.s_addr = inet_addr("127.0.0.1");
    destinatario.sin_addr.s_addr = inet_addr("10.3.160.7");

    // porta do servidor
    // destinatario.sin_port = htons(2343);
    destinatario.sin_port = htons(80);

    // zerando o resto da estrutura
    memset(&(destinatario.sin_zero), '\0', sizeof(destinatario.sin_zero));

    connect(meusocket, (struct sockaddr *)&destinatario, sizeof(struct sockaddr));


    send(meusocket, requisicao, strlen(requisicao), 0);

    tamanho = recv(meusocket, buffer, MAXIMOMSG, 0);

    // terminando a mensagem
    buffer[tamanho] = '\0';

    printf("%s\n", buffer);

    // termina o socket
    close(meusocket);

    return 0;
}

// Instrucoes para compilacao
// gcc cliente.c -o cliente

