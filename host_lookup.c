#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <netdb.h>

/*
Description of data base entry for a single host.
struct hostent
{
  char *h_name;			// Official name of host.
  char **h_aliases;		// Alias list.
  int h_addrtype;		// Host address type.
  int h_length;			// Length of address.
  char **h_addr_list;	// List of addresses from name server.
#if defined __USE_MISC || defined __USE_GNU
# define	h_addr	h_addr_list[0] // Address, for backward compatibility.
#endif
};

*/

int main(int argc, const char *argv[])
{
    struct hostent *host_info;
    struct in_addr *address;

    if (argc < 2)
    {
        printf("Uso: %s <hostname>\n",argv[0]);
        exit(1);
    }

    // obtendo o IP do host passado, consulta ao servidor DNS
    host_info = gethostbyname(argv[1]);

    if (host_info == NULL)
    {
        printf("Não pude encontrar %s\n",argv[1]);
    }
    else
    {
        address = (struct in_addr *) (host_info->h_addr);
        printf("%s tem endereço %s\n",argv[1], inet_ntoa(*address));
    }

    return 0;
}
