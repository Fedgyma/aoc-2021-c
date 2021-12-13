#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{
  FILE *fp;
  char *lineptr = NULL;
  size_t n = 0;
  ssize_t n_char_read;
  fp = fopen(PUZZLE_INPUT, "r");
     
  if (fp == NULL) 
    {
      perror("Error could not open" PUZZLE_INPUT);
      exit(EXIT_FAILURE);
    }

  
  fclose(fp);
  return EXIT_SUCCESS;
}
