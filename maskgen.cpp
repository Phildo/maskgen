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

  if(n_sets  <= 0)      { printf("n_sets must be > 0\n");       usage(); }
  if(n_chars <= 0)      { printf("n_characters must be > 0\n"); usage(); }
  if(n_sets  > n_chars) { printf("n_sets must be <= n_characters\n"); usage(); }
  if(n_chars >= 12)     { printf("too many characters- this will break hashcat, but go for it\n"); }

  char *index = (char *)malloc(n_chars*sizeof(char)); //enumeration of [n_sets]-ary numbers
  char *mask = (char *)malloc(((n_chars*2)+1)*sizeof(char)); //printed mask
  char *accounting = (char *)malloc(n_sets*sizeof(char)); //keep track of what's accounted for, to toss out nonconforming masks
  for(int i = 0; i < n_chars; i++) index[i] = 0; //zero enumeration
  for(int i = 0; i < n_chars; i++) { mask[i*2] = '1'; mask[i*2+1] = '?'; } mask[n_chars*2] = '\0'; //setup default mask
  for(int i = 0; i < n_sets;  i++) accounting[i] = 0; //zero accounting (technically unnecessary- happens every trial)

  int complete = 0;
  int valid = 1;
  int inc_i = 0;
  int carry = 0;
  while(!complete)
  {
    valid = 1; //assume valid
    for(int i = 0; i < n_sets; i++) accounting[i] = 0; //reset account
    for(int i = 0; i < n_chars; i++) accounting[index[i]]++; //increment account
    for(int i = 0; i < n_sets; i++) if(accounting[i] == 0) valid = 0; //invalidate
    if(valid)
    {
      for(int i = 0; i < n_chars; i++) mask[i*2] = '1'+index[i]; //format
      printf("%s\n",mask); //print
    }
    //increment index
    carry = 1;
    inc_i = n_chars-1;
    while(carry && inc_i >= 0)
    {
      index[inc_i]++;
      if(index[inc_i] >= n_sets)
      {
        index[inc_i] = 0;
        inc_i--;
      }
      else carry = 0;
    }
    if(carry) complete = 1;
  }
}

