#include <stdio.h>
#include "functions.h"

////////////////////////////////////////////////////
// This code is provided by araujobd & gorgonioac //
//      based on code develop by ~joaoborges      //
////////////////////////////////////////////////////

int main(int argc, char ** argv)
{
  char * ss = getIp(argv[1]);
  if (ss == NULL)
  {
    printf("FAILED\n");
    return 1;
  }
  char * kk = getPage(ss);
  printf(kk);
  return 0;
}