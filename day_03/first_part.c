#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(void)
{

  FILE *fp;
  char *lineptr = NULL;
  size_t n = 0;
  ssize_t n_char_read;

  uint16_t b_gamma_rate = 0;
  uint16_t b_epsilon_rate;
  unsigned short gamma_rate[12] = {0};
  unsigned short data_count = 0;

  fp = fopen(PUZZLE_INPUT, "r");
  if (fp == NULL)
  {
    perror("Error could not open" PUZZLE_INPUT);
    exit(EXIT_FAILURE);
  }


  while ((n_char_read = getline(&lineptr, &n, fp)) != -1)
  {
    data_count++;
    for (int c = 0;c < 12; c++)
    {
        if (lineptr[c] == '1')
          gamma_rate[c]++;
    }
  }

  for (int b = 0;b < 12; b++) {
      b_gamma_rate = b_gamma_rate * 2 + (*(gamma_rate+b) > (data_count / 2));
  }

  b_epsilon_rate = 0x0fff & ~b_gamma_rate;

  printf("%u\n", b_gamma_rate * b_epsilon_rate);

  fclose(fp);
  if (lineptr)
  {
    free(lineptr);
  }


  return EXIT_SUCCESS;
}
