#include "stdlib.h"
#include "stdio.h"
#include "math.h"

void usage()
{
  printf("usage: maskgen n_sets n_characters\n");
  exit(1);
}

int main(int argc, char **argv)
{
  int n_sets = 0;
  int n_chars = 0;

  if(argc != 3) usage();

  n_sets = atoi(argv[1]);
  n_chars = atoi(argv[2]);

  printf("%d sets, %d chars\n",n_sets,n_chars);

  if(n_sets  <= 0) { printf("n_sets must be > 0\n");       usage(); }
  if(n_chars <= 0) { printf("n_characters must be > 0\n"); usage(); }
}

